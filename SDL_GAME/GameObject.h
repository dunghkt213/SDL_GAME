#pragma once
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include<vector>
#include"tool.h"
#include"boom.h"
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
	int die = 0;
	int move_stop = 0;
	int move_being_attack = 0;
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
		if (move_down > 5)
		{
			move_down = 0;
		}
		if (move_stop > 5)
		{
			move_stop = 0;
		}
		if (move_being_attack > 5)
		{
			move_being_attack = 0;
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
	void attack();
	void move();
	void resert();
	void get(int x, int y);

	pair<int, int> getxy()
	{
		pair<int, int>a;
		a.first = p_x;
		a.second = p_y;
		return a;
	}
    void HandelInput(SDL_Event events, SDL_Renderer* screen);
	void set_delay()
	{
		if (delay <= 0)
		{
			delay=1;
		}
		delay--;
	}
	void being_attack_block(vector<pair<SDL_Rect, SDL_Rect>> rect);
	void check_being_attack(vector<pair<SDL_Rect, int>> v);
	void skill();
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
	bool being_attack=0;
	Input input_status;
	int p_x=100;
	int p_y=100;
	int p_w =46;
    int p_h =48;
	fame Fame;
	int dr_width = 30;
	int dr_height = 50;
	int hp = 100;
	int delay = 0;
	bool skill1 = 0;
	int time_skill1 = 0;
	bool skill2 = 0;
	int time_skill2 = 0;
	bool intput_skill =0;
	vector<boom> vector_boom;
};


class Enemy : public GameObject	
{
public:
	void draw(SDL_Renderer* pRenderer);
	void move();
	void set_delay();
	void check_being_attack(vector<pair<SDL_Rect,int>> rect, SDL_Renderer* pRenderer);
	void set_vt(int x,int y)
	{
		this->e_x = x;
		this->e_y = y;
	}
	bool check_die()
	{
		if (Fame.move_die >= 4 && die == 1 && time_die<=0) return 1;
		else return 0;
	}
	void spawn();
private:
	int time_die =20;
	int e_w = 40;
	int e_h = 40;
	int e_x=380;
	int e_y=380;
	int status=0 ;
	int move_attack = 0;
	fame Fame;
	bool being_attack = 0;
	bool attack = 0;
	int delay = 0;
	bool die = 0;
	int hp = 200;
	int last_status = 2;
};


class enemy_home
{
private:
	int hp=300;
	int x=800;
	int y=339;
	int w = 70;
	int h = 90;
	int die = 0;
public:
	void draw(SDL_Renderer* pRenderer);
	void being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer);
};

class Enemy2 : public GameObject
{
public:
	void draw(SDL_Renderer* pRenderer);
	void move();
	void set_delay();
	void check_being_attack(vector<pair<SDL_Rect, int>> rect, SDL_Renderer* pRenderer);
	void set_vt(int x, int y)
	{
		this->e_x = x;
		this->e_y = y;
	}
	bool check_die()
	{
		if (Fame.move_die >= 7 && die == 1 && die_time == 1) return 1;
		else return 0;
	}
	void spawn();
private:
	int srcy = 27;
	bool die_time = 0;
	int time_die = 20;
	int e_w = 40;
	int e_h = 40;
	int e_x = 300;
	int e_y = 300;
	int status = 0;
	int move_attack = 0;
	fame Fame;
	bool being_attack = 0;
	bool attack = 0;
	int delay = 0;
	bool die = 0;
	int hp = 200;
	int last_status = 2;
};
