#include "Paddle.h"
#include "Graphics.h"

Paddle::Paddle(int X)
:x(X)
{
	Reset();
}

void Paddle::MoveUp()
{
	yOld = y;
	y -= 7;
}

void Paddle::MoveDown()
{
	yOld = y;
	y += 7;
}

void Paddle::Update()
{
	if (y > yOld)
	{
		movement = 1;
	}
	else if (y < yOld)
	{
		movement = -1;
	}
	else
	{
		movement = 0;
	}

	if (y-height/2 < 0)
	{
		y = height/2;
	}
	if (y + height/2 >= Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height/2 - 1;
	}

	yOld = y;
}

void Paddle::Reset()
{
	y = Graphics::ScreenHeight / 2;
	height = 250;
}

void Paddle::Shrink()
{
	if (height > 50)
	{
		height -= 25;
	}
}
