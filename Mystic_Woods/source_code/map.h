#pragma once
#include<SDL.h>
#include"TextManager.h"
class Map
{
private:
	int x=0, y=0;
	int  height = 500;
	int  width = 700;
	string m_textureID = "map";
	static Map* Map_Instance;
	int move_x;
	int move_y;
public:
	static Map* Instance()
	{	
		if (Map_Instance == 0)
		{
			Map_Instance = new Map();
			return Map_Instance;
		}
		return Map_Instance;
	}
	void reset();
	void Map_get(int x, int  y);
	void Map_update(int p_x,int p_y);
	void Map_draw( SDL_Renderer* pRenderer);
	pair<int, int> get();
};