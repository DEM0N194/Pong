#pragma once
#include "Paddle.h"
#include "Ball.h"

class Projectile
{
public:
	Projectile(float X);
	int GetX(){ return static_cast<int>(x); }
	int GetY(){ return y; }
	bool IsActive(){ return bActive; }
	void Shoot(float XV, int Y);
	void Update();
	void StopBullet();
	void Collision(Paddle *paddle);
	void Collision(Ball *ball);

	static constexpr int width = 20;
	static constexpr int height = 8;
private:

	bool bActive = false;
	const float StartPosX;
	float x;
	int y;
	float xv;
};