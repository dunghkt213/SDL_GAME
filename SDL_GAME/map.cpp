#include"map.h"
#include"GameObject.h"
Map* Map::Map_Instance = nullptr;
void Map::Map_get(int x, int y)
{
	this->x = x;
	this->y = y;
}
void Map::Map_update(int p_x,int p_y)
{
	cout << x << " " << y << "\n";
	if (x + p_x < 0 || y+p_y<0 || x+p_x>925 || y+p_y>390)
	{
		Player::Instance()->get(p_x, p_y);
	}
	else {
		x += p_x;
		y += p_y;
	}
		
}
void Map::Map_draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawmap(m_textureID, x, y,
		width, height, pRenderer);
}