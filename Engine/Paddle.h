#pragma once

class Paddle
{
public:
	Paddle(int X);
	void MoveUp(float dt);
	void MoveDown(float dt);
	void Update();
	static constexpr int width = 10;
	int GetY(){ return static_cast<int>(y); }
	int GetX(){ return x; }
	int GetMovement(){ return movement; }
	int GetHeight(){ return static_cast<int>(height); }
	void Reset();
	void Shrink();
private:
	const int x;
	float y;
	float yOld;
	int movement;
	float height;
};