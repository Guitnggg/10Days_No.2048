#include "TitleScene.h"
#include <numbers>

TitleScene::TitleScene() {}

TitleScene::~TitleScene() { delete titlemodel_; }

void TitleScene::Initialize() {
	dxCommon_ = DirectXCommon::GetInstance();
	titlemodel_ = Model::CreateFromOBJ("title", true);
	titleWorldTransform_.Initialize();
	viewProjection_.Initialize();
	Timer_ = 0.0f;

	//modeltitleSkydome_ = Model::CreateFromOBJ("titlesphere", true);
	//titleskydome_ = new TitleSkydome;
	//titleskydome_->Initialize(modeltitleSkydome_, &viewProjection_);
	//// デバックカメラの生成
}

void TitleScene::Update() {
	if (Input::GetInstance()->TriggerKey(DIK_SPACE)) {
		finished_ = true;
	}
	Timer_ += 1.0f / 60.0f;
	float param = std::sin(2.0f * std::numbers::pi_v<float> *Timer_ / kWalklMotionTime);
	float radian = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 1.0f;
	titleWorldTransform_.rotation_.y = radian * (std::numbers::pi_v<float> / 90.0f);
	// 行列計算
	titleWorldTransform_.UpdateMatrix();

	/*titleskydome_->Update();*/
}

void TitleScene::Draw() {
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	/*titleskydome_->Draw();*/

	titlemodel_->Draw(titleWorldTransform_, viewProjection_);

	Model::PostDraw();
}