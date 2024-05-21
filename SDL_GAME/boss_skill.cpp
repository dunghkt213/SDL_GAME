#include"boss_skill.h"
#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"
#include"skill_tornado.h"

void boss_skill::draw(SDL_Renderer* pRenderer)
{

	move();
	int map_x = Map::Instance()->get().first;
	int map_y = Map::Instance()->get().second;
	SDL_Rect rect;
	if (status == 4)
	{
		TextureManager::Instance()->draw_player("tornado", x - map_x, y - map_y, 351 + fame * 32, 164,
			32, 23, 50, 60, pRenderer, SDL_FLIP_NONE);
		rect.x = x + 5 ;
		rect.y = y+10 ;
		rect.w = 30;
		rect.h = 40;
	}
	else
	{
		TextureManager::Instance()->draw_player("tornado", x - map_x, y - map_y, 351 + fame * 32, 164,
			32, 23, 50, 60, pRenderer, SDL_FLIP_HORIZONTAL);
		rect.x = x + 7 ;
		rect.y = y+10 ;
		rect.w = 26;
		rect.h = 40;
	}
	//SDL_RenderDrawRect(pRenderer, &rect);
	Game::Instance()->get_hitbox({ rect,2 });
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
void boss_skill::move()
{
	if (x > x_end)
	{
		x -= min(abs(x - x_end), 4);
	}
	else if (x < x_end)
	{
		x += min(abs(x - x_end), 4);
	}
	if (y > y_end)
	{
		y -= min(abs(y - y_end), 4);
	}
	else if (y < y_end)
	{
		y += min(abs(y - y_end), 4);
	}

	if (x == x_end && y == y_end)
	{
		done = 1;
	}
}