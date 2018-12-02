#include "TubLid.h"

TubLid:: TubLid(int x, int y): Lids(x,y, TubLid_WIDTH, TubLid_HEIGHT)
{
    spriteNum = 131;
    ReduceSize(0.4);
}

TubLid:: ~TubLid()
{

}

void TubLid::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

