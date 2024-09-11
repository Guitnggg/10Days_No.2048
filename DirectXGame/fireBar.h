#pragma once
class fireBar
{
public:
	FireSphere fireSphere1_;
	FireSphere fireSphere2_;
	FireSphere fireSphere3_;
	FireSphere fireSphere4_;
	FireSphere fireSphere5_;
	FireSphere fireSphere6_;

	int isAlive_;


public:
	void Update();
	void Move();
	void Draw();

private:
	
};

