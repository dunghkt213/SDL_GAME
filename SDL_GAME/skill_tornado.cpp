#include"skill_thunder.h"
#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"
#include"skill_tornado.h"

void skill_tornado::draw(SDL_Renderer* pRenderer)
{

	move();
	int map_x = Map::Instance()->get().first;
	int map_y = Map::Instance()->get().second;
	TextureManager::Instance()->draw_player("tornado", x - map_x, y - map_y, 194 + fame * 31, 0,
		31, 31, 60, 90, pRenderer, SDL_FLIP_NONE);
	SDL_Rect rect;
	rect.x = x+10 ;
	rect.y = y ;
	rect.w = 40;
	rect.h = 90;
	//SDL_RenderDrawRect(pRenderer, &rect);
	Game::Instance()->get_hitbox({ rect,1 });
	if (delay == 0) fame++;
	if (fame >= 3)
	{
		fame = 0;
	}
	if (delay == 0)
	{
		delay = 3;
	}
	delay--;
}
void skill_tornado::move()
{
	if (x > x_end)
	{
		x-=4;
	}
	else if (x < x_end)
		{
			x += 4;
		}
	if (y > y_end)
	{
		y -= 4;
	}
	else if (y < y_end)
	{
		y += 4;
	}

	if (x == x_end && y == y_end)
	{
		done = 1;
	}
}