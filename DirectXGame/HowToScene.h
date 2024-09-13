#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "Input.h"

/// <summary>
/// 操作方法説明シーン
/// </summary>

class HowToScene
{
public:
	HowToScene();

	~HowToScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished()const { return finished_; }

private:

	//終了フラグ
	bool finished_ = false;
	DirectXCommon* dxCommon_ = nullptr;

	WorldTransform howToWorldTransform_;

	ViewProjection viewProjection_;

	Model* howTomodel_ = nullptr;

};

