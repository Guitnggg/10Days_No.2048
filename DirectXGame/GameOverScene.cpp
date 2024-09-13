#include "GameOverScene.h"

GameOverScene::GameOverScene(){}

GameOverScene::~GameOverScene() { delete gameOvermodel_; }

void GameOverScene::Initialize()
{
	dxCommon_ = DirectXCommon::GetInstance();
	gameOvermodel_ = Model::CreateFromOBJ("gameOver", true);
	gameOverWorldTransform_.Initialize();
	viewProjection_.Initialize();
}

void GameOverScene::Update()
{
	if (Input::GetInstance()->TriggerKey(DIK_SPACE))
	{
		finished_ = true;
	}
}

void GameOverScene::Draw()
{
	ID3D12GraphicsCommandList* commandList = dxCommon_->GetCommandList();

	Model::PreDraw(commandList);

	gameOvermodel_->Draw(gameOverWorldTransform_, viewProjection_);

	Model::PostDraw();
}
