#pragma once
class ani_Gold
{
private:
	int x, y;
	int fame=0;
	int delay_done = 5;
	int delay = 5;
	bool done = 0;
public:
	void draw(SDL_Renderer* pRenderer);
	void get_xy(int tx, int ty);
	void check_delay();
	bool check_done();
	void move();
};