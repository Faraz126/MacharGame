#include "Soil.h"

Soil:: Soil(int x, int y): Lids(x,y, SOIL_WIDTH, SOIL_HEIGHT)
{
    spriteNum = 73;
    ReduceSize(0.1);
}

Soil:: ~Soil()
{

}

void Soil::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}
