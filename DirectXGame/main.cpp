#include "Audio.h"
#include "AxisIndicator.h"
#include "DirectXCommon.h"
#include "GameScene.h"
#include "ImGuiManager.h"
#include "PrimitiveDrawer.h"
#include "TextureManager.h"
#include "WinApp.h"
#include "TitleScene.h"
#include "EndScene.h"
#include "DescriptionScene.h"
#include "HowToScene.h"
#include "GameOverScene.h"

//シーン(型)
enum class Scene {
	kUnknown = 0,
	kTitle,
	kDescription,
	kHowTo,
	kGame,
	kGameOver,
	kClear
};

//現在シーン(型)
Scene scene = Scene::kUnknown;

GameScene* gameScene = nullptr;
TitleScene* titleScene = nullptr;
DescriptionScene* descriptionScene = nullptr;
HowToScene* howToScene = nullptr;
EndScene* endScene = nullptr;
GameOverScene* gameOverScene = nullptr;

//シーン切り替え
void ChangeScene() 
{
	switch (scene) 
	{
	case Scene::kTitle:
		if (titleScene->IsFinished()) {
			//シーン変更
			scene = Scene::kDescription;
			//旧シーンの解放
			delete titleScene;
			titleScene = nullptr;
			//新シーンの生成と初期化
			descriptionScene = new DescriptionScene;
			descriptionScene->Initialize();
		}
		break;

	case Scene::kDescription:
		if (descriptionScene->IsFinished()) {
			//シーン変更
			scene = Scene::kHowTo;
			//旧シーンの解放
			delete descriptionScene;
			descriptionScene = nullptr;
			//新シーンの生成と初期化
			howToScene = new HowToScene;
			howToScene->Initialize();
		}
		break;

	case Scene::kHowTo:
		if (howToScene->IsFinished()) {
			//シーン変更
			scene = Scene::kGame;
			//旧シーンの解放
			delete howToScene;
			howToScene = nullptr;
			//新シーンの生成と初期化
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;

	case Scene::kGame:
		if (gameScene->IsFinished()) {
			// ゲームオーバーへ
			delete gameScene;
			gameScene = nullptr;
			gameOverScene = new GameOverScene();
			gameOverScene->Initialize();
			scene = Scene::kGameOver;
		}
		else if (gameScene->IsCleared()) {
			// ゲームクリアへ
			delete gameScene;
			gameScene = nullptr;
			endScene = new EndScene();
			endScene->Initialize();
			scene = Scene::kClear;
		}
		break;

	case Scene::kGameOver:
		if (gameOverScene->IsFinished()) {
			//旧シーン変更
			scene = Scene::kGame;
			//旧シーンの解放
			delete gameOverScene;
			gameOverScene = nullptr;
			//新シーンの生成と初期化
			gameScene = new GameScene;
			gameScene->Initialize();
		}
		break;

	case Scene::kClear:
		if (endScene->IsFinished()) {
			//旧シーン変更
			scene = Scene::kTitle;
			//旧シーンの解放
			delete endScene;
			endScene = nullptr;
			//新シーンの生成と初期化
			titleScene = new TitleScene;
			titleScene->Initialize();
		}
		break;
	}
}
//シーンの更新
void UpdateScene() 
{
	switch (scene)
	{
	case Scene::kTitle:
		titleScene->Update();
		break;

	case Scene::kDescription:
		descriptionScene->Update();
		break;

	case Scene::kHowTo:
		howToScene->Update();
		break;

	case Scene::kGame:
		gameScene->Update();
		break;

	case Scene::kClear:
		endScene->Update();
		break;

	case Scene::kGameOver:
		gameOverScene->Update();
		break;
	}
}
//シーンの描画
void DrawScene() 
{
	switch (scene)
	{
	case Scene::kTitle:
		titleScene->Draw();
		break;

	case Scene::kDescription:
		descriptionScene->Draw();
		break;

	case Scene::kHowTo:
		howToScene->Draw();
		break;

	case Scene::kGame:
		gameScene->Draw();
		break;

	case Scene::kClear:
		endScene->Draw();
		break;

	case Scene::kGameOver:
		gameOverScene->Draw();
		break;
	}
}
// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	WinApp* win = nullptr;
	DirectXCommon* dxCommon = nullptr;
	// 汎用機能
	Input* input = nullptr;
	Audio* audio = nullptr;
	AxisIndicator* axisIndicator = nullptr;
	PrimitiveDrawer* primitiveDrawer = nullptr;

	// ゲームウィンドウの作成
	win = WinApp::GetInstance();
	win->CreateGameWindow(L"2048_落下の領域");

	// DirectX初期化処理
	dxCommon = DirectXCommon::GetInstance();
	dxCommon->Initialize(win);

#pragma region 汎用機能初期化
	// ImGuiの初期化
	ImGuiManager* imguiManager = ImGuiManager::GetInstance();
	imguiManager->Initialize(win, dxCommon);

	// 入力の初期化
	input = Input::GetInstance();
	input->Initialize();

	// オーディオの初期化
	audio = Audio::GetInstance();
	audio->Initialize();

	// テクスチャマネージャの初期化
	TextureManager::GetInstance()->Initialize(dxCommon->GetDevice());
	TextureManager::Load("white1x1.png");

	// スプライト静的初期化
	Sprite::StaticInitialize(dxCommon->GetDevice(), WinApp::kWindowWidth, WinApp::kWindowHeight);

	// 3Dモデル静的初期化
	Model::StaticInitialize();

	// 軸方向表示初期化
	axisIndicator = AxisIndicator::GetInstance();
	axisIndicator->Initialize();

	primitiveDrawer = PrimitiveDrawer::GetInstance();
	primitiveDrawer->Initialize();
#pragma endregion

	//最初のシーンの初期化
	scene = Scene::kTitle;
	// ゲームシーンの初期化
	titleScene = new TitleScene;
	titleScene->Initialize();

	// メインループ
	while (true) {
		// メッセージ処理
		if (win->ProcessMessage()) {
			break;
		}

		// ImGui受付開始
		imguiManager->Begin();
		// 入力関連の毎フレーム処理
		input->Update();
		//シーンの切り替え
		ChangeScene();
		//現在シーン更新
		UpdateScene();
		// 軸表示の更新
		axisIndicator->Update();
		// ImGui受付終了
		imguiManager->End();

		// 描画開始
		dxCommon->PreDraw();
		//現在シーンの描画
		DrawScene();
		// 軸表示の描画
		axisIndicator->Draw();
		// プリミティブ描画のリセット
		primitiveDrawer->Reset();
		// ImGui描画
		imguiManager->Draw();
		// 描画終了
		dxCommon->PostDraw();
	}

	// 各種解放
	delete titleScene;
	delete descriptionScene;
	delete howToScene;
	delete gameScene;
	delete endScene;

	// 3Dモデル解放
	Model::StaticInitialize();
	audio->Finalize();
	
	// ImGui解放
	imguiManager->Finalize();

	// ゲームウィンドウの破棄
	win->TerminateGameWindow();

	return 0;
}