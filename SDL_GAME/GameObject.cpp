#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"
#define SPEED_PLAYER (int)7
#define WALK_UP 1;
#define WALK_RIGHT 2;
#define WALK_DOWN 3;
#define WALK_LEFT 4;
#define DIE 5;
#define ATTACK 6;
#define WALK_STOP 7;
#define SPEED_ENEMY (int)3;
Player* Player::Player_Instance = nullptr;
Player2* Player2::Player2_Instance = nullptr;
void GameObject::draw(SDL_Renderer* pRenderer)
{
	TextureManager::Instance()->drawFrame(m_textureID, m_x, m_y,
		m_width, m_height, m_currentRow, m_currentFrame, pRenderer);
	//cout << TextureManager::Instance()<<"GameObject\n";
	//TextureManager::Instance()->draw(m_textureID, m_x, m_y,
	//	m_width, m_height, pRenderer);
}
void GameObject::update()
{
	m_x += 1;
}
void GameObject::load(int x, int y, int width, int height, std::string textureID)
{
	m_x = x;
	m_y = y;
	m_width = width;
	m_height = height;
	m_textureID = textureID;
	m_currentRow = 0;
	m_currentFrame =0 ;
	cout << m_textureID << "Gameobject\n";
}
void Player::get(int x,int y)
{
    this->p_x += x;
    this->p_y += y;
    this->p_x = max(5, p_x);
    this->p_y = max(5, p_y);
    this->p_x = min(685, p_x);
    this->p_y = min(485, p_y);
}
void Player:: resert()
{
    input_status.move_right = 0;
    input_status.move_left = 0;
    input_status.move_up = 0;
    input_status.move_down = 0;
}

 void Player:: move()
{
    int x = 0, y = 0;
    //cout << "nguoi"<<p_x << " " <<p_y << "\n";
    resert();
    if (input_status.right == 1)
    {
         Fame.move_right++;
        x += SPEED_PLAYER;
    }
    if (input_status.left == 1)
    {
         Fame.move_right++;
        x -= SPEED_PLAYER;
    }
    if (input_status.up == 1)
    {
         Fame.move_up++;
        y -= SPEED_PLAYER;
    }
    if (input_status.down == 1)
    {
         Fame.move_down++;
        y += SPEED_PLAYER;
    }
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
   
    if (p_x + x > 0 && p_x + x < 1900)
    {
        p_x += x;
    }
    else x = 0;
    if (p_y + y > 0 && p_y + y < 970)
    {
        p_y += y;
    }
    else y = 0;
    if ((x>0 && p_x - map_x >= 500)|| (p_y-map_y>=350 && y >0) || ( x< 0 && p_x - map_x <= 100) || (y <0 && p_y - map_y <= 100)) 
    {
        if (map_x + x >= 0 &&  map_x+x<2000-750 ) 
        {
            Map::Instance()->Map_get(map_x+x,-1);
        }
        if ( map_y + y >= 0 &&  map_y + y < 1080 - 550)
        {
            Map::Instance()->Map_get(-1, map_y + y);
        }
    }
    //if ((p_x+x>700- 150 && input_status.right==1)|| (p_x+x<150 && input_status.left==1) 
    //    || (p_y+y>500-150 && input_status.down) ||p_y+y<150 && input_status.up==1)
    //{
    //   
    //    Map::Instance()->Map_update(x, y);
    //}
    //else
    //{
    //    p_y += y; p_x += x;
    //}
    
    //cout << p_x << " " << p_y << '\n';
    Fame.check();
}
 void Player :: reset()
 {
    Player_Instance = nullptr;
 }
