#pragma once
#include "Model.h"
#include "ViewProjection.h"
#include "WorldTransform.h"
#include "DirectXCommon.h"
#include "Input.h"

/// <summary>
/// エンドシーン
/// </summary>

class EndScene
{
public:
	EndScene();

	~EndScene();

	void Initialize();

	void Update();

	void Draw();

	bool IsFinished()const { return finished_; }

private:

	//最初の角度[度]
	static inline const float kWalkMotionAngleStart = 5.0f;
	// 最後の角度[度]
	static inline const float kWalkMotionAngleEnd = -5.0f;
	// アニメーションの周期となる時間[秒]
	static inline const float kWalklMotionTime = 1.0f;
	//タイマー
	float Timer_ = 0.0f;
	//終了フラグ
	bool finished_ = false;
	DirectXCommon* dxCommon_ = nullptr;
	WorldTransform endWorldTransform_;
	ViewProjection viewProjection_;
	Model* endmodel_ = nullptr;

};

