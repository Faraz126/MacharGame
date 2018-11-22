#include "CleanWater.h"

CleanWater::CleanWater(int x, int y): Container(x,y, WATER_WIDTH, WATER_HEIGHT)
{
    spriteNum = rand()%4 + 27;
    SetCovered((bool)(rand()%2));

}

void CleanWater::SetCovered(bool status)
{
    spriteNum = spriteNum + (4*(int)status);
    Container::SetCovered(status);
}

void CleanWater::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

Mosquito* CleanWater::Breed()
{
    return factory->GetMosquito(0);
}

CleanWater::~CleanWater()
{
    //dtor
}

void CleanWater::EventHandle(SDL_Event*)
{

}
