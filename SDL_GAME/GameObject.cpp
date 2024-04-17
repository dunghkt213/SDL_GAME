#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"Game.h"
#include"map.h"
#define SPEED_PLAYER (int)10;
#define WALK_UP 1;
#define WALK_RIGHT 2;
#define WALK_DOWN 3;
#define WALK_LEFT 4;
#define DIE 5;
#define ATTACK 6;
#define WALK_STOP 7;
#define SPEED_ENEMY (int)3;
Player* Player::Player_Instance = nullptr;
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
    cout << "nguoi"<<p_x << " " <<p_y << "\n";
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
    if ((p_x+x>700- 150 && input_status.right==1)|| (p_x+x<150 && input_status.left==1) 
        || (p_y+y>500-150 && input_status.down) ||p_y+y<150 && input_status.up==1)
    {
       
        Map::Instance()->Map_update(x, y);
    }
    else
    {
        p_y += y; p_x += x;
    }

    //cout << p_x << " " << p_y << '\n';
    Fame.check();
}
void Player::HandelInput(SDL_Event events, SDL_Renderer* screen)
{
    //if (hp <= 0)
    //{
    //    check_die = 1;
    //}
    if (check_die != 1 && input_status.attack != 1)
    {

        if (events.type == SDL_KEYDOWN)
        {
            input_status.resert();
            switch (events.key.keysym.sym)
            {
            case SDLK_RIGHT:
            {
                hp -= 20;
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
                input_status.attack = 1;
                Fame.move_attack = 0;
                Fame.fame = 3;
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


void Player::draw(SDL_Renderer* pRenderer)
{
    if (check_die == 1)
    {
        if (Fame.die <= 3)
        {
            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 49 * Fame.die, 456, 22, 19, 46, 48, pRenderer, SDL_FLIP_NONE);
            SDL_Delay(50);
            Fame.die++;
        }
    }
    else 
    if (input_status.attack == 1)
    {
        int srcx = 46 * Fame.move_attack;
        int srcy = 336;
         if (status == 2)
        {
            srcy = 336;
        }
        else if (status == 4)
        {
            srcy = 336;
        }
        else if (status == 3)
        {
            srcy = 288;
        }
        else if (status == 1)
        {
            srcy = 384;
        }
        if (delay == 0) Fame.move_attack++;
        if (Fame.move_attack > 2)
        {
            Fame.move_attack = 1;
            input_status.attack = 0;
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("player", p_x - 40, p_y - 40, srcx, srcy, 46, 48,100,100, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->draw_player("player", p_x - 40, p_y - 40, srcx, srcy, 46, 48, 100,100, pRenderer, SDL_FLIP_NONE);
        }
    }
    else
    {
        if (status == 0)
        {
            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 48 * Fame.move_stop, 19, 18, 23, 35, 50, pRenderer, SDL_FLIP_NONE);
            if(delay==0) Fame.move_stop++;
        }
        else if (status == 2)
        {

            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 48 * Fame.move_right, move_right , player_width, player_height, dr_width, dr_height, pRenderer, SDL_FLIP_NONE);

        }
        else if (status == 4)
        {
            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 48 * Fame.move_right, move_right, player_width, player_height,  dr_width, dr_height, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else if (status == 3)
        {
            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 48 * Fame.move_down, move_down, player_width, player_height,  dr_width, dr_height,pRenderer, SDL_FLIP_NONE);
        }
        else if (status == 1)
        {
            TextureManager::Instance()->draw_player("player", p_x, p_y, 16 + 48 * Fame.move_up, move_up, player_width, player_height,  dr_width, dr_height, pRenderer, SDL_FLIP_NONE);
        }
        Fame.check();
    }
 
}
void Enemy::move()
{
    //cout << e_x << " " << e_y << "\n";
    if (attack != 1)
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
            if (abs(p_y - e_y) <= 60 && abs(p_x - e_x) <= 80)
            {
                if (p_y > e_y)
                {
                    e_y += min((int)abs(p_y - e_y), 8);
                }
                if (p_y < e_y)
                {
                    e_y -= min((int)abs(p_y - e_y), 8);
                }
                if (p_x - 20 > e_x)
                {
                    e_x += min((int)abs(p_x - 20 - (e_x)), 8);
                    status = 2;
                }
                if (p_x + 20 < e_x)
                {
                    e_x -= min((int)abs(p_x + 20 - e_x), 8);
                    status = 4;
                }
            }
            else
            {
                status = 0;
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
    if (being_attack == 1)
    {
        TextureManager::Instance()->draw_player("enemy", e_x + 5, e_y, 21 + Fame.move_being_attack * 65, 222,
            28, 26, 50, 50, pRenderer, SDL_FLIP_NONE);
             Fame.move_being_attack++;
        if (Fame.move_being_attack == 3)
        {
            Fame.move_being_attack = 0;
            being_attack = 0;
            status = 0;
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
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("enemy", e_x, e_y - 13, srcx, srcy,
                40, 40, 80, 80, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->draw_player("enemy", e_x, e_y - 13, srcx, srcy,
                40, 40, 80, 80, pRenderer, SDL_FLIP_NONE);
        }
    }
    else
    {
        if (status == 2)
        {
            TextureManager::Instance()->draw_player("enemy", e_x, e_y + 5, 21 + Fame.move_right * 65, 97,
                40, 40, 80, 80, pRenderer, SDL_FLIP_NONE);
            if(delay == 0) Fame.move_right++;
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("enemy", e_x, e_y + 5, 21 + Fame.move_left * 65, 97,
                40, 40, 80, 80, pRenderer, SDL_FLIP_HORIZONTAL);
            if (delay == 0) Fame.move_left++;
        }
        if (status == 0)
        {
            TextureManager::Instance()->draw_player("enemy", e_x, e_y + 5, 21 + Fame.move_stop * 65, 35,
                20, 19, 40, 43, pRenderer, SDL_FLIP_NONE);
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