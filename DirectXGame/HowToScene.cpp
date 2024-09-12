#include "HowToScene.h"
#include <numbers>

HowToScene::HowToScene(){}

HowToScene::~HowToScene() { delete howTomodel_; }

void HowToScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	howTomodel_ = Model::CreateFromOBJ("howTo", true);
	howToWorldTransform_.Initialize();
	viewProjection_.Initialize();
}

void HowToScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		finished_ = true;
	}
}

void HowToScene::Draw()
{
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	howTomodel_->Draw(howToWorldTransform_, viewProjection_);

	Model::PostDraw();
}
