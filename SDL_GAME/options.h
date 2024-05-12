#pragma once
#include<SDL.h>
class options
{
private:
	bool reset = 0;
	bool pause = 0;
	static options* options_Instance;
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool poster = 1;
	bool game_over = 0;
	int player = 1 ;
public:
	static options* Instance()
	{
		if (options_Instance == 0)
		{
			options_Instance = new options();
			return options_Instance;
		}
		return options_Instance;
	}
	int check_player()
	{
		return player;
	}
	bool check_game_over()
	{
		return game_over;
	}
	bool check_reset()
	{
		return reset;
	}
	bool check_pause()
	{
		return pause;
	}
	bool check_poster()
	{
		return poster;
	}
	void get_reset(int x)
	{
		this->reset = x;
	}
	void get_poster(int x)
	{
		this->poster = x;
	}
	void get_pause(int x)
	{
		this->pause = x;
	}
	void get_game_over(int x)
	{
		this->game_over = x;
	}
	void get_window(SDL_Window* Window)
	{
		this->m_pWindow = Window;
	}
	void get_player(int player)
	{
		this->player = player;
	}
	void get_renderer(SDL_Renderer* Renderer)
	{
		this->m_pRenderer = Renderer;
	}
	SDL_Window* window()
	{
		return m_pWindow;
	}
	SDL_Renderer* Renderer()
	{
		return m_pRenderer;
	}
};