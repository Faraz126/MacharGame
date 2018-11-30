#include "Plant.h"

Plant::Plant(int x, int y): Container(x,y, PLANT_WIDTH, PLANT_HEIGHT)
{
    spriteNum = rand()%4 + 27; //to choose if plant is watered or not
    //lid = 0;

    lid = new Soil(pos.x, pos.y + 300);
    //SetCovered((bool)(rand()%2));
        //plant image proportion with which image will be rendered
    water = 0;
}

void Plant::SetCovered(bool status)
{
    if (status)
    {
        if (lid != 0)
        {
            lid->SetPosition(pos.x-6,pos.y-14);
            //lid = 0;
        }
        if (spriteNum >31)
        {
            spriteNum -= 4;
        }

    }
    else
    {
        spriteNum += 4;
    }

    Container::SetCovered(status);
}

void Plant::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        lid->HandleEvents(e,node);
    }
    if (Collides(*lid))
    {
        SetCovered(true);
    }
}

void Plant::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);
}



Mosquito* Plant::Breed()
{
    return factory->GetMosquito(0);

}

Plant::~Plant()
{
    //dtor
}
