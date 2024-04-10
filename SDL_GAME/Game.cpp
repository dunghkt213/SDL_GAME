#include"Game.h"
#include<vector>
Game* Game::Game_Instance = nullptr;
//void Game::draw()
//{
//	for (std::vector<GameObject*>::size_type i = 0; i !=m_gameObjects.size(); i++)
//	{
//		m_gameObjects[i]->draw(m_pRenderer);
//	}
//	m_gameObjects.clear();
//}
SDL_Renderer* Game::get_render()
{
	return m_pRenderer;
}
void Game:: push(SDL_Texture* texture)
{
	m_gameObjects.push_back(texture);
}
bool Game::init(const char* title, int xpos, int ypos, int width,
	int height, int flags)
{
	// attempt to initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL init success\n";
		// init the window
		m_pWindow = SDL_CreateWindow(title, xpos, ypos,
			width, height, flags);
		if (m_pWindow != 0) // window init success
		{
			std::cout << "window creation success\n";
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, SDL_RENDERER_ACCELERATED |
				SDL_RENDERER_PRESENTVSYNC);
			if (m_pRenderer != 0) // renderer init success
			{
				std::cout << "renderer creation success\n";
				//SDL_SetRenderDrawC/*olor(m_pRenderer,
				//	255, 255, 255, 255);*/
			}
			else
			{
				std::cout << "renderer init fail\n";
				return false; // renderer init fail
			}
		}
		else
		{
			std::cout << "window init fail\n";
			return false; // window init fail
		}
	}
	else
	{
		std::cout << "SDL init fail\n";
		return false; // SDL init fail
	}
	//if (!TextureManager::Instance()->load("assets/animate.png",
	//	"animate", m_pRenderer))
	//{
	//	return false;
	//}
	if (!TextureManager::Instance()->load("assets/map.png", "map", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/player.png", "player", m_pRenderer))
	{
		return false;
	}
	std::cout << "init success\n";
	m_bRunning = true;
	return true;
}
void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else
		{
			Player::Instance()->HandelInput(event, m_pRenderer);
		}
	}
	
}
void Game::update()
{
}
void Game::render()
{
	
	SDL_RenderClear(m_pRenderer); // clear to the draw colour
	// loop through our objects and draw them
	Map:: Instance()->Map_draw(m_pRenderer);
	Player::Instance()->move();
	Player::Instance()-> draw(m_pRenderer);
	//for (std::vector<GameObject*>::size_type i = 0; i !=
	//	m_gameObjects.size(); i++)
	//{
	//	m_gameObjects[i]->draw(m_pRenderer);
	//}
	SDL_RenderPresent(m_pRenderer); // draw to the screen

}
void Game::clean()
{
	std::cout << "cleaning game\n";
	m_bRunning = 0;
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}
void Game::waitUntilKeyPressed()
{
	SDL_Event e;
	while (true) {
		if (SDL_PollEvent(&e) != 0 &&
			(e.type == SDL_KEYDOWN || e.type == SDL_QUIT))
		{
			clean();
			return;
		}
		SDL_Delay(16);
	}
}