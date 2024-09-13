#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "Input.h"

/// <summary>
/// ゲームオーバーシーン
/// </summary>

class GameOverScene
{
public:
	GameOverScene();

	~GameOverScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished() const { return finished_; }

private:

	//終了フラグ
	bool finished_ = false;
	DirectXCommon* dxCommon_ = nullptr;
	WorldTransform gameOverWorldTransform_;
	ViewProjection viewProjection_;
	Model* gameOvermodel_ = nullptr;
};

