#include"ManholeLid.h"

ManholeLid:: ManholeLid(int x, int y): Lids(x,y, MANHOLELID_WIDTH, MANHOLELID_HEIGHT)
{
    spriteNum = 70;
}

ManholeLid:: ~ManholeLid()
{

}

void ManholeLid::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

