#include "Showpiece.h"
#include "Texture.h"
#include <random>

Showpiece::Showpiece()
{
    spriteNum = (rand()%3)+24;
}

void Showpiece::SetPos(int x, int y)
{
    pos.x = x;
    pos.y = y;

    if (spriteNum == 24)
    {
        pos.w = 225;
        pos.h = 92;
    }
    else if (spriteNum == 25)
    {
        pos.w = 262;
        pos.h = 104;
    }
    else if (spriteNum == 26)
    {
        pos.w = 91*0.7;
        pos.h = 145*0.7;
    }
}

void Showpiece::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &pos);
}
