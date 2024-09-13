#include "trap.h"
#include"time.h"
#define _USE_MATH_DEFINES 
#include"cmath"
#include"math.h"
#include"Model.h"

void trap::Update()
{
	Move();
	if (isCollision_) {
		Timer();
		
	}





}

void trap::Draw()
{

}

//作動時の処理
void trap::Timer()
{
	lostTime_ = 168;
	if (isLostTime_==true) {
		lostTime_ -= 1;

		if (lostTime_ <= 0) {
			lostTime_ = 0;
			coolTime_ = 60;
			isCoolTime_ = true;

			if (isCoolTime_==true) {
				isLostTime_ = false;
				coolTime_ -= 1;

				if (coolTime_ <= 0) {
					lostTime_ = 168;
				}
			}

		}
	}
	
	
}

void trap::Move()
{

	if (isCoolTime_ == true) {
		
	}

}
