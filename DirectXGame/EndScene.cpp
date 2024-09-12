#include "EndScene.h"
#include <numbers>

EndScene::EndScene()
{
}

EndScene::~EndScene() { delete endmodel_; }

void EndScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	endmodel_ = Model::CreateFromOBJ("end", true);
	endWorldTransform_.Initialize();
	viewProjection_.Initialize();
	Timer_ = 0.0f;
}

void EndScene::Update()
{
	if (Input::GetInstance()->PushKey(DIK_SPACE)) {
		finished_ = true;
	}
	Timer_ += 1.0f / 60.0f;
	float param = std::sin(2.0f * std::numbers::pi_v<float> *Timer_ / kWalklMotionTime);
	float radian = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 2.0f;
	endWorldTransform_.rotation_.y = radian * (std::numbers::pi_v<float> / 90.0f);
	// 行列計算
	endWorldTransform_.UpdateMatrix();
}

void EndScene::Draw() {
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	if (endmodel_) {  // endmodel_がnullptrでないか確認
		endmodel_->Draw(endWorldTransform_, viewProjection_);
	}

	Model::PostDraw();
}
