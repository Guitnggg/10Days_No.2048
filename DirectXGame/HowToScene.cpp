#include "HowToScene.h"
#include <numbers>

HowToScene::HowToScene(){}

HowToScene::~HowToScene() { 
	delete howTomodel_;
	delete titleskydome_;
}

void HowToScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	howTomodel_ = Model::CreateFromOBJ("howTo", true);
	howToWorldTransform_.Initialize();
	viewProjection_.Initialize();

	modeltitleSkydome_ = Model::CreateFromOBJ("titlesphere", true);
	titleskydome_ = new TitleSkydome;
	titleskydome_->Initialize(modeltitleSkydome_, &viewProjection_);
}

void HowToScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		finished_ = true;
	}

	titleskydome_->Update();
}

void HowToScene::Draw()
{
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	titleskydome_->Draw();

	howTomodel_->Draw(howToWorldTransform_, viewProjection_);

	Model::PostDraw();
}
