#include "Plant.h"

Plant::Plant(int x, int y): Container(x,y, PLANT_WIDTH, PLANT_HEIGHT)
{
    spriteNum = rand()%4 + 27;
    SetCovered((bool)(rand()%2));

}

void Plant::SetCovered(bool status)
{
    spriteNum = spriteNum + (4*(int)status);
    if (status)
    {
        delete water;
    }
    else
    {
        water = new CleanWater(0,0);
    }
    Container::SetCovered(status);
}

void Plant::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

Mosquito* Plant::Breed()
{
    return water->Breed();
}

Plant::~Plant()
{
    //dtor
}
