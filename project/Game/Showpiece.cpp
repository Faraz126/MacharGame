#include "Showpiece.h"
#include "Texture.h"
#include <random>

Showpiece::Showpiece()
{
    spriteNum = (rand()%2) + 24;
}

void Showpiece::SetPos(int x, int y, int n)
{
    pos.x = x;
    pos.y = y;

    if (n == 24)
    {
        pos.w = 225;
        pos.h = 92;
    }
    else if (n == 25)
    {
        pos.w = 262;
        pos.h = 104;
    }
    else if (n == 26)
    {
        pos.w = 91*0.7;
        pos.h = 145*0.7;
        spriteNum = n;
    }
    else if( n == 70)
    {
        pos.w = 662;
        pos.h = 102;
        spriteNum = n;
    }


}

void Showpiece::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &pos);
}
