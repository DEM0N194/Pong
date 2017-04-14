#pragma once

class Paddle
{
public:
	Paddle(int X);
	void MoveUp();
	void MoveDown();
	void Update();
	static constexpr int width = 10;
	int GetY(){ return y; }
	int GetX(){ return x; }
	int GetMovement(){ return movement; }
	int GetHeight(){ return height; }
	void Reset();
	void Shrink();
private:
	const int x;
	int y;
	int yOld;
	int movement;
	int height;
};