#pragma once
#include "Paddle.h"
#include "Ball.h"

class Projectile
{
public:
	Projectile(int X);
	int GetX(){ return x; }
	int GetY(){ return y; }
	bool IsActive(){ return bActive; }
	void Shoot(int XV, int Y);
	void Update();
	void StopBullet();
	void Collision(Paddle *paddle);
	void Collision(Ball *ball);

	static constexpr int width = 20;
	static constexpr int height = 8;
private:

	bool bActive = false;
	const int StartPosX;
	int x;
	int y;
	int xv;
};