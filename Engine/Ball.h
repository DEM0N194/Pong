#pragma once
#include "Paddle.h"

class Ball
{
public:
	Ball();
	int Update();
	void RandDirection();
	int GetX(){ return x; }
	int GetY(){ return y; }
	void Shot(int XV);
	void Collision(Paddle *paddle);
	static constexpr int height = 20;
	static constexpr int width = 20;

private:
	int x;
	int y;
	int xv;
	int yv;
};