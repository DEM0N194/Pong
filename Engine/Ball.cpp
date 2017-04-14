#include "Ball.h"
#include "Graphics.h"
#include <cstdlib>
#include <ctime>

Ball::Ball()
{
	srand(time(NULL));

	x = Graphics::ScreenWidth / 2;
	y = Graphics::ScreenHeight / 2;
}

int Ball::Update()
{
	x += xv;
	y += yv;
	
	if (y - height / 2 < 0)
	{
		y = height / 2;
		yv = -yv;
	}
	if (y + height / 2 > Graphics::ScreenHeight)
	{
		y = Graphics::ScreenHeight - height / 2 - 1;
		yv = - yv;
	}


	if (x - width / 2 < 0 || x + width / 2 > Graphics::ScreenWidth)
	{
		x = Graphics::ScreenWidth / 2;
		y = Graphics::ScreenHeight / 2;
		return 1;
	}
	
	
	return 0;
}

void Ball::RandDirection()
{
	if (rand() % 2)
	{
		xv = 4;
	}
	else
	{
		xv = -4;
	}
	yv = rand() % 9 - 4;
}

void Ball::Shot(int XV)
{
	if (xv < 0 && XV > 0)
	{
		xv = -xv;
		xv += 2;
	}
	else if ( xv > 0 && XV < 0)
	{ 
		xv = -xv;
		xv -= 2;
	}
	else if (xv < 0 && XV < 0)
	{
		xv -= 2;
	}
	else
	{
		xv += 2;
	}
}

void Ball::Collision(Paddle * paddle)
{
	if (paddle->GetX() < 400)
	{
		if (x - width / 2 < paddle->GetX() + Paddle::width && y + height / 2 >= paddle->GetY() - paddle->GetHeight()/2 && y - height / 2 <= paddle->GetY() + paddle->GetHeight()/2)
		{
			x = paddle->GetX() + Paddle::width + width / 2;
			xv = -xv;
			if (paddle->GetMovement() < 0)
			{
				yv -= 1;
			}
			else if (paddle->GetMovement() > 0)
			{
				yv += 1;
			}
		}
	}
	else
	{
		if (x + width / 2> paddle->GetX() && y + height / 2 >= paddle->GetY() - paddle->GetHeight()/2 && y - height / 2 <= paddle->GetY() + paddle->GetHeight()/2)
		{
			x = paddle->GetX() - width / 2;
			xv = -xv;
			if (paddle->GetMovement() < 0)
			{
				yv -= 1;
			}
			else if (paddle->GetMovement() > 0)
			{
				yv += 1;
			}
		}
	}
}
