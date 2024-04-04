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
    if (check_die != 1 && input_status.attack != 1)
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
   
   
    if (input_status.attack == 1)
    {
    cout << "attack" << " " << Fame.move_attack << "\n";
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
        Fame.move_attack++;
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
        if (status == 2)
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

void Player::update()
{

}
void Enemy::update()
{
	m_y += 1;
	m_x += 1;
	m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
}
void Enemy::draw(SDL_Renderer* pRenderer)
{
	GameObject::draw(pRenderer);
}