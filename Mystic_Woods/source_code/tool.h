#pragma once
#include<SDL.h>
#include<iostream>
#include"TextManager.h"
class tool
{
public:
	void handlein(SDL_Event event);
    void draw(SDL_Renderer* pRenderer);
	void createfile();
private:
	int MAP[3000][3000];
	int x=1, y=1;
};