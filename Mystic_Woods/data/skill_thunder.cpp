#include"skill_thunder.h"
#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"

void skill_thunder::draw(SDL_Renderer* pRenderer)
{
	int map_x = Map::Instance()->get().first;
	int map_y = Map::Instance()->get().second;
	TextureManager::Instance()->draw_player("skill_thunder", x - map_x , y - map_y , 62 + fame * 65, 0,
		54, 63, 80, 80, pRenderer, SDL_FLIP_NONE);
	if (fame == 5)
	{
		SDL_Rect rect;
		rect.x = x+8;
		rect.y = y+25 ;
		rect.w = 68;
		rect.h = 50;
		Game::Instance()->get_hitbox({ rect,1 });
	}
	if (delay == 0) fame++;
	if (fame >= 11) done = 1;
	if (delay == 0)
	{
		delay = 3;
	}
	delay--;

}