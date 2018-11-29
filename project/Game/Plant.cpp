#include "Plant.h"

Plant::Plant(int x, int y): Container(x,y, PLANT_WIDTH, PLANT_HEIGHT)
{
    spriteNum = rand()%4 + 27; //to choose if plant is watered or not
    water = 0;
    SetCovered((bool)(rand()%2));
    percentage = 5;

        //plant image proportion with which image will be rendered

}

void Plant::SetCovered(bool status)
{
    spriteNum = spriteNum + (4*(int)status);
    if (status && water != 0)
    {
        //delete water;
        water = 0;
    }
    else
    {
        water = new CleanWater(pos.x,pos.y);
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

void Plant::Update(int)
{
    if (!GetCovered() && water != 0)
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

Plant::~Plant()
{
    //dtor
}
