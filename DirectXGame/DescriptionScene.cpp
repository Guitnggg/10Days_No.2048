#include "DescriptionScene.h"
#include <numbers>

DescriptionScene::DescriptionScene(){}

DescriptionScene::~DescriptionScene() { delete descriptionmodel_; }

void DescriptionScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	descriptionmodel_ = Model::CreateFromOBJ("title", true);
	descriptionWorldTransform_.Initialize();
	viewProjection_.Initialize();
	Timer_ = 0.0f;
}

void DescriptionScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		finished_ = true;
	}
	Timer_ += 1.0f / 60.0f;
	float param = std::sin(2.0f * std::numbers::pi_v<float> *Timer_ / kWalklMotionTime);
	float radian = kWalkMotionAngleStart + kWalkMotionAngleEnd * (param + 1.0f) / 2.0f;
	descriptionWorldTransform_.rotation_.y = radian * (std::numbers::pi_v<float> / 90.0f);
	// 行列計算
	descriptionWorldTransform_.UpdateMatrix();
}

void DescriptionScene::Draw()
{
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	descriptionmodel_->Draw(descriptionWorldTransform_, viewProjection_);

	Model::PostDraw();
}
