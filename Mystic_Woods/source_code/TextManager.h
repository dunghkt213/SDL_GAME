#pragma once
#include<iostream>
#include<map>
#include<SDL.h>
#include<SDL_image.h>
using namespace std;
class TextureManager
{
public:
	static TextureManager* Instance()
	{
		if (s_pInstance == 0)
		{
			s_pInstance = new TextureManager();
			return s_pInstance;
		}
		return s_pInstance;
	}
	void reset();
	bool load(std::string fileName, std::string
		id, SDL_Renderer* pRenderer);
	void draw(std::string id, int x, int y, int width, int
		height, SDL_Renderer* pRenderer, SDL_RendererFlip flip =
		SDL_FLIP_NONE);
	void drawFrame(std::string id, int x, int y, int width, int
		height, int currentRow, int currentFrame, SDL_Renderer*
		pRenderer, SDL_RendererFlip flip = SDL_FLIP_NONE);
	void check()
	{
		if (m_textureMap["animate"] == 0) cout << "loi texture\n";
	}
	void drawmap(std::string id, int x, int y, int
		width, int height, SDL_Renderer* pRenderer,SDL_RendererFlip flip= SDL_FLIP_NONE);
	void draw_player(std::string id, int x, int y, int srcx, int srcy,
		int width, int dr_width, int dr_height, int height, SDL_Renderer* pRenderer,
		SDL_RendererFlip flip);
private:
	
	map<std::string, SDL_Texture*> m_textureMap;
	static TextureManager* s_pInstance;

};

