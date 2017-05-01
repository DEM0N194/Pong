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
	p1score.SetPostion(gfx.ScreenWidth/2 - 50, 10);
	p1score.AlignMiddle();
	p1score.SetNumOf0(1);
	p2score.SetPostion(gfx.ScreenWidth/2 + 50, 10);
	p2score.AlignMiddle();
	p2score.SetNumOf0(1);
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
	float dt = ft.Mark();
	if (isPlaying)
	{
		//! ----------player1 update model----------
		if (wnd.kbd.KeyIsPressed(0x57))
		{
			player1.MoveUp(dt);
		}
		if (wnd.kbd.KeyIsPressed(0x53))
		{
			player1.MoveDown(dt);

		}
		player1.Update();

		//! ----------player2 update model----------
		if (wnd.kbd.KeyIsPressed(VK_UP))
		{
			player2.MoveUp(dt);
		}
		if (wnd.kbd.KeyIsPressed(VK_DOWN))
		{
			player2.MoveDown(dt);
		}
		player2.Update();

		//! ----------bullet1 update model----------
		if (wnd.kbd.KeyIsPressed(0x44))
		{
			if (!bullet1.IsActive())
			{
				bullet1.Shoot(10 * 60, player1.GetY());
			}
		}
		if (bullet1.IsActive())
		{
			bullet1.Update(dt);
			bullet1.Collision(&player2);
			bullet1.Collision(&ball);
		}

		//! ----------bullet2 update model----------
		if (wnd.kbd.KeyIsPressed(VK_LEFT))
		{
			if (!bullet2.IsActive())
			{
				bullet2.Shoot(-10 * 60, player2.GetY());
			}
		}
		if (bullet2.IsActive())
		{
			bullet2.Update(dt);
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
		switch (ball.Update(dt))
		{
			case 1:
				p1score++;
				isPlaying = false;
				player1.Reset();
				player2.Reset();
				bullet1.StopBullet();
				bullet2.StopBullet();
				break;
			case 2:
				p2score++;
				isPlaying = false;
				player1.Reset();
				player2.Reset();
				bullet1.StopBullet();
				bullet2.StopBullet();
				break;
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

	p1score.Draw(gfx);
	p2score.Draw(gfx);
	gfx.chDash(gfx.ScreenWidth/2-10, 15, Colors::White);
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
