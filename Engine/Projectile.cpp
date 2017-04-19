#include "Projectile.h"
#include "Graphics.h"

Projectile::Projectile(float X)
:StartPosX(X)
{
	x = X;
}

void Projectile::Collision(Paddle *paddle)
{
	if (paddle->GetX() < 400)
	{
		if (x <= paddle->GetX() + Paddle::width && y + height >= paddle->GetY() - paddle->GetHeight() / 2 && y <= paddle->GetY() + paddle->GetHeight() / 2)
		{
			paddle->Shrink();
			StopBullet();
		}
	}
	else
	{
		if (x + width >= paddle->GetX() && y + height >= paddle->GetY() - paddle->GetHeight() / 2 && y <= paddle->GetY() + paddle->GetHeight() / 2)
		{
			paddle->Shrink();
			StopBullet();
		}
	}
}

void Projectile::Collision(Ball * ball)
{
	if (x <= ball->GetX() + Ball::width/2 && x + width >= ball->GetX() - Ball::width/2 && y + height >= ball->GetY() - Ball::height/2 && y <= ball->GetY() + Ball::height/2)
	{
		ball->Shot(xv);
		StopBullet();
	}
}

void Projectile::Shoot(float XV, int Y)
{
	bActive = true;
	x = StartPosX;
	xv = XV;
	y = Y;
}

void Projectile::Update(float dt)
{
	x += xv * dt;
	if (x - width/2 < 0 || x + width/2 > Graphics::ScreenWidth)
	{
		StopBullet();
	}
}

void Projectile::StopBullet()
{
	// x = StartPosX;
	xv = 0;
	bActive = false;
}

