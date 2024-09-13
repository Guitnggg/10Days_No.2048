#pragma once
#include"Vector3.h"
	class Player;
class spiderTrap
{	
	private:

	public:
		void Update();
		void Draw();
		void Timer();
		void Move();
		Player* player_;

		int coolTime_;
		int lostTime_;
		bool isCollision_;
		bool isCoolTime_;
		bool isLostTime_;
	
};

