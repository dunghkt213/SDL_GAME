#include"GameObject.h"
#include<SDL.h>
#include<iostream>
#include<SDL_image.h>
#include"TextManager.h"
#include"map.h"
#include"Game.h"
#include"options.h"
#include"gold.h"
void boss::draw(SDL_Renderer* pRenderer)
{
    for (int i = 0; i < skill.size(); i++)
    {
        skill[i].draw(pRenderer);
        if (skill[i].check_done() == 1)
        {
            skill.erase(skill.begin() + i);
        }

    }
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
            TextureManager::Instance()->draw_player("boss_death", e_x - map_x-50 , e_y - map_y -40, 3 + Fame.move_die * 77, 2,
                65, 66,110, 113, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->draw_player("boss_death", e_x - map_x , e_y - map_y -40, 3 + Fame.move_die * 77, 2,
                65, 66, 110, 113, pRenderer, SDL_FLIP_NONE);

        }
        if (delay == 0)
        {
            Fame.move_die++;
            if (Fame.move_die >= 7)
            {

                done = 1;
            }
        }
    }
    else if (being_attack == 1)
    {

       if (Fame.move_being_attack == 1)
        {
            if (Player::Instance()->getxy().first > e_x)e_x -= 3;
            else e_x += 3;
        }
        if (Player::Instance()->getxy().first > e_x)
        {

            TextureManager::Instance()->draw_player("boss_being_attack", e_x - map_x + 5-30, e_y - map_y-50, 6 + Fame.move_being_attack * 79, 0,
                63, 65, 110, 113, pRenderer, SDL_FLIP_HORIZONTAL);
        }
        else
        {
            TextureManager::Instance()->draw_player("boss_being_attack", e_x - map_x + 5-10, e_y - map_y-50, 6 + Fame.move_being_attack * 79, 0,
                63, 65, 110, 113, pRenderer, SDL_FLIP_NONE);
        }
        if (delay == 0) Fame.move_being_attack++;
        if (Fame.move_being_attack == 3)
        {
            Fame.move_being_attack = 0;
            being_attack = 0;
            move_attack = 0;
        }

    }
    else if (attack == 1)
    {
       
        if (delay == 0) move_attack++;
        if (move_attack >= 8)
        {
            move_attack = 0;
            attack = 0;
            check_hitbox = 0;
        }
        if (status == 4)
        {
            if (move_attack == 3 && check_hitbox==0)
            {
                check_hitbox = 1;
                boss_skill new_skill;
                new_skill.getxy(e_x, e_y, e_x - 500, e_y,4);
                skill.push_back(new_skill);
            }
            
            TextureManager::Instance()->draw_player("boss_attack",e_x - map_x , e_y - map_y - 50, move_attack * 78, 7,
                78, 61, 135, 115, pRenderer, SDL_FLIP_NONE);
        }
        else
        {
            if (move_attack == 3 && check_hitbox==0)
            {
                check_hitbox = 1;
                boss_skill new_skill;
                new_skill.getxy(e_x+20, e_y-10, e_x + 500, e_y-10,2);
                skill.push_back(new_skill);
            }
            
            TextureManager::Instance()->draw_player("boss_attack", e_x - map_x - 70, e_y - map_y - 60, move_attack* 78, 7,
                78, 61, 132, 115, pRenderer, SDL_FLIP_HORIZONTAL);
 
        }
    }
    else
    {
        if (status == 2)
        {
            TextureManager::Instance()->draw_player("boss_fly", e_x - map_x-80, e_y - map_y-60 ,1+Fame.move_left * 79, 2,
                76, 65, 132, 115, pRenderer, SDL_FLIP_HORIZONTAL);
            if (delay == 0) Fame.move_left++;
        }
        if (status == 4)
        {
            TextureManager::Instance()->draw_player("boss_fly", e_x - map_x-10, e_y - map_y-60, 1+Fame.move_left * 79, 2,
                76, 65, 132, 115, pRenderer, SDL_FLIP_NONE);
            if (delay == 0) Fame.move_left++;
        }
        if (Fame.move_left >= 4)
        {
            Fame.move_left = 0;
        }
    }
    if (delay == 0)
    {
        if (die == 1) delay = 5;
         else delay = 4;
    }
    delay--;
}
void boss::check_being_attack(vector<pair<SDL_Rect, int>> v, SDL_Renderer* pRenderer)
{
    time_being_attack--;
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
        int x ;
        int y ;
        int w ;
        int h ;
        if (status == 4)
        {
             x = e_x + 25-10;
             y = e_y + 10-40;
             w = e_w - 10;
             h = e_h - 10;
        }
        else
        {
             x = e_x + 25 - 50;
             y = e_y + 10 - 40;
             w = e_w - 10;
             h = e_h - 10;
        }
        
        r2.x = x - Map::Instance()->get().first;
        r2.y = y + 10 - Map::Instance()->get().second;
        r2.w = w - 10;
        r2.h = h;
        //SDL_RenderDrawRect(pRenderer, &r2);
        //cout << e_x << " " << e_y << " " << e_h << " " << e_w << " | " << x_hitbox << " " << y_hitbox << " " << h_hitbox << " " << w_hitbox << "\n";
        if (y_hitbox <= y && y <= y_hitbox + h_hitbox)
        {
            if ((x + w >= x_hitbox && x <= x_hitbox) || (x_hitbox <= x && x_hitbox + w_hitbox >= x))
            {
                if (time_being_attack <= 0)
                {
                    time_being_attack = 40;
                    being_attack = 1;
                    hp -= 20;
                }
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
                
                if (time_being_attack <= 0)
                {
                    time_being_attack = 40;
                    being_attack = 1;
                    hp -= 20;
                }
                if (hp <= 0)
                {
                    die = 1;
                }
            }
        }


    }
}
void boss::move()
{
    if (attack != 1 && being_attack != 1 && die != 1 && Player::Instance()->check_die() == 0)
    {
        int p_x = Player::Instance()->getxy().first;
        int p_y = Player::Instance()->getxy().second;
        if (p_y == e_y && abs(p_x - e_x) <= 200)
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
            if (abs(p_y - e_y) <= 5000 && abs(p_x - e_x) <= 5000)
            {
                if (p_y > e_y)
                {
                    e_y += min((int)abs(p_y - e_y),2);
                }
                if (p_y < e_y)
                {
                    e_y -= min((int)abs(p_y - e_y), 2);
                }
                if (p_x - 20 > e_x)
                {
                    e_x += min((int)abs(p_x - 20 - (e_x)), 2);
                    status = 2;
                    last_status = 2;
                }
                if (p_x + 20 < e_x)
                {
                    e_x -= min((int)abs(p_x + 20 - e_x), 2);
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