#include"Game.h"
#include<vector>
#include"sound.h"
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
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
		return 1;
	}

	// Initialize SDL_image
	if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
		std::cerr << "SDL_image could not initialize! IMG_Error: " << IMG_GetError() << std::endl;
		SDL_Quit();
		return 1;
	}
	// attempt to initialize SDL
	sound::Instance()->init();
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
	if (!TextureManager::Instance()->load("assets/player2.png", "player2", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/gold.png", "gold", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/khung.png", "khung", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ava_gold.png", "ava_gold", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/1.png", "1", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/2.png", "2", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/3.png", "3", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/4.png", "4", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/5.png", "5", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/6.png", "6", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/7.png", "7", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/8.png", "8", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/9.png", "9", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/0.png", "0", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/skill_thunder.png", "skill_thunder", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/tornado.png", "tornado", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ava_skill1.png", "ava_skill1", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ava_skill2.png", "ava_skill2", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ava_skill3.png", "ava_skill3", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/font_z.png", "font_z", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/font_x.png", "font_x", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/font_c.png", "font_c", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/font_v.png", "font_v", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill1.png", "dark_ava_skill1", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill2.png", "dark_ava_skill2", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill3.png", "dark_ava_skill3", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill1_lock.png", "dark_ava_skill1_lock", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill2_lock.png", "dark_ava_skill2_lock", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_ava_skill3_lock.png", "dark_ava_skill3_lock", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/heal.png", "heal", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_heal.png", "dark_heal", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/market.png", "market", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/disable.png", "disable", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/10_gold.png", "10_gold", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/dark_10_gold.png", "dark_10_gold", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/now_gold.png", "now_gold", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/DEATH.png", "boss_death", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/ATTACK.png", "boss_attack", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/FLYING.png", "boss_fly", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/HURT.png", "boss_being_attack", m_pRenderer))
	{
		return false;

	}
	if (!TextureManager::Instance()->load("assets/victory.png", "victory", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/easy.png", "easy", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/medium.png", "medium", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/hard.png", "hard", m_pRenderer))
	{
		return false;
	}
	if (!TextureManager::Instance()->load("assets/LEVEL.png", "level", m_pRenderer))
	{
		return false;
	}
	//sound
	sound::Instance()->loadSound("assets/attack.mp3", "attack");
	sound::Instance()->loadSound("assets/attack_enemy_house.mp3", "attack_enemy_house");
	sound::Instance()->loadSound("assets/collect_gold.mp3", "collect_gold");
	sound::Instance()->loadSound("assets/spray.mp3", "spray");
	sound::Instance()->loadSound("assets/thunder.mp3", "thunder");
	sound::Instance()->loadSound("assets/tornado.mp3", "tornado");
	sound::Instance()->loadSound("assets/unlock_skill.mp3", "unlock_skill");
	sound::Instance()->loadSound("assets/lose.mp3", "lose");
	sound::Instance()->loadSound("assets/boom.mp3", "boom");
	sound::Instance()->loadSound("assets/hurt.mp3", "hurt");
	sound::Instance()->loadSound("assets/heal.mp3", "heal");
	sound::Instance()->loadSound("assets/run.mp3", "run");
	sound::Instance()->loadSound("assets/victory.mp3", "victory");
	sound::Instance()->loadMusic("assets/music_game.wav", "music_game");
	sound::Instance()->play_music("music_game");
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
	SDL_Surface* icon = IMG_Load("assets/icon.png"); // Sử dụng dấu gạch chéo
		// Đặt icon cho cửa sổ
	cout << icon << " co \n";
	SDL_SetWindowIcon(m_pWindow, icon);
	// Giải phóng Surface icon
	SDL_FreeSurface(icon);
}
void Game:: level()
{
	SDL_RenderClear(m_pRenderer);
	TextureManager::Instance()->draw_player("p", 0, 0, 0, 0,
		1280, 640, 700, 500, m_pRenderer, SDL_FLIP_NONE);
	TextureManager::Instance()->draw_player("menu_ingame", 280, 50, 35, 30,
		120, 131, 150, 205,m_pRenderer, SDL_FLIP_NONE);
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event1;
	if (y >= 80 && y <= 120 && x >= 313 && x <= 403)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("easy", 313, 80, 134, 0,
				65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster_level(0);
			options::Instance()->get_level(-1);

		}
		else
			TextureManager::Instance()->draw_player("easy", 313, 80, 67, 0,
				67, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else
	{
		TextureManager::Instance()->draw_player("easy", 313, 80, 0, 0,
			65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}

	if (y >= 125 && y <= 165 && x >= 313 && x <= 403)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("medium", 313, 125, 134, 0,
				65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster_level(0);
			options::Instance()->get_level(0);

		}
		else
			TextureManager::Instance()->draw_player("medium", 313, 125, 67, 0,
				67, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else
	{
		TextureManager::Instance()->draw_player("medium", 313, 125, 0, 0,
			65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}

	if (y >= 170 && y <= 210 && x >= 313 && x <= 403)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("hard", 313, 170, 134, 0,
				65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster_level(0);
			options::Instance()->get_level(1);

		}
		else
			TextureManager::Instance()->draw_player("hard", 313, 170, 67, 0,
				67, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else
	{
		TextureManager::Instance()->draw_player("hard", 313, 170, 0, 0,
			65, 37, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
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
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("menu", 300, 40, 128, 1,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster_level(1);
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
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("menu", 300, 95, 320, 352,
				62, 30, 115, 50, m_pRenderer, SDL_FLIP_NONE);
			if (options::Instance()->check_music() == 1)
			{
				cout << "tat\n";
				options::Instance()->get_music(0);
				Mix_PauseMusic();
			}
			else
			{
				cout << "bat\n";
				options::Instance()->get_music(1);
				Mix_ResumeMusic();
			}
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
			sound::Instance()->play_sound("spray");
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
	while (SDL_PollEvent(&event))
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
				//cout << "p";
				if (options::Instance()->check_pause() == 1 )
				{

					options::Instance()->get_pause(0);
				}
				else if (options::Instance()->check_pause() == 0 && options::Instance()->check_game_over() == 0)
				{
					options::Instance()->get_pause(1);
				}
			}
			if (event.key.keysym.sym == SDLK_o)
			{
				options::Instance()->get_pause(1);
			}
			if (event.key.keysym.sym == SDLK_m)
			{
				if (options::Instance()->check_market() == 1)
				{

					options::Instance()->get_market(0);
				}
				else if (options::Instance()->check_market() == 0 )
				{
					options::Instance()->get_market(1);
				}
			}
			if (event.key.keysym.sym == SDLK_w)
			{
				if (options::Instance()->check_market() == 1)
				{

					options::Instance()->get_market(0);
				}
				else if (options::Instance()->check_market() == 0)
				{
					options::Instance()->get_market(1);
				}
			}
			if(options:: Instance()->check_player()==1) Player::Instance()->HandelInput(event, m_pRenderer);
			else Player2::Instance()->HandelInput(event, m_pRenderer);
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
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("menu", 322, 170, 576, 128,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_pause(0);
		}
			TextureManager::Instance()->draw_player("menu", 322, 170, 480, 128,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("menu", 322, 170, 384, 128,
			94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
	if (y >= 215 && y <= 250 && x >= 301 && x <= 391)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("menu", 322, 215, 320, 352,
				62, 30, 90, 35, m_pRenderer, SDL_FLIP_NONE);
			if (options::Instance()->check_music() == 1)
			{
				options::Instance()->get_music(0);
				Mix_PauseMusic();
			}
			else
			{
				options::Instance()->get_music(1);
				Mix_ResumeMusic();
			}
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
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("menu", 322, 255, 576, 192,
				94, 30, 90, 40, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster(1);
			options::Instance()->get_pause(0);
			Player2::Instance()->get_die(0);
			Player::Instance()->get_die(0);
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
			sound::Instance()->play_sound("spray");
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
void Game::victory_menu()
{
	if (victory == 0)
	{
		sound::Instance()->play_sound("victory");
		victory = 1;
	}
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event1;
	if (y >= 230 && y <= 290 && x >= 250 && x <= 310)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("setting", 250, 230, 64, 32,
				30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_reset(1);
			options::Instance()->get_victory(0);
		}
		else TextureManager::Instance()->draw_player("setting", 250, 230, 32, 32,
				30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("setting", 250, 230, 0, 32,
		30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);

	if (x >= 390 && x <= 450 && y >= 230 && y <= 290)
	{

		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			TextureManager::Instance()->draw_player("setting", 390, 230, 352, 0,
				30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);
			options::Instance()->get_poster(1);
			options::Instance()->get_victory(0);
		}
		else TextureManager::Instance()->draw_player("setting", 390, 230, 320, 0,
			30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);
	}
	else TextureManager::Instance()->draw_player("setting", 390, 230, 288, 0,
		30, 30, 60, 60, m_pRenderer, SDL_FLIP_NONE);

}

void Game::render()
{
	if (options::Instance()->check_poster() == 1 || options::Instance()->check_victory()==1 || options::Instance()->check_poster_level() == 1)
	{
		if (options::Instance()->check_victory()==1)
		{
			TextureManager::Instance()->draw_player("victory", 210, 130, 0, 0,
				262, 81, 280, 81, m_pRenderer, SDL_FLIP_NONE);
			victory_menu();
			SDL_RenderPresent(m_pRenderer);
			
		}
		else if (options::Instance()->check_poster_level() == 1)
		{
			level();
			SDL_RenderPresent(m_pRenderer);
		}
		else
		{
			SDL_RenderClear(m_pRenderer);
			TextureManager::Instance()->draw_player("p", 0, 0, 0, 0,
				1280, 640, 700, 500, m_pRenderer, SDL_FLIP_NONE);
			menu();
			SDL_RenderPresent(m_pRenderer);
		}
	}
	else
	{
		if (options::Instance()->check_pause() == 0 && options::Instance()->check_market() == 0)
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
						sound::Instance()->play_sound("spray");
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
						sound::Instance()->play_sound("spray");
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
				if (options::Instance()->check_player() == 1)Player::Instance()->move();
				else Player2::Instance()->move();
				Map::Instance()->Map_draw(m_pRenderer);
				if(options::Instance()->check_player() == 1) Player::Instance()->set_delay();
				else Player2::Instance()->set_delay();

				if (options::Instance()->check_player() == 1) 	Player::Instance()->set_delay_attack();
				else Player2::Instance()->set_delay_attack();
				if (options::Instance()->check_player() == 1) 	Player::Instance()->draw(m_pRenderer);
				else Player2::Instance()->draw(m_pRenderer);

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
				destroy_house = 0;
				for (int i = 0; i < Enemy_house.size(); i++)
				{
					if (Enemy_house[i].check_die() == 1) destroy_house++;
					if (Enemy_house[i].check_die() == 0)Enemy_house[i].check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
					Enemy_house[i].draw(m_pRenderer);
					if (Enemy_house[i].check_delay() == 1 && Enemy_house[i].check_die() == 0)
					{
						int e_x = Enemy_house[i].get_vt().first;
						int e_y = Enemy_house[i].get_vt().second + 60;
						if (rand() % 2 == 0)
						{
							Enemy e;
							number_gold++;
							e.get_gold(number_gold);
							e.set_vt(e_x, e_y);
							vector_enemy.push_back(e);
						}
						else
						{
							Enemy2 e;
							number_gold++;
							e.get_gold(number_gold);
							e.set_vt(e_x, e_y);
							vector_enemy2.push_back(e);
						}
					}
					Enemy_house[i].run_delay();
				}
				if (destroy_house >= 7)
				{
					Boss.move();
					Boss.draw(m_pRenderer);
					Boss.check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
					if (delay_enemy_boss == 0)
					{
						Enemy e;
						e.spawn();
						vector_enemy.push_back(e);
						Enemy2 e2;
						e2.spawn();
						vector_enemy2.push_back(e2);
					}
					if (delay_enemy_boss <= 0)
					{
						if (options::Instance()->check_level() == -1)
						{
							delay_enemy_boss = 200;
						}
						if (options::Instance()->check_level() == 0)
						{
							delay_enemy_boss = 100;
						}
						if (options::Instance()->check_level() == 1)
						{
							delay_enemy_boss = 45;
						}
					}
					delay_enemy_boss--;
					if (Boss.check_done() == 1)
					{
						options::Instance()->get_victory(1);
					}
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
				int map_x = Map::Instance()->get().first;
				int map_y = Map::Instance()->get().second;
				for (int i = 0; i < Game::Instance()->get_Gold()->size(); i++)
				{
					//cout << "ingold \n";
					std::vector<ani_Gold>* goldVector = Game::Instance()->get_Gold();
					(*goldVector)[i].draw(m_pRenderer);
					if ((*goldVector)[i].check_done() == 1)
					{
						sound::Instance()->play_sound("collect_gold");
						(*goldVector).erase((*goldVector).begin() + i);
					}
				}
				//if(ugold.check_done()!=1) ugold.draw(m_pRenderer);
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
				//cout << x << " " << y << "\n";
				SDL_Event event1;
				if (y >= 5 && y <= 35 && x >= 660 && x <= 690)
				{

					if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
					{
						sound::Instance()->play_sound("spray");
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
				if (options::Instance()->check_player() == 1) 	Player::Instance()->check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
				else Player2::Instance()->check_being_attack(Game::Instance()->hitbox(), m_pRenderer);
				int check_heart;
				if (options::Instance()->check_player() == 1) 	check_heart = Player::Instance()->get_heart();
				else check_heart = Player2::Instance()->get_heart();
				int hp;
				if (options::Instance()->check_player() == 1) 	hp=Player::Instance()->get_hp();
				else hp = Player2::Instance()->get_hp();


				TextureManager::Instance()->draw_player("khung", 3, 3, 0, 0,
					177, 183, 220, 60, m_pRenderer, SDL_FLIP_NONE);
				TextureManager::Instance()->draw_player("khung", 3, 3, 0, 0,
					177, 183, 55, 58, m_pRenderer, SDL_FLIP_NONE);
				Player::Instance()->avatar(15, 7, m_pRenderer);

				TextureManager::Instance()->draw_player("ava_gold",90 ,35, 0, 0,
					41, 46, 25, 25, m_pRenderer, SDL_FLIP_NONE);
				if (Game::Instance()->get_number_gold() > last_gold)
				{
					last_gold++;
					draw_number(86, 42, last_gold, m_pRenderer);
				}
				else if (Game::Instance()->get_number_gold() < last_gold)
					{
						last_gold--;
						draw_number(86, 42, last_gold, m_pRenderer);
					}
				else draw_number(86, 42, last_gold,m_pRenderer);
				//draw_number(86, 42, 0);
				if (options::Instance()->check_player() == 1)
				{
					for (int i = 0; i < Player::Instance()->get_heart(); i++)
					{
						int y = 9;
						int x = 63 + 30 * i;
						if (hp > 0) TextureManager::Instance()->draw_player("heart", x, y, 0, 0,
							45, 45, 24, 24, m_pRenderer, SDL_FLIP_NONE);
						else TextureManager::Instance()->draw_player("no_heart", x, y, 0, 0,
							45, 45, 24, 24, m_pRenderer, SDL_FLIP_NONE);
						hp--;
					}
				}
				else
				{
					for (int i = 0; i < Player2::Instance()->get_heart(); i++)
					{
						int y = 9;
						int x = 63 + 30 * i;
						if (hp > 0) TextureManager::Instance()->draw_player("heart", x, y, 0, 0,
							45, 45, 28, 28, m_pRenderer, SDL_FLIP_NONE);
						else TextureManager::Instance()->draw_player("no_heart", x, y, 0, 0,
							45, 45, 28, 28, m_pRenderer, SDL_FLIP_NONE);
						hp--;
					}
				}
				Player::Instance()->draw_skill(m_pRenderer);
			}
			
		}
		else
		{
			if (options::Instance()->check_pause() == 1) menu_ingame();
			else
			{
				market();
			}
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
	Mix_Quit();
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
void Game::draw_number(int x, int  y, int number,SDL_Renderer *pRenderer)
{
	if (number == 0)
	{
		x -= 9;
		TextureManager::Instance()->draw_player("0", x, y, 0, 0,
			21, 30, 11, 15, pRenderer, SDL_FLIP_NONE);
	}
	while (number > 0)
	{
		int u = number % 10;
		number=number / 10;
		string s;
		s = u + 48;
		x -= 9;
		//cout << "number" << " " << s << "\n";
		TextureManager::Instance()->draw_player(s, x, y, 0, 0,
			21, 30, 11, 15, pRenderer, SDL_FLIP_NONE);
	}

}
void Game::draw_number2(int x, int  y, int number, SDL_Renderer* pRenderer)
{
	if (number == 0)
	{
		x -= 19;
		TextureManager::Instance()->draw_player("0", x, y, 0, 0,
			21, 30, 21, 23, pRenderer, SDL_FLIP_NONE);
	}
	while (number > 0)
	{
		int u = number % 10;
		number = number / 10;
		string s;
		s = u + 48;
		x -= 19;
		//cout << "number" << " " << s << "\n";
		TextureManager::Instance()->draw_player(s, x, y, 0, 0,
			21, 30, 21, 23, pRenderer, SDL_FLIP_NONE);
	}

}
void Game::market()
{

	//cout << options::Instance()->check_market()<<"\n";
	TextureManager::Instance()->draw_player("market", 150, 150, 0,
		0, 126, 121, 400, 200, m_pRenderer, SDL_FLIP_NONE);
	TextureManager::Instance()->draw_player("now_gold", 275, 90, 0,
		0, 140, 50, 140, 50, m_pRenderer, SDL_FLIP_NONE);
	if (Game::Instance()->get_number_gold() > last_gold)
	{
		last_gold++;
		draw_number2(340, 100, last_gold, m_pRenderer);
	}
	else if (Game::Instance()->get_number_gold() < last_gold)
	{
		last_gold--;
		draw_number2(340, 100, last_gold, m_pRenderer);
	}
	else draw_number2(340, 100, last_gold, m_pRenderer);
	if (Player::Instance()->check_unlock_skill1() == 0)
	{
		TextureManager::Instance()->draw_player("dark_ava_skill1_lock", 235, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("10_gold", 235, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);
	}
	else 
	{
		TextureManager::Instance()->draw_player("ava_skill1", 235, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("dark_10_gold", 235, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);
	}
	
	if (Player::Instance()->check_unlock_skill2() == 0)
	{
		TextureManager::Instance()->draw_player("dark_ava_skill2_lock", 315, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("10_gold", 315, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);

	}
	else 
	{
		TextureManager::Instance()->draw_player("ava_skill2", 315, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("dark_10_gold", 315, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);

	}

	if (Player::Instance()->check_unlock_skill3() == 0)
	{
		TextureManager::Instance()->draw_player("dark_ava_skill3_lock", 395, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("10_gold", 395, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);
	}
	else
	{
		TextureManager::Instance()->draw_player("ava_skill3", 395, 180, 0,
			0, 51, 56, 70, 75, m_pRenderer, SDL_FLIP_NONE);
		TextureManager::Instance()->draw_player("dark_10_gold", 395, 260, 0,
			0, 70, 30, 70, 30, m_pRenderer, SDL_FLIP_NONE);
	}
	int x, y;
	SDL_GetMouseState(&x, &y);
	SDL_Event event1;
	TextureManager::Instance()->draw_player("disable", 470,170, 0,
		0, 30, 29, 30, 29, m_pRenderer, SDL_FLIP_NONE);
	if (x >= 470 && x <= 500 && y >= 170 && y <= 199)
	{
		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT)
		{
			sound::Instance()->play_sound("spray");
			options::Instance()->get_market(0);
		}
	}
	if (x >= 235 && x <= 305 && y >= 260 && y <= 290 )
	{
		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT 
			&& Game::Instance()->get_number_gold()>= 10 && Player::Instance()->check_unlock_skill1()==0)
		{
			sound::Instance()->play_sound("unlock_skill");
			Player::Instance()->Unlock_skill1();
			Game::Instance()->update_number_gold(-10);
		}
	}
	if (x >= 315 && x <= 385 && y >= 260 && y <= 290)
	{
		if (SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT 
			&& Game::Instance()->get_number_gold() >= 10 && Player::Instance()->check_unlock_skill2() == 0)
		{
			sound::Instance()->play_sound("unlock_skill");
			Player::Instance()->Unlock_skill2();
			Game::Instance()->update_number_gold(-10);
		}
	}
	if (x >= 395 && x <= 465 && y >= 260 && y <= 290)
	{
		if(SDL_PollEvent(&event1) && event1.type == SDL_MOUSEBUTTONDOWN && event1.button.button == SDL_BUTTON_LEFT 
			&& Game::Instance()->get_number_gold() >= 10 && Player::Instance()->check_unlock_skill3() == 0)
		{
			sound::Instance()->play_sound("unlock_skill");
			Player::Instance()->Unlock_skill3();
			Game::Instance()->update_number_gold(-10);
		}
	}
	

}