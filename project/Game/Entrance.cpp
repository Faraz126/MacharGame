#include "Entrance.h"
#include <random>

Entrance::Entrance(int n,int x,int y)
{
    pos.x = x;
    pos.y = y;
    if (n == 0)
    {
        spriteNum = (rand()%3)+10;
        pos.w = 145;
        pos.h = 188;
    }
    if (n == 1)
    {
        spriteNum = 13;
        pos.w = 200;
        pos.h = 110;
    }

}

void Entrance::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &pos);
}

bool Entrance::WithinEntrance(int x, int y)
{
    return x >= pos.x && y >= pos.y && x <= pos.x + pos.w && y <= pos.h + pos.y;
}
