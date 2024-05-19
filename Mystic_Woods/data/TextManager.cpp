#include"TextManager.h"

TextureManager* TextureManager::s_pInstance = nullptr;

void TextureManager::reset()
{
	s_pInstance = nullptr;
}
bool TextureManager::load(std::string fileName, std::string
	id, SDL_Renderer* pRenderer)
{
	SDL_Surface* pTempSurface = IMG_Load(fileName.c_str());
	if (pTempSurface == 0)
	{
		return false;
	}
	SDL_Texture* pTexture =
		SDL_CreateTextureFromSurface(pRenderer, pTempSurface);
	SDL_FreeSurface(pTempSurface);
	// everything went ok, add the texture20 to our list
	if (pTexture != 0)
	{
		m_textureMap[id] = pTexture;
		return true;
	}
	// reaching here means something went wrong
	return false;
}

void TextureManager::draw(std::string id, int x, int y, int
	width, int height, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = 0;
	srcRect.y = 0;
	srcRect.w = destRect.w =  width;
	srcRect.h = destRect.h =  height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}
void TextureManager::drawFrame(std::string id, int x, int y, int
	width, int height, int currentRow, int currentFrame, SDL_Renderer
	* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = width * currentFrame;
	srcRect.y = height * currentRow;
	srcRect.w = destRect.w = width;
	srcRect.h = destRect.h = height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}
void TextureManager::drawmap(std::string id, int x, int y, int
	width, int height, SDL_Renderer* pRenderer, SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = x;
	srcRect.y = y;
	srcRect.w = width;
	srcRect.h = height;
	destRect.w = 700;
	destRect.h = 500;
	destRect.x = 0;
	destRect.y = 0;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}
void TextureManager::draw_player(std::string id, int x, int y,int srcx,int srcy, int
	width, int height,int dr_width,int dr_height, SDL_Renderer* pRenderer,
	SDL_RendererFlip flip)
{
	SDL_Rect srcRect;
	SDL_Rect destRect;
	srcRect.x = srcx;
	srcRect.y = srcy;
	srcRect.w =  width;
	srcRect.h =  height;
	destRect.w = dr_width;
	destRect.h = dr_height;
	destRect.x = x;
	destRect.y = y;
	SDL_RenderCopyEx(pRenderer, m_textureMap[id], &srcRect,
		&destRect, 0, 0, flip);
}