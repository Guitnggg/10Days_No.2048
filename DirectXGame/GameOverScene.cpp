#include "GameOverScene.h"

GameOverScene::GameOverScene(){}

GameOverScene::~GameOverScene() { delete gameOvermodel_; }

void GameOverScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	gameOvermodel_ = Model::CreateFromOBJ("gameOver", true);
	gameOverWorldTransform_.Initialize();
	viewProjection_.Initialize();

	//  3Dモデルの生成
	modelSkydome_ = Model::CreateFromOBJ("sphere", true);
	// 天球の生成
	skydome_ = new Skydome();
	// 天球の初期化
	skydome_->Initialize(modelSkydome_, &viewProjection_);
}

void GameOverScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		finished_ = true;
	}

	skydome_->Update();
}

void GameOverScene::Draw()
{
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	skydome_->Draw();

	gameOvermodel_->Draw(gameOverWorldTransform_, viewProjection_);

	Model::PostDraw();
}
