#include "fireBar.h"
#include"struct.h"
#define _USE_MATH_DEFINES
#include"cmath"
#include"math.h"
#include"time.h"

void fireBar::Update()
{
	Move();

	//

	
	if (isAlive_ == true) {
		Draw();
	}
}

void fireBar::Move()
{
	//直線上に並びながら回転(中心が1)
	//中心は回転しない
	//線形補間で
	Timer();

	if (isAlive_==true) {
		//float angle = fireSphere1_.speedX *;
		//fireSphere1_.posX = fireSphere1_.posX * angle;


	}


}

void fireBar::Draw()
{
	//回転しながら
	//座標にそのまま

}

void fireBar::Timer()
{

}
