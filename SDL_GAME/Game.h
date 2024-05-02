#include<SDL.h>
#include<vector>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"GameObject.h"
#include"map.h"
#include"boom.h"
//#include"boom.h"
class Game
{
public:
	static Game* Instance()
	{
		if (Game_Instance == 0)
		{
			Game_Instance = new Game();
			return Game_Instance;
		}
		return Game_Instance;
	}
	SDL_Renderer* get_render();
	bool init(const char* title, int xpos, int ypos, int width, int height, int flags);
	void render();
	void update();
	void waitUntilKeyPressed();
	void handleEvents();
	void clean();
	bool running() { return m_bRunning;}
	void draw();
	void push(Enemy enemy);
	void get_hitbox(pair<SDL_Rect, int> u)
	{
		v.push_back(u);
	}
	//void get_Boom(boom b)
	//{
	//	Boom.push_back(b);
	//}
	void clear_hitbox()
	{
		v.clear();
	}
	//vector<boom> get_vector_boom()
	//{
	//	return Boom;
	//}
	vector<pair<SDL_Rect, int>> hitbox()
	{
		return v;
	}
	//int get_size_Boom()
	//{
	//	return Boom.size();
	//}
private:
	int m_currentFrame;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning=1;
	SDL_Texture* m_pTexture; 
	SDL_Rect m_sourceRectangle; 
	SDL_Rect m_destinationRectangle; 
	vector<Enemy> vector_enemy;
	static Game* Game_Instance;
	int map_box[701][501];
	tool tools;
	vector<pair<SDL_Rect,int>>v;
	enemy_home Enemy_home;
	//vector<boom> Boom;
	//boom b;
	Enemy2 e;
	vector<Enemy2> vector_enemy2;
}; 