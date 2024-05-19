#pragma once
#include<SDL.h>
class skill_tornado
{
	int x=100,y=100;
	int x_end=500;
	int y_end=100;
	int fame = 0;
	int delay =3;
	bool done = 0;
public:
	void move();
	bool check_done()
	{
		return done;
	}
	void getxy(int x, int y, int last_x, int last_y)
	{
		this->x = x;
		this->y = y;
		this->x_end = last_x;
		this->y_end = last_y;

	}
	void draw(SDL_Renderer* pRenderer);
};