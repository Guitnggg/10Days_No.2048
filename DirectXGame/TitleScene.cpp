#include "TitleScene.h"
#include <numbers>

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { 
	delete titlemodel_;
	delete modelSkydome_;
}

void TitleScene::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();
	titlemodel_ = Model::CreateFromOBJ("title", true);
	titleWorldTransform_.Initialize();
	viewProjection_.Initialize();
	Timer_ = 0.0f;

	//  3Dモデルの生成
	modelSkydome_ = Model::CreateFromOBJ("sphere", true);
	// 天球の生成
	skydome_ = new Skydome();
	// 天球の初期化
	skydome_->Initialize(modelSkydome_, &viewProjection_);
}

void TitleScene::Update() {
	//  天球の更新
	skydome_->Update();

	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}
	Timer_ += 1.0f / 60.0f;
	float param = std::sin(2.0f * std::numbers::pi_v<float> *Timer_ / kWalklMotionTime);
	float radian = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 1.0f;
	titleWorldTransform_.rotation_.y = radian * (std::numbers::pi_v<float> / 90.0f);
	// 行列計算
	titleWorldTransform_.UpdateMatrix();
}

void TitleScene::Draw() {
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	titlemodel_->Draw(titleWorldTransform_, viewProjection_);

	// 天球の描画
	skydome_->Draw();

	Model::PostDraw();
}