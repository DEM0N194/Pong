#pragma once
#include "Paddle.h"

class Ball
{
public:
	Ball();
	int Update();
	void RandDirection();
	int GetX(){ return static_cast<int>(x); }
	int GetY(){ return static_cast<int>(y); }
	void Shot(float XV);
	void Collision(Paddle *paddle);
	static constexpr int height = 20;
	static constexpr int width = 20;

private:
	float x;
	float y;
	float xv;
	float yv;
};