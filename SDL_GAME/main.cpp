#pragma once
#include<iostream>
#include"Game.h"
#include<SDL.h>
using namespace std;
Game* g_game = 0;
const int SCREEN_WIDTH =700;
const int SCREEN_HEIGHT = 500;
const char* WINDOW_TITLE = "Hello World!";

int main(int argc, char* argv[])
{
	g_game = new Game();
	g_game->init(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	while (g_game->running())
	{
		g_game->handleEvents();
		//g_game->update();
		g_game->render();
		SDL_Delay(30);
	}
	g_game->clean();
	return 0;
 
}
