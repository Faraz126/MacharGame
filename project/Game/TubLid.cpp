#include "TubLid.h"

TubLid:: TubLid(int x, int y): Lids(x,y, TubLid_WIDTH, TubLid_HEIGHT)
{
    spriteNum = 70;
}

TubLid:: ~TubLid()
{

}

void TubLid::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

