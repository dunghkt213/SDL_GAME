#include"tool.h"
#include<fstream>
void tool::draw(SDL_Renderer* pRenderer)
{
    TextureManager::Instance()->draw_player("map", 1, 1, x-40, y-40, 100, 100, 100, 100, pRenderer, SDL_FLIP_NONE);
    SDL_Rect rect = { 41, 41, 20, 20 };
    SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255); // Màu tr?ng
    SDL_RenderDrawRect(pRenderer, &rect);
}

void tool::handlein(SDL_Event event)
{
    if (event.type == SDL_KEYDOWN)
    {
        switch (event.key.keysym.sym)
        {
        case SDLK_RIGHT:
        {
            x += 20;
        }
        break;

        case SDLK_LEFT:
        {
            x -= 20;
        }
        break;

        case SDLK_UP:
        {
            y -= 20;
        }
        break;

        case SDLK_DOWN:
        {
            y += 20;
        }
        break;

        case SDLK_SPACE:
        {
            for (int i = x; i <= x+20; i++)
            {
                for (int j = y; j <=y+ 20; j++)
                {
                    MAP[i][j] = 1;
                    cout << "map " << " "<<i<<" "<<j<<" "<<MAP[i][j] << "\n";
                }
            }
        }
        break;
        }
    }
}
void tool::createfile()
{
    ofstream outFile("map.out");
    for (int i = 1; i <= 2017; i++)
    {
        for (int j = 1; j <= 1080; j++)
        {
            outFile << MAP[i][j]<<" ";
            //cout << MAP[i][j] << " ";
        }
        outFile << "\n";
    }

}