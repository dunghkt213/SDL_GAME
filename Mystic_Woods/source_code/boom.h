#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include<vector>
#include<vector>

class boom
{
private:
	int fame = 0;
	int x=250;
	int y=200;
	int w = 60;
	int h = 60;
	int delay = 0;
	bool done = 0;
	bool check_boom = 0;
	bool check_sound = 0;
public:
	void get_xy(int x,int y,int delay_fame)
	{
		this->x = x;
		this->y = y;
		this->fame = delay_fame*(-1);
	}
	void plus_fame()
	{
		fame++;
	}
	void run(SDL_Renderer* pRenderer,int i);
	void check_delay();
	bool check_done()
	{
		return done;
	}

};