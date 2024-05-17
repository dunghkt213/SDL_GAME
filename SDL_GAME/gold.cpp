#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"
void ani_Gold::draw(SDL_Renderer* pRenderer)
{
	int map_x = Map::Instance()->get().first;
	int map_y = Map::Instance()->get().second;
	//cout <<"goldrun"<<" "<<delay<<" "<< x << " " << y << "\n";
	TextureManager::Instance()->draw_player("gold", x - map_x+20, y - map_y+20, 41 + fame * 123, 31,
		80, 68, 45, 45, pRenderer, SDL_FLIP_NONE);
	if (delay == 0) fame++;
	if (fame >= 7)
	{
		int p_x = Player::Instance()->getxy().first;
		int p_y = Player::Instance()->getxy().second;
		cout << p_x - 42 << " " << p_y - 7 << " * ";
		cout << x << " " << y << "\n";
		fame--;
		if (abs(p_x-42 - x)<15 && abs(p_y- 7-y)<15)
		{
			Game::Instance()->update_number_gold(1);
			done = 1;
		}
	}
	check_delay();
	delay --;
}
void ani_Gold:: get_xy(int tx, int ty)
{
	this->x = tx;
	this->y = ty;
}
void ani_Gold:: check_delay()
{
	if (delay == 0)
	{
		delay = 3;
	}
}
bool ani_Gold:: check_done()
{
	return done;
}