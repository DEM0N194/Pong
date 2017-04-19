#include "MainWindow.h"
#include "Game.h"

//!? If you think paging some data from disk into RAM is slow,
//!? try paging it into a simian cerebrum over a pair of optical nerves.
//!?                                              - gameprogrammingpatterns.com

Game::Game( MainWindow& wnd )
:wnd( wnd )
,gfx( wnd )
,player1(10)
,player2(gfx.ScreenWidth - Paddle::width - 10)
,bullet1(10)
,bullet2(gfx.ScreenWidth - Paddle::width - 10)
{
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	if (isPlaying)
	{
		//! ----------player1 update model----------
		if (wnd.kbd.KeyIsPressed(0x57))
		{
			player1.MoveUp();
		}
		if (wnd.kbd.KeyIsPressed(0x53))
		{
			player1.MoveDown();

		}
		player1.Update();

		//! ----------player2 update model----------
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			player2.MoveUp();
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			player2.MoveDown();
		}
		player2.Update();

		//! ----------bullet1 update model----------
		if (wnd.kbd.KeyIsPressed(0x44))
		{
			if (!bullet1.IsActive())
			{
				bullet1.Shoot(10, player1.GetY());
			}
		}
		if (bullet1.IsActive())
		{
			bullet1.Update();
			bullet1.Collision(&player2);
			bullet1.Collision(&ball);
		}

		//! ----------bullet2 update model----------
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (!bullet2.IsActive())
			{
				bullet2.Shoot(-10, player2.GetY());
			}
		}
		if (bullet2.IsActive())
		{
			bullet2.Update();
			bullet2.Collision(&player1);
			bullet2.Collision(&ball);
		}

		if (bullet1.IsActive() && bullet2.IsActive())
		{
			if (bullet1.GetX() - Projectile::width / 2  <= bullet2.GetX() + Projectile::width / 2  &&
			    bullet1.GetX() + Projectile::width / 2  >= bullet2.GetX() - Projectile::width / 2  &&
			    bullet1.GetY() - Projectile::height / 2 <= bullet2.GetY() + Projectile::height / 2 &&
			    bullet1.GetY() + Projectile::height / 2 >= bullet2.GetY() - Projectile::height / 2)
			{
				bullet1.StopBullet();
				bullet2.StopBullet();
			}
		}

		//! ----------ball update model----------
		ball.Collision(&player1);
		ball.Collision(&player2);
		if (ball.Update())
		{
			isPlaying = false;
			player1.Reset();
			player2.Reset();
			bullet1.StopBullet();
			bullet2.StopBullet();
		}
	}
	else
	{
		if (wnd.kbd.KeyIsPressed(VK_SPACE))
		{
			isPlaying = true;
			ball.RandDirection();
		}

	}
}

void Game::ComposeFrame()
{
	DrawPaddle(&player1);
	DrawPaddle(&player2);
	DrawBall(&ball);

	if (bullet1.IsActive()) DrawBullet(&bullet1);
	if (bullet2.IsActive()) DrawBullet(&bullet2);
}

void Game::DrawPaddle(Paddle *paddle)
{
	for (int i = paddle->GetY() - paddle->GetHeight()/2; i <= paddle->GetY() + paddle->GetHeight()/2; i++)
	{
		for (int j = paddle->GetX(); j < paddle->GetX() + Paddle::width; j++)
		{
			gfx.PutPixel(j, i, 255, 255, 255);
		}
	}
}

void Game::DrawBall(Ball *ball)
{
	for (int i = ball->GetY() - Ball::height/2; i < ball->GetY() + Ball::height/2; i++)
	{
		for (int j = ball->GetX() - Ball::width/2; j < ball->GetX() + Ball::width/2; j++)
		{
			gfx.PutPixel(j, i, 255, 255, 255);
		}
	}
}

void Game::DrawBullet(Projectile *bullet)
{
	for (int i = bullet->GetY() - Projectile::height/2; i < bullet->GetY() + Projectile::height/2; i++)
	{
		for (int j = bullet->GetX() - Projectile::width/2; j < bullet->GetX() + Projectile::width/2; j++)
		{
			gfx.PutPixel(j, i, 100, 100, 100);
		}
	}
}
