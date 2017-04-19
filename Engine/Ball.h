#pragma once
#include "Paddle.h"
#include <random>

class Ball
{
public:
	Ball();
	int Update(float dt);
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
	static constexpr float baseSpeed = 60;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> binDist;
	std::uniform_real_distribution<float> yvDist;
};