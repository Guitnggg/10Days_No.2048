#pragma once
#include"Vector3.h"

class fireBar
{



public:
	void Update();
	void Move();
	void Draw();
	void Timer();
	int GetIsAlive(int isAlive) { isAlive = isAlive_; }
	int GetTimeCount(int timeCount) { timeCount = timeCount_; }

private:
	FireSphere fireSphere1_;
	FireSphere fireSphere2_;
	FireSphere fireSphere3_;
	FireSphere fireSphere4_;
	FireSphere fireSphere5_;
	FireSphere fireSphere6_;

	int isAlive_;
	int timeCount_;
};