#pragma once
#include "Model.h"
#include "WorldTransform.h"
#include "ViewProjection.h"
#include <cassert>

class TitleSkydome
{
public:

	void Initialize(Model* model, ViewProjection* viewProjection);

	void Update();

	void Draw();

private:

	//ワールド変換データ
	WorldTransform worldTransform_;
	//モデル
	Model* model_ = nullptr;
	//ビュープロジェクション
	ViewProjection* viewProjection_;

};

