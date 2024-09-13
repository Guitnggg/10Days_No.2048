#include "spiderTrap.h"
#include"time.h"
#define _USE_MATH_DEFINES 
#include"cmath"
#include"math.h"
#include"Model.h"

void spiderTrap::Update()
{
	Move();
	if (isCollision_) {
		Timer();

	}





}

void spiderTrap::Draw()
{

}

//作動時の処理
void spiderTrap::Timer()
{
	lostTime_ = 168;
	if (isLostTime_ == true) {
		lostTime_ -= 1;

		if (lostTime_ <= 0) {
			lostTime_ = 0;
			coolTime_ = 60;
			isCoolTime_ = true;

			if (isCoolTime_ == true) {
				isLostTime_ = false;
				coolTime_ -= 1;

				if (coolTime_ <= 0) {
					lostTime_ = 168;
				}
			}

		}
	}


}

void spiderTrap::Move()
{

	if (isCoolTime_ == true) {
		
	}

}
