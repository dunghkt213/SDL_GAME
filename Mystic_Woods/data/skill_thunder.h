#pragma once
#include<SDL.h>
class skill_thunder
{
private:
	int x, y;
	int fame = 0;
	int delay = 3;
	bool done = 0;
public:
	void get_xy(int x, int y,int fame)
	{
		this->fame = -fame;
		this->x = x;
		this->y = y;
	}
	bool check_done()
	{
		return done;
	}
	void draw(SDL_Renderer* pRenderer);
};