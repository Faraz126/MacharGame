#include "DirtyWater.h"

DirtyWater::DirtyWater(int x, int y): Container(x,y, WATER_WIDTH, WATER_HEIGHT)
{
    spriteNum = rand()%4 + 27;
    SetCovered((bool)(rand()%2));

}

void DirtyWater::SetCovered(bool status)
{
    spriteNum = spriteNum + (4*(int)status);
    Container::SetCovered(status);
}

void DirtyWater::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

Mosquito* DirtyWater::Breed()
{
    return factory->GetMosquito(0);
}

DirtyWater::~DirtyWater()
{
    //dtor
}
