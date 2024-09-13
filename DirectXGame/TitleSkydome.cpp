#include "TitleSkydome.h"

void TitleSkydome::Initialize(Model* model, ViewProjection* viewProjection)
{
	assert(model);
	model_ = model;
	viewProjection_ = viewProjection;
	worldTransform_.Initialize();

	worldTransform_.scale_ = { 3.0f,3.0f,3.0f };

	
};

void TitleSkydome::Update()
{
	worldTransform_.UpdateMatrix();
}

void TitleSkydome::Draw()
{
	model_->Draw(worldTransform_, *viewProjection_);
}
