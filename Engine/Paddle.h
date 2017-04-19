#pragma once

class Paddle
{
public:
	Paddle(int X);
	void MoveUp();
	void MoveDown();
	void Update();
	static constexpr int width = 10;
	int GetY(){ return static_cast<int>(y); }
	int GetX(){ return x; }
	int GetMovement(){ return movement; }
	float GetHeight(){ return height; }
	void Reset();
	void Shrink();
private:
	const int x;
	float y;
	float yOld;
	int movement;
	float height;
};