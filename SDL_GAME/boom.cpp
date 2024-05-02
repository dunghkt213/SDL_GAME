#include"boom.h"
#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"Game.h"
#include"map.h"
void boom:: run (SDL_Renderer* pRenderer)
{
	int map_x = Map::Instance()->get().first;
	int map_y = Map::Instance()->get().second;
	
	TextureManager::Instance()->draw_player("boom", x - map_x , y - map_y , 34 + fame*195, 34, 120, 120, 60,60, pRenderer, SDL_FLIP_NONE);
	if(delay ==0)this -> fame++;
	//cout << x<<" "<<y<<" "<< fame<< "\n";
	if (fame == 2)
	{
		SDL_Rect rect;
		rect.x = x;
		rect.y =  y;
		rect.w = w;
		rect.h = h;
		Game::Instance()->get_hitbox({ rect, 1 });
	}
	if (fame >= 9)
	{
		done = 1;
	}
}
void boom:: check_delay()
{
	if (delay == 0)
	{
		delay = 3;
	}
	delay--;
}