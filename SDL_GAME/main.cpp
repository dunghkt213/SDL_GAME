#pragma once
#include<iostream>
#include"Game.h"
#include<SDL.h>
#include<cstdlib>
#include<ctime>
#include"options.h"
#include"GameObject.h"
using namespace std;
Game* g_game = 0;
const int SCREEN_WIDTH =700;
const int SCREEN_HEIGHT = 500;
const char* WINDOW_TITLE = "Mystic_Woods";
int x = time(0);
int main(int argc, char* argv[])
{
	srand(x);
	g_game = new Game();
	
	g_game->init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	while (g_game->running())
	{
		//g_game->handleEvents();
		//g_game->update();
		if (options::Instance()->check_reset() == 1)
		{
			g_game = new Game();
			g_game->load_data(); 
			g_game->get_Window(options::Instance()->window());
			g_game->get_Renderer(options::Instance()->Renderer());
			Game::Instance()->reset();
			Player::Instance()->reset();
			Player2::Instance()->reset();
			Map::Instance()->reset();
			options::Instance()->get_reset(0);
		}
		//cout << options::Instance()->check_poster() << "\n";
		g_game->render();
		g_game->handleEvents();
		SDL_Delay(30);
	}
	g_game->clean();
	return 0;
 
}
