#include"map.h"
#include"GameObject.h"
Map* Map::Map_Instance = nullptr;
void Map::Map_get(int x, int y)
{
	if(x!=-1) this->x = x;
	if( y!=-1) this->y = y;
}
void Map::Map_update(int p_x,int p_y)
{
	
		
}
void Map::Map_draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawmap(m_textureID, x, y,
		width, height, pRenderer);
}
pair<int, int> Map::get()
{
	return make_pair(x, y);
}