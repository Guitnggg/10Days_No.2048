#pragma once
#include"Vector3.h"

class trap
{
private:


public:
	void Update();
	void Draw();
	void Timer();
	void Move();

	int coolTime_;
	int lostTime_;
	bool isCollision_;
	bool isCoolTime_;
	bool isLostTime_;
};