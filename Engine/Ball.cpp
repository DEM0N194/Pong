#include "Ball.h"
#include "Graphics.h"

Ball::Ball()
	: rng(rd())
	, binDist(0, 1)
	, yvDist(1.0f,4.0f)
{
	x = Graphics::ScreenWidth / 2;
	y = Graphics::ScreenHeight / 2;
}

int Ball::Update(float dt)
{
	x += xv * dt;
	y += yv * dt;
	
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
	if (binDist(rng))
	{
		xv = 4 * baseSpeed;
	}
	else
	{
		xv = -4 * baseSpeed;
	}
	if (binDist(rng))
	{
		yv = yvDist(rng) * baseSpeed;
	}
	else
	{
		yv = -yvDist(rng) * baseSpeed;
	}
}

void Ball::Shot(float XV)
{
	if (xv < 0 && XV > 0)
	{
		xv = -xv;
		xv += 2 * baseSpeed;
	}
	else if ( xv > 0 && XV < 0)
	{ 
		xv = -xv;
		xv -= 2 * baseSpeed;
	}
	else if (xv < 0 && XV < 0)
	{
		xv -= 2 * baseSpeed;
	}
	else
	{
		xv += 2 * baseSpeed;
	}
}

void Ball::Collision(Paddle * paddle)
{
	if (paddle->GetX() < 400)
	{
		if (x - width / 2 < paddle->GetX() + Paddle::width && y + height / 2 >= paddle->GetY() - paddle->GetHeight()/2 && y - height / 2 <= paddle->GetY() + paddle->GetHeight()/2)
		{
			x = static_cast<float>(paddle->GetX() + Paddle::width + width / 2);
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
			x = static_cast<float>(paddle->GetX() - width / 2);
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
