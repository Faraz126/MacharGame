#include"ManholeLid.h"

ManholeLid:: ManholeLid(int x, int y): Lids(x,y, MANHOLELID_WIDTH, MANHOLELID_HEIGHT)
{
    ReduceSize(0.5);
    spriteNum = 117;
}

ManholeLid:: ~ManholeLid()
{

}

void ManholeLid::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

