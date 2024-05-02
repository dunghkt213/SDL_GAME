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
void Game:: push(Enemy enemy)
{
	vector_enemy.push_back(enemy);
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
	if (!TextureManager::Instance()->load("assets/boom.png", "boom", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/player.png", "player", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/skeleton.png", "enemy", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/enemy2_die.png", "enemy2_die", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/enemy2.png", "enemy2", m_pRenderer))
	{
		return false;
	}
	Enemy e2;
	e2.set_vt(300, 200);
	Enemy e3;
	vector_enemy.push_back(e2);
	vector_enemy.push_back(e3);
	Enemy2 e;
	vector_enemy2.push_back(e);
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
	Game::Instance()->clear_hitbox();
	Player::Instance()->move();
	Map::Instance()->Map_draw(m_pRenderer);	
	Player::Instance()->set_delay();
	Player::Instance()->draw(m_pRenderer);
	//cout << Boom.size() << " boom \n";
	// 
	//for (int i = 0; i < Game::Instance()->get_vector_boom().size(); i++)
	//{
	//	cout << i << " ";
	//	//Game::Instance()->get_vector_boom()[i].plus_fame();
	//	Game::Instance()->get_vector_boom()[i].check_delay();
	//	Game::Instance()->get_vector_boom()[i].run(m_pRenderer);
	//	if (Game::Instance()->get_vector_boom()[i].check_done() == 1)
	//	{
	//		Game::Instance()->get_vector_boom().erase(Game::Instance()->get_vector_boom().begin() + i);
	//	}
	//}

	//if (Game::Instance()->get_vector_boom()[0].check_done() != 1)
	//{
	//	Game::Instance()->get_vector_boom()[0].check_delay();
	//	Game::Instance()->get_vector_boom()[0].run(m_pRenderer);
	//}
	//if (b.check_done() != 1)
	//{
	//	b.check_delay();
	//	b.run(m_pRenderer);
	//}

	
	for (int i = 0; i < vector_enemy2.size(); i++)
	{
		cout << "co";
		vector_enemy2[i].set_delay();
		vector_enemy2[i].move();
		vector_enemy2[i].draw(m_pRenderer);
		vector_enemy2[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
		if (vector_enemy2[i].check_die() == 1)
		{
			vector_enemy2.erase(vector_enemy2.begin() + i);
		}
	}
	for (int i=0;i< vector_enemy.size();i++)
	{
		vector_enemy[i].set_delay();
		vector_enemy[i].move();
		vector_enemy[i].draw(m_pRenderer);
		vector_enemy[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
		if (vector_enemy[i].check_die() == 1)
		{
			vector_enemy.erase(vector_enemy.begin()+i);
		}
	}
	//SDL_Rect rect;
	//rect.x = 200;
	//rect.y = 280;
	//rect.w = 46;
	//rect.h = 48;
	//e3.set_delay();
	//e3.move();
	//e3.draw(m_pRenderer);
	//e2.set_delay();
	//e2.move();
	//e2.draw(m_pRenderer);
	//e2.check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
	//e3.check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
	//SDL_RenderDrawRect(m_pRenderer, &rect);
	//v.push_back({ rect,1 });
	Player::Instance()->check_being_attack(v);
	
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