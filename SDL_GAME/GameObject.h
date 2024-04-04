#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include<vector>
struct Input
{
	int left;
	int right;
	int up;
	int down;
	int stop;
	int attack;
	bool move_right = 1;
	bool move_left = false;
	bool move_up = false;
	bool move_down = false;
	bool direction = false;
	void resert()
	{
		move_right = false;
		move_left = false;
		move_up = false;
		move_down = false;
		direction = false;
	}
};
struct fame
{
	int fame;
	int move_left = 0;
	int move_up = 0;
	int move_right = 0;
	int move_down= 0;
	int move_attack=0;
	int move_die = 0;
	void check()
	{
		if (move_left > 5)
		{
			move_left = 0;
		}
		if (move_right > 5)
		{
			move_right = 0;
		}
		if (move_up > 5)
		{
			move_up = 0;
		}
		if (move_down > 5)
		{
			move_down = 0;
		}
		//cout << " " << "move up" << " " << move_up << '\n';
		//cout << " " << "move right" << " " << move_right << '\n';
		//cout << " " << "move down" << " " << move_down << '\n';
		//cout << " " << "move left" << " " << move_left << '\n';
	}
};
class GameObject
{
public:
	virtual void load(int x, int y, int width, int height,
		std::string textureID);
	virtual void draw(SDL_Renderer* pRenderer);
	virtual void update();
protected:
	std::string m_textureID;
	int m_currentFrame;
	int m_currentRow;
	int m_x;
	int m_y;
	int m_width;
	int m_height;
};


class Player : public GameObject
{
public:
	static Player* Instance()
	{
		if (Player_Instance == 0)
		{
			Player_Instance = new Player();
			return Player_Instance;
		}
		return Player_Instance;
	}
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
	void attack();
	void move();
	void resert();
	void get(int x, int y);
    void HandelInput(SDL_Event events, SDL_Renderer* screen);
private:
	static Player* Player_Instance;
	int step = 46;
	int non_move_mouse_right = 48;
	int non_move_mouse_down = 0;
	int non_move_mouse_up = 96;
	int move_down = 162;
	int move_right = 210;
	int move_up = 260;
	int attack_down = 308;
	int attack_right = 336;
	int attack_up = 384;
	int die = 432;
    int check_die = 0;
	int check_attack = 0;
	int status;
	int player_width=15;
	int player_height=24;
	vector<SDL_Texture*>Animation[9];
	Input input_status;
	int p_x=350;
	int p_y=220;
	fame Fame;
	int dr_width = 30;
	int dr_height = 50;
};


class Enemy : public GameObject
{
public:
	void draw(SDL_Renderer* pRenderer);
	void update();
	void clean();
};


