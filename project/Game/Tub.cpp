#include "Tub.h"
#include <random>

Tub::Tub(int x, int y) : Container(x, y, TUB_WIDTH, TUB_HEIGHT)
{
    spriteNum = 66 + (rand()%4); //need to replace with updated spritesheet.
    percentage = 5;
}

void Tub::SetCovered(bool status)
{
    Container::SetCovered(status);
}

void Tub::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

Mosquito* Tub::Breed()
{
    return factory->GetMosquito(0);
}

void Tub::Update(int n)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}


Tub::~Tub()
{

}

