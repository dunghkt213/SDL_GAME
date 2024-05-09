#include"Game.h"
#include<vector>
#include"options.h"
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
	if (!TextureManager::Instance()->load("assets/p1.png", "p", m_pRenderer))
	{
		return false;
	}
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
	if (!TextureManager::Instance()->load("assets/Enemy_house.png", "Enemy_house", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/Enemy_house_destroy.png", "Enemy_house_destroy", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/0_5_blood.png", "0_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/1_5_blood.png", "1_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/2_5_blood.png", "2_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/3_5_blood.png", "3_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/4_5_blood.png", "4_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/5_5_blood.png", "5_5_blood", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/heart.png", "heart", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/no_heart.png", "no_heart", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/menu.png", "menu", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/menu_ingame.png", "menu_ingame", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/setting.png", "setting", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/text.png", "text", m_pRenderer))
	{
		return false;
	}
	enemy_house e_house;
	e_house.set_vt(589, 18);
	Enemy_house.push_back(e_house);
	e_house.set_vt(263, 609);
	Enemy_house.push_back(e_house);
	e_house.set_vt(819, 350);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1231, 336);
	Enemy_house.push_back(e_house);
	e_house.set_vt(668, 859);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1512, 676);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1764, 91);
	Enemy_house.push_back(e_house);
	//for (int i = 1; i <= 100; i++)
	//{
	//	Enemy e;
	//	//e.spawn();
	//	vector_enemy.push_back(e);
	//}
	//Enemy e2;
	//e2.set_vt(300, 200);
	//Enemy e3;
	//vector_enemy.push_back(e2);
	//vector_enemy.push_back(e3);
	//Enemy2 e;
	//vector_enemy2.push_back(e);
	options::Instance()->get_window(m_pWindow);
	options::Instance()->get_renderer(m_pRenderer);
	std::cout << "init success\n";
	m_bRunning = true;
	return true;
}
void Game::menu()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event1;
	if (y >= 40 && y <= 90 && x >= 301 && x <= 415)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 300, 40, 128, 1,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster(0);
		}
		else
			TextureManager::Instance()->draw_player("menu", 300, 40, 64, 1,
			62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}
	else if (options::Instance()->check_poster() == 1)
	{
		TextureManager::Instance()->draw_player("menu", 300, 40, 1, 1,
			62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}
	if (y >= 95 && y <= 145 && x >= 301 && x <= 415)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 300, 95, 320, 352,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
		}
		else
			TextureManager::Instance()->draw_player("menu", 300, 95, 256, 352,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}
	else if (options::Instance()->check_poster() == 1)
	{
		TextureManager::Instance()->draw_player("menu", 300, 95, 193, 352,
			62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}
	if (y >= 150 && y <= 200 && x >= 301 && x <= 415)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 300, 150, 128, 192,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
			m_bRunning = 0;
		}
		else
			TextureManager::Instance()->draw_player("menu", 300, 150, 64, 192,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}
	else if (options::Instance()->check_poster() == 1)
	{
		TextureManager::Instance()->draw_player("menu", 300, 150, 0, 192,
			62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
	}

}
void Game::handleEvents()
{
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		if(event.type == SDL_QUIT)
		{
			m_bRunning = false;
		}
		else
		{
			if (event.key.keysym.sym == SDLK_r)
			{
				options::Instance()->get_reset(1);
			}
			if (event.key.keysym.sym == SDLK_t)
			{
				if (options::Instance()->check_poster() == 1)
				{
					
					options::Instance()->get_poster(0);
				}
				else options::Instance()->get_poster(1);
			}
			if (event.key.keysym.sym == SDLK_p)
			{
				if (options::Instance()->check_pause() == 1)
				{

					options::Instance()->get_pause(0);
				}
				else
				{
					options::Instance()->get_pause(1);
				}
			}
			if (event.key.keysym.sym == SDLK_o)
			{
				options::Instance()->get_pause(1);
			}
			Player::Instance()->HandelInput(event, m_pRenderer);
		}
	}
	
}
void Game::menu_ingame()
{
	TextureManager::Instance()->draw_player("menu_ingame", 300, 150, 35, 31,
		120, 130, 130, 230, m_pRenderer, SDL_FLIP_NONE);
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event1;
	if (y >= 170 && y <= 210 && x >= 322 && x <= 412)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 322, 170, 576, 128,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_pause(0);
		}
		else
			TextureManager::Instance()->draw_player("menu", 322, 170, 480, 128,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("menu", 322, 170, 384, 128,
			94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	if (y >= 215 && y <= 250 && x >= 301 && x <= 391)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 322, 215, 320, 352,
				62, 30, 90, 35, m_pRenderer, SDL_FLIP_NONE);
		}
		else
			TextureManager::Instance()->draw_player("menu", 322, 215, 256, 352,
				62, 30, 90, 35, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("menu", 322, 215, 193, 352,
			62, 30, 90, 35, m_pRenderer, SDL_FLIP_NONE);
	if (y >= 255 && y <= 295 && x >= 301 && x <= 391)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 322, 255, 576, 192,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster(1);
			options::Instance()->get_pause(0);
			options::Instance()->get_reset(1);
		}
		else
			TextureManager::Instance()->draw_player("menu", 322, 255, 480, 192,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("menu", 322, 255, 384, 192,
			94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	if (y >= 300 && y <= 340 && x >= 301 && x <= 391)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			TextureManager::Instance()->draw_player("menu", 322, 300, 544,32,
				78, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_reset(1);
			options::Instance()->get_pause(0);
		}
		else
			TextureManager::Instance()->draw_player("menu", 322, 300, 464, 32,
				78, 30, 90,40, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("menu", 322, 300, 384, 32,
		78, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);

}
void Game::reset()
{
	Game_Instance = nullptr;
}
void Game::update()
{
}
void Game::render()
{
	if (options::Instance()->check_poster() == 1)
	{
		SDL_RenderClear(m_pRenderer);
		TextureManager::Instance()->draw_player("p", 0, 0,0 ,0,
			1280, 640, 700, 500, m_pRenderer, SDL_FLIP_NONE);
		menu();
		SDL_RenderPresent(m_pRenderer);
	}
	else
	{
		if (options::Instance()->check_pause() == 0 )
		{
			if (options::Instance()->check_game_over() == 1)
			{
				TextureManager::Instance()->draw_player("text", 227, 130, 0, 241,
					73, 16, 246, 36, m_pRenderer, SDL_FLIP_NONE);
				TextureManager::Instance()->draw_player("menu_ingame", 290, 180, 35, 31,
					120, 130, 120, 130, m_pRenderer, SDL_FLIP_NONE);
				int x, y;
				SDL_GetMouseState(&x, &y);
				SDL_Event event1;
				if (y >= 200 && y <= 240 && x >= 310 && x <= 390)
				{

					if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
					{
						TextureManager::Instance()->draw_player("menu", 312, 200, 544, 32,
							78, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
						options::Instance()->get_reset(1);
						options::Instance()->get_game_over(0);
					}
					else
						TextureManager::Instance()->draw_player("menu", 312, 200, 464, 32, 
							78, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
				}
				else TextureManager::Instance()->draw_player("menu", 312, 200, 384, 32,
					78, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
				if (y >= 245 && y <= 295 && x >= 301 && x <= 391)
				{

					if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
					{
						TextureManager::Instance()->draw_player("menu", 312, 245, 576, 192,
							94, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
						options::Instance()->get_poster(1);
						options::Instance()->get_pause(0);
						options::Instance()->get_reset(1);
						options::Instance()->get_game_over(0);
					}
					else
						TextureManager::Instance()->draw_player("menu", 312, 245, 480, 192,
							94, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
				}
				else TextureManager::Instance()->draw_player("menu", 312, 245, 384, 192,
					94, 30, 80, 40, m_pRenderer, SDL_FLIP_NONE);
			}
			else
			{
				SDL_RenderClear(m_pRenderer); // clear to the draw colour
				// loop through our objects and draw them
				Game::Instance()->clear_hitbox();
				Player::Instance()->move();
				Map::Instance()->Map_draw(m_pRenderer);
				Player::Instance()->set_delay();
				Player::Instance()->set_delay_attack();
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

				for (int i = 0; i < Enemy_house.size(); i++)
				{

					if (Enemy_house[i].check_die() == 0)Enemy_house[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
					Enemy_house[i].draw(m_pRenderer);
					if (Enemy_house[i].check_delay() == 1 && Enemy_house[i].check_die() == 0)
					{
						int e_x = Enemy_house[i].get_vt().first;
						int e_y = Enemy_house[i].get_vt().second + 60;
						if (rand() % 2 == 0)
						{
							Enemy e;
							e.set_vt(e_x, e_y);
							vector_enemy.push_back(e);
						}
						else
						{
							Enemy2 e;
							e.set_vt(e_x, e_y);
							vector_enemy2.push_back(e);
						}
					}
					Enemy_house[i].run_delay();
				}

				//for (int i = 0; i < vector_enemy2.size(); i++)
				//{
				//	vector_enemy2[i].set_delay();
				//	vector_enemy2[i].move();
				//	vector_enemy2[i].draw(m_pRenderer);
				//	vector_enemy2[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
				//	if (vector_enemy2[i].check_die() == 1)
				//	{
				//		vector_enemy2.erase(vector_enemy2.begin() + i);
				//	}
				//}
				for (int i = 0; i < vector_enemy.size(); i++)
				{
					vector_enemy[i].set_delay();
					vector_enemy[i].move();
					vector_enemy[i].draw(m_pRenderer);
					vector_enemy[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
					if (vector_enemy[i].check_die() == 1)
					{
						vector_enemy.erase(vector_enemy.begin() + i);
					}
				}
				for (int i = 0; i < vector_enemy2.size(); i++)
				{
					vector_enemy2[i].set_delay();
					vector_enemy2[i].move();
					vector_enemy2[i].draw(m_pRenderer);
					vector_enemy2[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
					if (vector_enemy2[i].check_die() == 1)
					{
						vector_enemy2.erase(vector_enemy2.begin() + i);
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
				int x, y;
				SDL_GetMouseState(&x, &y);
				cout << x << " " << y << "\n";
				SDL_Event event1;
				if (y >= 5 && y <= 35 && x >= 660 && x <= 690)
				{

					if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
					{
						TextureManager::Instance()->draw_player("setting", 660, 5, 352, 32,
							30, 30, 30, 30, m_pRenderer, SDL_FLIP_NONE);
						options::Instance()->get_pause(1);
					}
					else
						TextureManager::Instance()->draw_player("setting", 660, 5, 320, 32,
							30, 30, 30, 30, m_pRenderer, SDL_FLIP_NONE);
				}
				else TextureManager::Instance()->draw_player("setting", 660, 5, 288, 32,
					30, 30, 30, 30, m_pRenderer, SDL_FLIP_NONE);
				Player::Instance()->check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
				int check_heart = Player::Instance()->get_heart();
				int hp = Player::Instance()->get_hp();
				for (int i = 0; i < Player::Instance()->get_heart(); i++)
				{
					int y = 9;
					int x = 5 + 30 * i;
					if (hp > 0) TextureManager::Instance()->draw_player("heart", x, y, 0, 0,
						45, 45, 28, 28, m_pRenderer, SDL_FLIP_NONE);
					else TextureManager::Instance()->draw_player("no_heart", x, y, 0, 0,
						45, 45, 28, 28, m_pRenderer, SDL_FLIP_NONE);
					hp--;
				}
			}
			
		}
		else
		{
			menu_ingame();
		}
		//for (std::vector<GameObject*>::size_type i = 0; i !=
		//	m_gameObjects.size(); i++)
		//{
		//	m_gameObjects[i]->draw(m_pRenderer);
		//}
		SDL_RenderPresent(m_pRenderer); // draw to the screen
	}

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
void Game::load_data()
{
	enemy_house e_house;
	e_house.set_vt(589, 18);
	Enemy_house.push_back(e_house);
	cout << "co";
	e_house.set_vt(263, 609);
	Enemy_house.push_back(e_house);
	e_house.set_vt(819, 350);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1231, 336);
	Enemy_house.push_back(e_house);
	e_house.set_vt(668, 859);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1512, 676);
	Enemy_house.push_back(e_house);
	e_house.set_vt(1764, 91);
	Enemy_house.push_back(e_house);
}