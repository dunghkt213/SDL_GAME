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
Player2* Player2::Player2_Instance = nullptr;
void Player2::draw(SDL_Renderer* pRenderer)
{

    int map_x = Map::Instance()->get().first;
    int map_y = Map::Instance()->get().second;
    if (die == 1)
    {
        TextureManager::Instance()->draw_player("player2", p_x - map_x-5, p_y - map_y, 98 + 288 * Fame.die, 1746, 100, 45, 110, 50, pRenderer, SDL_FLIP_NONE);
        SDL_Delay(70);
        if (Fame.die < 11) Fame.die++;
        else options::Instance()->get_game_over(1);
    }
    else
        if (input_status.attack == 1)
        {
            //if (Fame.move_attack == 2) skill();
            int srcy = 336;
            if (status == 4)
            {
                SDL_Rect rect;
                rect.x = p_x - 25;
                rect.y = p_y + 30;
                rect.w = 40;
                rect.h = 25;
                if (check_hitbox == 0)Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
            }
            else
            {
                SDL_Rect rect;
                rect.x = p_x + 15;
                rect.y = p_y + 30;
                rect.w = 40;
                rect.h = 20;
                if (check_hitbox == 0) Game::Instance()->get_hitbox({ rect,1 });
                check_hitbox = 1;
            }
            if (delay_attack == 0) Fame.move_attack++;
            if (Fame.move_attack >= 8)
            {
                Fame.move_attack = 1;
                check_hitbox = 0;
                input_status.attack = 0;
            }
            if (status == 4)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x -100, p_y - map_y -10,96 +288* Fame.move_attack, 702, 150, 60, 165,65, pRenderer, SDL_FLIP_HORIZONTAL);
            }
            else
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x -10 , p_y - map_y -10 , 96 + 288 * Fame.move_attack, 702,150, 60, 165, 65, pRenderer, SDL_FLIP_NONE);
            }
        }
        else
        {
            if (status == 0)
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x, p_y - map_y, 99 + 288 * Fame.move_stop, 80, 150, 60, 165, 65, pRenderer, SDL_FLIP_NONE);
                if (delay == 0) Fame.move_stop++;
            }
            else if (status == 4)
            {

                TextureManager::Instance()->draw_player("player2", p_x - map_x-10, p_y - map_y, 100 + 288 * Fame.move_right, 210, 63, 45, 65, 50, pRenderer, SDL_FLIP_HORIZONTAL);

            }
            else
            {
                TextureManager::Instance()->draw_player("player2", p_x - map_x-10, p_y - map_y, 100 + 288 * Fame.move_right, 210, 63, 45, 65, 50, pRenderer, SDL_FLIP_NONE);
            }
            Fame.check();
        }

    //if (Game::Instance()->get_vector_boom().size() > 0 && Game::Instance()->get_vector_boom()[0].check_done() != 1)
    //{
    //    Game::Instance()->get_vector_boom()[0].check_delay();
    //    Game::Instance()->get_vector_boom()[0].run(pRenderer);
    //}
}
void Player2::get(int x, int y)
{
    this->p_x += x;
    this->p_y += y;
    this->p_x = max(5, p_x);
    this->p_y = max(5, p_y);
    this->p_x = min(685, p_x);
    this->p_y = min(485, p_y);
}
void Player2::resert()
{
    input_status.move_right = 0;
    input_status.move_left = 0;
    input_status.move_up = 0;
    input_status.move_down = 0;
}

void Player2::move()
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
        Fame.move_right++;
        y -= SPEED_PLAYER;
    }
    if (input_status.down == 1)
    {
        Fame.move_right++;
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
    if ((x > 0 && p_x - map_x >= 500) || (p_y - map_y >= 350 && y > 0) || (x < 0 && p_x - map_x <= 100) || (y < 0 && p_y - map_y <= 100))
    {
        if (map_x + x >= 0 && map_x + x < 2000 - 750)
        {
            Map::Instance()->Map_get(map_x + x, -1);
        }
        if (map_y + y >= 0 && map_y + y < 1080 - 550)
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
void Player2::reset()
{
    Player2_Instance = nullptr;
}
void Player2::HandelInput(SDL_Event events, SDL_Renderer* screen)
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
                Fame.fame = 2;
            }
            break;

            case SDLK_DOWN:
            {
                input_status.down = 1;
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
            input_status.up = 0;
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
void Player2::skill()
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
            b.get_xy(x + 12 + 40 + 60 * i, y, i);
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
            b.get_xy(x - 12 - 40 - 60 * i, y, i);
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

void Player2::check_being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer)
{
    for (pair<SDL_Rect, int> u : v)
    {
        SDL_Rect rect = u.first;
        if (u.second != 2) continue;
        rect.x = rect.x - Map::Instance()->get().first;
        rect.y = rect.y - Map::Instance()->get().second;
        //SDL_RenderDrawRect(pRenderer, &rect);
        SDL_Rect r2;
        int x_hitbox = u.first.x;
        int y_hitbox = u.first.y;
        int w_hitbox = u.first.w;
        int h_hitbox = u.first.h;
        int x = p_x;
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