void Player::HandelInput(SDL_Event events, SDL_Renderer* screen)
{
    //if (hp <= 0)
    //{
    //    check_die = 1;
    //}
    if (die != 1 && input_status.attack != 1)
    {

        if (events.type == SDL_KEYDOWN)
        {
            input_status.resert();
            switch (events.key.keysym.sym)
            {
            case SDLK_RIGHT:
            {
                input_status.right = 1;
                status = WALK_RIGHT;
                Fame.fame = 2;
            }
            break;

            case SDLK_LEFT:
            {
                input_status.left = 1;
                status = WALK_LEFT;
                Fame.fame = 2;
            }
            break;

            case SDLK_UP:
            {
                input_status.up = 1;
                status = WALK_UP;
                Fame.fame = 2;
            }
            break;

            case SDLK_DOWN:
            {
                input_status.down = 1;
                status = WALK_DOWN;
                Fame.fame = 2;
            }
            break;

            case SDLK_SPACE:
            {

                if (input_status.attack == 0)
                {
                    input_status.attack = 1;
                    Fame.move_attack = 0;
                    Fame.fame = 3;
                }
            }
            break;
            case SDLK_z:
            {
                intput_skill = 1;
            }
            break;
            }

            //cout << "down\n";
            //cout << "input_status.down" << " " << input_status.down << '\n';
            //cout << "input_status.up" << " " << input_status.up << '\n';
            //cout << "input_status.right" << " " << input_status.right << '\n';
            //cout << "input_status.left" << " " << input_status.left << '\n';
            //cout << "input_status.left" << " " << input_status.attack << '\n';
            //cout << "status" << " " << status << "\n";

        }
    }
    if (events.type == SDL_KEYUP)
    {
        switch (events.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            input_status.right = 0;
            input_status.direction = false;
        }
        break;

        case SDLK_LEFT:
        {
            input_status.left = 0;
            input_status.direction = true;
        }
        break;

        case SDLK_UP:
        {
            input_status.up= 0;
        }
        break;

        case SDLK_DOWN:
        {
            input_status.down = 0;
        }
        break;

        case SDLK_z:
        {
            intput_skill = 0;
        }
        break;

        default:
            break;
        }
    //cout << "up\n";
    //cout << "input_status.down" << " " << input_status.down << '\n';
    //cout << "input_status.up" << " " << input_status.up << '\n';
    //cout << "input_status.right" << " " << input_status.right << '\n';
    //cout << "input_status.left" << " " << input_status.left << '\n';
    //cout << "status" << " " << status << "\n";

    }
            
}
void Player::skill()
{
    //if (status == 1)
    //{
    //    int x = p_x;
    //    int y = p_y;
    //    for (int i = 0; i < 4; i++)
    //    {
    //        boom b;
    //        b.get_xy(x-12, y - 40 - 60 * i,i);
    //        Game::Instance()->get_Boom(b);

    //    }
    //}
    if (status == 1)
    {
        int x = p_x;
        int y = p_y;
        for (int i = 0; i < 5; i++)
        {
            boom b;
            b.get_xy(x - 12, y - 40 - 60 * i, i);
            vector_boom.push_back(b);
        }
    }
    else if (status == 2)
    {
        int x = p_x;
        int y = p_y;
        for (int i = 0; i < 5; i++)
        {
            boom b;
            b.get_xy(x + 12 + 40 +60*i, y, i);
            vector_boom.push_back(b);
        }

    }
    else if (status == 4)
    {
        int x = p_x;
        int y = p_y;
        for (int i = 0; i < 5; i++)
        {
            boom b;
            b.get_xy(x - 12 -40 -60*i, y, i);
            vector_boom.push_back(b);
        }

    }
    else if (status = 3)
    {
        int x = p_x;
        int y = p_y;
        for (int i = 0; i < 5; i++)
        {
            boom b;
            b.get_xy(x - 12, y + 40 + 60 * i, i);
            vector_boom.push_back(b);
        }
    }
}
void Player::draw(SDL_Renderer* pRenderer)
{
    for (int i = 0; i < vector_boom.size(); i++)
    {
	    //Game::Instance()->get_vector_boom()[i].plus_fame();
	    vector_boom[i].check_delay();
        vector_boom[i].run(pRenderer);
	    if (vector_boom[i].check_done() == 1)
	    {
		    vector_boom.erase(vector_boom.begin() + i);
	    }
    }
    if (intput_skill == 1)
    {
        skill();
        intput_skill = 0;
    }
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die == 1)
    {
        TextureManager::Instance()->draw_player("player", p_x-map_x, p_y- map_y, 16 + 49 * Fame.die, 456, 22, 19, 46, 48, pRenderer, SDL_FLIP_NONE);
        SDL_Delay(50);
        if (Fame.die < 2) Fame.die++;
        else options::Instance()->get_game_over(1);
    }
    else 
    if (input_status.attack == 1)
    {
        int srcx = 46 * Fame.move_attack;
        //if (Fame.move_attack == 2) skill();
        int srcy = 336;
        if (status == 2)
        {
            SDL_Rect rect;
            rect.x = p_x + 15;
            rect.y = p_y + 30;
            rect.w = 40;
            rect.h = 20;
            if (check_hitbox == 0) Game::Instance()->get_hitbox({ rect,1 });
            check_hitbox = 1;
            srcy = 336;
        }
        else if (status == 4)
        {
            SDL_Rect rect;
            rect.x = p_x - 25;
            rect.y = p_y + 30;
            rect.w = 40;
            rect.h = 25;
            if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
            check_hitbox = 1;
            srcy = 336;
        }
        else if (status == 3)
        {
            SDL_Rect rect;
            rect.x = p_x;
            rect.y = p_y + 30;
            rect.w = 40;
            rect.h = 30;
            //SDL_RenderDrawRect(pRenderer, &rect);
            if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
            check_hitbox = 1;
            srcy = 288;
        }
        else if (status == 1)
        {
            SDL_Rect rect;
            rect.x = p_x + 5;
            rect.y = p_y + 5;
            rect.w = 20;
            rect.h = 20;
            if(check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
            check_hitbox = 1;
            srcy = 384;
        }
        if (delay_attack == 0) Fame.move_attack++;
        if (Fame.move_attack >=2 )
        {
            Fame.move_attack = 1;
            check_hitbox = 0;
            input_status.attack = 0;
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x - 40, p_y - map_y - 40, srcx, srcy, 46, 48,100,100, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x - 40, p_y - map_y - 40, srcx, srcy, 46, 48, 100,100, pRenderer, SDL_FLIP_NONE);
        }
    }
    else
    {
        if (status == 0)
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_stop, 19, 18, 23, 35, 50, pRenderer, SDL_FLIP_NONE);
            if(delay==0) Fame.move_stop++;
        }
        else if (status == 2)
        {

            TextureManager::Instance()->draw_player("player", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_right, move_right , player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_NONE);

        }
        else if (status == 4)
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_right, move_right, player_width, player_height,  dr_width, dr_height, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else if (status == 3)
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_down, move_down, player_width, player_height,  dr_width, dr_height,pRenderer, SDL_FLIP_NONE);
        }
        else if (status == 1)
        {
            TextureManager::Instance()->draw_player("player", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_up, move_up, player_width, player_height,  dr_width, dr_height, pRenderer, SDL_FLIP_NONE);
        }
        Fame.check();
    }

    //if (Game::Instance()->get_vector_boom().size() > 0 && Game::Instance()->get_vector_boom()[0].check_done() != 1)
    //{
    //    Game::Instance()->get_vector_boom()[0].check_delay();
    //    Game::Instance()->get_vector_boom()[0].run(pRenderer);
    //}
}
void Player::check_being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer)
{
    for (pair<SDL_Rect, int> u : v)
    {
        SDL_Rect rect = u.first;
        if (u.second !=2) continue;
        rect.x = rect.x - Map::Instance()->get().first;
        rect.y = rect.y - Map::Instance()->get().second;
        //SDL_RenderDrawRect(pRenderer, &rect);
        SDL_Rect r2;
        int x_hitbox = u.first.x;
        int y_hitbox = u.first.y;
        int w_hitbox = u.first.w;
        int h_hitbox = u.first.h;
        int x = p_x ;
        int y = p_y + 10;
        int w = p_w - 10;
        int h = p_h - 10;
        r2.x = x - Map::Instance()->get().first;
        r2.y = y - Map::Instance()->get().second;
        r2.w = w - 10;
        r2.h = h;
        //SDL_RenderDrawRect(pRenderer, &r2);
        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
        if (y_hitbox <= y && y <= y_hitbox + h_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
            {
                being_attack = 1;
                hp -= 1;
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }
        if (y_hitbox >= y && y + h >= y_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
            {
                being_attack = 1;
                hp -= 1;
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }
        
    }
}
void Enemy::move()
{
    if (attack != 1 && being_attack!=1 && die!=1 && Player::Instance()->check_die() == 0)
    {
        int p_x = Player::Instance()->getxy().first;
        int p_y = Player::Instance()->getxy().second;
        if (p_y == e_y && abs(p_x - e_x) <= 22)
        {
            attack = 1;
            if (p_x > e_x)
            {
                status = 2;
            }
            else
            {
                status = 4;
            }
        }
        else
        {
            if (abs(p_y - e_y) <= 1000 && abs(p_x - e_x) <= 1000)
            {
                if (p_y > e_y)
                {
                    e_y += min((int)abs(p_y - e_y), 3);
                }
                if (p_y < e_y)
                {
                    e_y -= min((int)abs(p_y - e_y), 3);
                }
                if (p_x - 20 > e_x)
                {
                    e_x += min((int)abs(p_x - 20 - (e_x)), 3);
                    status = 2;
                    last_status = 2;
                }
                if (p_x + 20 < e_x)
                {
                    e_x -= min((int)abs(p_x + 20 - e_x), 3);
                    status = 4;
                    last_status = 4;
                }
            }
            else
            {
                status = 0;
            }
        }

    }
   

}
void Enemy::check_being_attack(vector<pair<SDL_Rect, int>> v,SDL_Renderer* pRenderer)
{
    for (pair<SDL_Rect, int> u  : v)
    {
        SDL_Rect rect = u.first;
        if (u.second != 1) continue;
        rect.x = rect.x - Map::Instance()->get().first;
        rect.y = rect.y - Map::Instance()->get().second;
        //SDL_RenderDrawRect(pRenderer, &rect);
        SDL_Rect r2;
        int x_hitbox = u.first.x;
        int y_hitbox = u.first.y;
        int w_hitbox = u.first.w;
        int h_hitbox = u.first.h;
        int x = e_x+25;
        int y = e_y + 10;
        int w = e_w - 10;
        int h = e_h-10;
        r2.x = x- Map::Instance()->get().first;
        r2.y = y+10 - Map::Instance()->get().second;
        r2.w = w-10;
        r2.h = h;
        //SDL_RenderDrawRect(pRenderer, &r2);
        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
        if (y_hitbox <= y && y <= y_hitbox + h_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
            {
                being_attack = 1;
                hp -= 20;
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }
        if (y_hitbox >= y && y + h >= y_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox<=x && x_hitbox+w_hitbox>=x))
            {
                being_attack = 1;
                hp -= 20;
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }


    }
}
void Enemy::draw(SDL_Renderer* pRenderer)
{
    
    int p_x = Player::Instance()->getxy().first;
    int p_y = Player::Instance()->getxy().second;
    //cout << attack << " " << Fame.move_attack << " ";
    //cout << p_x << " " << p_y <<" "<<e_x<<" "<<e_y<<"\n";
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die == 1)
    {
        if (status == 2)
        {
            TextureManager::Instance()->draw_player("enemy", e_x - map_x+5 , e_y - map_y+10, 21 + Fame.move_die * 61, 287,
                30, 25, 50, 50, pRenderer, SDL_FLIP_NONE);
        }
        else
        {
            TextureManager::Instance()->draw_player("enemy", e_x - map_x+5, e_y - map_y+10, 21 + Fame.move_die * 61, 287,
                30, 25, 50, 50, pRenderer, SDL_FLIP_HORIZONTAL);

        }
        if (delay == 0)
        {
            Fame.move_die++;
            if (Fame.move_die >= 5)
            {
     
                Fame.move_die--;
                time_die--;
            }
        }
    }
    else if (being_attack == 1)
        {
            
            if (Fame.move_being_attack == 1)
            {
                if (Player::Instance()->getxy().first>e_x)e_x -= 3;
                else e_x += 3;
            }
            if (Player::Instance()->getxy().first > e_x)
            {

                TextureManager::Instance()->draw_player("enemy", e_x - map_x + 5, e_y - map_y, 21 + Fame.move_being_attack * 65, 222,
                    28, 26, 50, 50, pRenderer, SDL_FLIP_NONE);
            }
            else
            {
                TextureManager::Instance()->draw_player("enemy", e_x - map_x + 5, e_y - map_y, 21 + Fame.move_being_attack * 65, 222,
                    28, 26, 50, 50, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            if(delay == 0 ) Fame.move_being_attack++;
            if (Fame.move_being_attack == 3)
            {
                Fame.move_being_attack = 0;
                being_attack = 0;
                move_attack = 0;
            }

        }
        else if (attack == 1)
        {
            int srcx = 13 + move_attack * 65;
            int srcy = 152;
            if (delay == 0) move_attack++;
            if (move_attack >= 5)
            {
                move_attack = 0;
                attack = 0;
                check_hitbox = 0;
            }
            if (status == 0)
            {
                if (Player::Instance()->getxy().first < e_x)
                {
                    status = 4;
                }
                else status = 2;
            }
            if (status == 4)
            {
                SDL_Rect rect;
                rect.x = e_x ;
                rect.y = e_y + 20;
                rect.w = 30;
                rect.h = 20;
                
               
                if (check_hitbox == 0 && move_attack == 4)
                {
                    Game::Instance()->get_hitbox({ rect,2 });
                    check_hitbox = 1;
                }
                //rect.x = e_x -map_x;
                //rect.y = e_y + 20 -map_y;
     
                //SDL_RenderDrawRect(pRenderer, &rect);
                TextureManager::Instance()->draw_player("enemy", e_x - map_x-4, e_y-map_y - 13, srcx, srcy,
                    40, 40, 80, 80, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            else
            {
                SDL_Rect rect;
                rect.x = e_x+35;
                rect.y = e_y+20 ;
                rect.w = 45;
                rect.h = 20;
                if (check_hitbox == 0 && move_attack == 4)
                {
                    Game::Instance()->get_hitbox({ rect,2 });
                    check_hitbox = 1;
                }
                //rect.x = e_x+45-map_x;
                //rect.y = e_y+20-map_y;
 
                //SDL_RenderDrawRect(pRenderer, &rect);
                TextureManager::Instance()->draw_player("enemy", e_x - map_x, e_y - map_y - 13, srcx, srcy,
                    40, 40, 80, 80, pRenderer, SDL_FLIP_NONE);
            }
        }
        else
        {
            if (status == 2)
            {
                TextureManager::Instance()->draw_player("enemy", e_x - map_x, e_y - map_y + 5, 21 + Fame.move_right * 65, 97,
                    40, 40, 80, 80, pRenderer, SDL_FLIP_NONE);
                if(delay == 0) Fame.move_right++;
            }
            if (status == 4)
            {
                TextureManager::Instance()->draw_player("enemy", e_x - map_x, e_y - map_y + 5, 21 + Fame.move_left * 65, 97,
                    40, 40, 80, 80, pRenderer, SDL_FLIP_HORIZONTAL);
                if (delay == 0) Fame.move_left++;
            }
            if (status == 0)
            {
                if (last_status == 4)
                {
                    TextureManager::Instance()->draw_player("enemy", e_x - map_x+10, e_y - map_y + 4, 21 + Fame.move_stop * 65, 35,
                        20, 19, 40, 40, pRenderer, SDL_FLIP_HORIZONTAL);
                }
                else TextureManager::Instance()->draw_player("enemy", e_x - map_x, e_y - map_y + 5, 21 + Fame.move_stop * 65, 35,
                    20, 19, 40, 40, pRenderer, SDL_FLIP_NONE);
                if (delay == 0) Fame.move_stop++;
            }
            Fame.check();
        }
  
}
void Enemy:: set_delay()
{
    if (delay <= 0)
    {
        delay = 4;
    }
    delay--;
    
}
void Enemy :: spawn()
{
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (rand() % 2 == 0)
    {
        this-> e_x = map_x + 700 + rand()%6;
        this-> e_y = map_y + rand() % 500;
    }
    else  
    {
        this->e_x = map_x -30 ;
        this->e_y = map_y + rand() % 500;
    }
    
}
void enemy_house::draw(SDL_Renderer* pRenderer)
{
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die ==0 ) TextureManager::Instance()->draw_player(status, x - map_x+8, y - map_y-10, 0, 0,
        205, 39, 50, 15, pRenderer, SDL_FLIP_NONE);
    if (die == 0) TextureManager::Instance()->draw_player("Enemy_house", x - map_x, y - map_y ,5 , 23,
        src_w, src_h, w, h, pRenderer, SDL_FLIP_NONE);
    else TextureManager::Instance()->draw_player("Enemy_house_destroy", x - map_x, y - map_y, 5, 23,
        src_w, src_h, w, h, pRenderer, SDL_FLIP_NONE);
}
void enemy_house::check_being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer)
{
    for (pair<SDL_Rect, int> u : v)
    {
        SDL_Rect rect = u.first;
        if (u.second != 1) continue;
        rect.x = rect.x - Map::Instance()->get().first;
        rect.y = rect.y - Map::Instance()->get().second;
        //SDL_RenderDrawRect(pRenderer, &rect);
        SDL_Rect r2;
        int x_hitbox = u.first.x;
        int y_hitbox = u.first.y;
        int w_hitbox = u.first.w;
        int h_hitbox = u.first.h;
        int e_w = w-24;
        int e_h = h - 20;
        int e_y = y + 10;
        int e_x = x+13;
        r2.x = e_x - Map::Instance()->get().first;
        r2.y = e_y - Map::Instance()->get().second;
        r2.w = e_w ;
        r2.h = e_h;
        //SDL_RenderDrawRect(pRenderer, &r2);
        bool check = 0;
        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
        if (y_hitbox <= e_y && e_y <= y_hitbox + h_hitbox)
        {
            if ((e_x + e_w >= x_hitbox && e_x <= x_hitbox) || (x_hitbox <= e_x && x_hitbox + w_hitbox >= e_x))
            {           
                hp -= 1;
                check = 1;
                if (hp == 1) status = "1_5_blood";
                if (hp == 2) status = "2_5_blood";
                if (hp == 3) status = "3_5_blood";
                if (hp == 4) status = "4_5_blood";
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }
        if (y_hitbox >= e_y && e_y + e_h >= y_hitbox && check == 0)
        {
                if ((e_x + e_w >= x_hitbox && e_x <= x_hitbox) || (x_hitbox <= e_x && x_hitbox + w_hitbox >= e_x))
                {
                    hp -= 1;
                    check = 1;
                    if (hp == 1) status = "1_5_blood";
                    if (hp == 2) status = "2_5_blood";
                    if (hp == 3) status = "3_5_blood";
                    if (hp == 4) status = "4_5_blood";
                    if (hp <= 0)
                    {
                        die = 1;
                    }
                }
           }
        cout << "\n";

    }
}

//void enemy_house::being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer)
//{
//    for (pair<SDL_Rect, int> u : v)
//    {
//        SDL_Rect rect = u.first;
//        if (u.second != 1) continue;
//        rect.x = rect.x - Map::Instance()->get().first; 
//        rect.y = rect.y - Map::Instance()->get().second;
//        //SDL_RenderDrawRect(pRenderer, &rect);
//        SDL_Rect r2;
//        int x_hitbox = u.first.x;
//        int y_hitbox = u.first.y;
//        int w_hitbox = u.first.w;
//        int h_hitbox = u.first.h;
//        r2.x = x - Map::Instance()->get().first;
//        r2.y = y - Map::Instance()->get().second;
//        r2.w = w;
//        r2.h = h;
//        //SDL_RenderDrawRect(pRenderer, &r2);
//        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
//        if (y_hitbox <= y && y <= y_hitbox + h_hitbox)
//        {
//            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
//            {
//                hp -= 20;
//                if (hp <= 0)
//                {
//                    die = 1;
//                }
//            }
//        }
//        if (y_hitbox >= y && y + h >= y_hitbox)
//        {
//            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
//            {
//                hp -= 20;
//                if (hp <= 0)
//                {
//                    die = 1;
//                }
//            }
//        }
//
//
//    }
//}
void Enemy2::move()
{
    //cout << e_x << " " << e_y << "\n";
    if (attack != 1 && being_attack != 1 && die != 1)
    {
        int p_x = Player::Instance()->getxy().first;
        int p_y = Player::Instance()->getxy().second;
        if (p_y == e_y && abs(p_x - e_x) <= 22)
        {
            attack = 1;
            if (p_x > e_x)
            {
                status = 2;
            }
            else
            {
                status = 4;
            }
        }
        else
        {
            if (abs(p_y - e_y) <= 1000 && abs(p_x - e_x) <= 1000)
            {
                if (p_y > e_y)
                {
                    e_y += min((int)abs(p_y - e_y), 5);
                }
                if (p_y < e_y)
                {
                    e_y -= min((int)abs(p_y - e_y), 5);
                }
                if (p_x - 20 > e_x)
                {
                    e_x += min((int)abs(p_x - 20 - (e_x)), 5);
                    status = 2;
                    last_status = 2;
                }
                if (p_x + 20 < e_x)
                {
                    e_x -= min((int)abs(p_x + 20 - e_x), 5);
                    status = 4;
                    last_status = 4;
                }
            }
            else
            {
                status = 0;
            }
        }

    }


}
void Enemy2::draw(SDL_Renderer* pRenderer)
{

    int p_x = Player::Instance()->getxy().first;
    int p_y = Player::Instance()->getxy().second;
    //cout << attack << " " << Fame.move_attack << " ";
    //cout << p_x << " " << p_y <<" "<<e_x<<" "<<e_y<<"\n";
    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die == 1)
    {
        if (last_status == 2)
        {
            TextureManager::Instance()->draw_player("enemy2_die", e_x - map_x + 5, e_y - map_y + 10, 30 + Fame.move_die * 126, srcy,
                71, 73, 40, 40, pRenderer, SDL_FLIP_NONE);
        }
        else
        {
            TextureManager::Instance()->draw_player("enemy2_die", e_x - map_x + 5, e_y - map_y + 10, 30 + Fame.move_die * 126, srcy,
                71, 73, 40,40, pRenderer, SDL_FLIP_HORIZONTAL);

        }
        if (delay == 0)
        {
            Fame.move_die++;
            if (Fame.move_die >= 7)
            {

                if (die_time == 0)
                {
                    srcy = 175;
                    Fame.move_die = 0;
                    die_time = 1;
                    e_y = e_y + 13;
                    e_x = e_x + 7;
                }
            }
        }
    }
    else if (attack == 1)
    {
        int srcx = 44 + move_attack * 185;
        int srcy = 407;
        if (delay == 0) move_attack++;
        if (move_attack >= 5)
        {
            move_attack = 0;
            attack = 0;
            check_hitbox = 0;
        }
        if (status == 0)
        {
            if (Player::Instance()->getxy().first < e_x)
            {
                status = 4;
            }
            else status = 2;
        }
        if (status == 4)
        {
            SDL_Rect rect;
            rect.x = e_x-6;
            rect.y = e_y + 20;
            rect.w = 25;
            rect.h = 20;

            if (check_hitbox == 0 && move_attack == 3)
            {
                Game::Instance()->get_hitbox({ rect,2 });
                check_hitbox = 1;
            }
  
            TextureManager::Instance()->draw_player("enemy2", e_x - map_x - 6, e_y - map_y - 13, srcx, srcy,
                148,120, 75, 70, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            
            SDL_Rect rect;
            rect.x = e_x + 50;
            rect.y = e_y + 20;
            rect.w = 17;
            rect.h = 20;
            if (check_hitbox == 0 && move_attack == 4)
            {
                Game::Instance()->get_hitbox({ rect,2 });
                check_hitbox = 1;
            }
            TextureManager::Instance()->draw_player("enemy2", e_x - map_x-6, e_y - map_y - 13, srcx, srcy,
                148, 120, 75, 70, pRenderer, SDL_FLIP_NONE);
        }
    }
    else
    {
        if (status == 2)
        {
            TextureManager::Instance()->draw_player("enemy2", e_x - map_x, e_y - map_y + 5, 13 + Fame.move_right * 200, 250,
                124, 77, 60, 50, pRenderer, SDL_FLIP_NONE);
            if (delay == 0) Fame.move_right++;
            if (Fame.move_right == 5)
            {
                Fame.move_right = 1;
            }
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("enemy2", e_x - map_x, e_y - map_y + 5, 13 + Fame.move_left * 200, 250,
                124, 77, 60, 50, pRenderer, SDL_FLIP_HORIZONTAL);
            if (delay == 0) Fame.move_left++;
            if (Fame.move_left == 5)
            {
                Fame.move_left = 1;
            }
        }
        if (status == 0)
        {
            if (last_status == 4)
            {
                TextureManager::Instance()->draw_player("enemy2", e_x - map_x + 10, e_y - map_y + 4, 47 + Fame.move_stop *190, 43,
                    87, 92, 50, 50, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            else TextureManager::Instance()->draw_player("enemy2", e_x - map_x + 10, e_y - map_y + 4, 47 + Fame.move_stop * 190, 43,
                87, 92, 50, 50, pRenderer, SDL_FLIP_NONE);
            if (delay == 0) Fame.move_stop++;
        }
        Fame.check();
    }

}
void Enemy2::set_delay()
{
    if (delay <= 0)
    {
        delay = 4;
    }
    delay--;

}
void Enemy2::check_being_attack(vector<pair<SDL_Rect, int>> v,SDL_Renderer* pRenderer)
{
    for (pair<SDL_Rect, int> u  : v)
    {
        SDL_Rect rect = u.first;
        if (u.second != 1) continue;
        rect.x = rect.x - Map::Instance()->get().first;
        rect.y = rect.y - Map::Instance()->get().second;
        //SDL_RenderDrawRect(pRenderer, &rect);
        SDL_Rect r2;
        int x_hitbox = u.first.x;
        int y_hitbox = u.first.y;
        int w_hitbox = u.first.w;
        int h_hitbox = u.first.h;
        int x = e_x+25;
        int y = e_y + 10;
        int w = e_w - 10;
        int h = e_h-10;
        r2.x = x- Map::Instance()->get().first;
        r2.y = y+10 - Map::Instance()->get().second;
        r2.w = w-10;
        r2.h = h;
        //SDL_RenderDrawRect(pRenderer, &r2);
        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
        if (y_hitbox <= y && y <= y_hitbox + h_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
            {
                   die = 1;
            }
        }
        if (y_hitbox >= y && y + h >= y_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox<=x && x_hitbox+w_hitbox>=x))
            {
                   die = 1;
            }
        }


    }
}
void Player2::draw(SDL_Renderer* pRenderer)
{

    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die == 1)
    {
        TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 98 + 303 * Fame.die, 1747, 64, 42 , 46, 48, pRenderer, SDL_FLIP_NONE);
        SDL_Delay(50);
        if (Fame.die < 2) Fame.die++;
        else options::Instance()->get_game_over(1);
    }
    else
        if (input_status.attack == 1)
        {
            int srcx = 46 * Fame.move_attack;
            //if (Fame.move_attack == 2) skill();
            int srcy = 336;
            if (status == 2)
            {
                SDL_Rect rect;
                rect.x = p_x + 15;
                rect.y = p_y + 30;
                rect.w = 40;
                rect.h = 20;
                if (check_hitbox == 0) Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
                srcy = 336;
            }
            else if (status == 4)
            {
                SDL_Rect rect;
                rect.x = p_x - 25;
                rect.y = p_y + 30;
                rect.w = 40;
                rect.h = 25;
                if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
                srcy = 336;
            }
            else if (status == 3)
            {
                SDL_Rect rect;
                rect.x = p_x;
                rect.y = p_y + 30;
                rect.w = 40;
                rect.h = 30;
                //SDL_RenderDrawRect(pRenderer, &rect);
                if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
                srcy = 288;
            }
            else if (status == 1)
            {
                SDL_Rect rect;
                rect.x = p_x + 5;
                rect.y = p_y + 5;
                rect.w = 20;
                rect.h = 20;
                if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
                srcy = 384;
            }
            if (delay_attack == 0) Fame.move_attack++;
            if (Fame.move_attack >= 2)
            {
                Fame.move_attack = 1;
                check_hitbox = 0;
                input_status.attack = 0;
            }
            if (status == 4)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x - 40, p_y - map_y - 40, srcx, srcy, 46, 48, 100, 100, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            else
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x - 40, p_y - map_y - 40, srcx, srcy, 46, 48, 100, 100, pRenderer, SDL_FLIP_NONE);
            }
        }
        else
        {
            if (status == 0)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_stop, 19, 18, 23, 35, 50, pRenderer, SDL_FLIP_NONE);
                if (delay == 0) Fame.move_stop++;
            }
            else if (status == 2)
            {

                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_right, move_right, player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_NONE);

            }
            else if (status == 4)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_right, move_right, player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            else if (status == 3)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_down, move_down, player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_NONE);
            }
            else if (status == 1)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 16 + 48 * Fame.move_up, move_up, player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_NONE);
            }
            Fame.check();
        }

    //if (Game::Instance()->get_vector_boom().size() > 0 && Game::Instance()->get_vector_boom()[0].check_done() != 1)
    //{
    //    Game::Instance()->get_vector_boom()[0].check_delay();
    //    Game::Instance()->get_vector_boom()[0].run(pRenderer);
    //}
}