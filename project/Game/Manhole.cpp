#include "Manhole.h"

Manhole::Manhole(int x, int y) : Container(x, y, MANHOLE_WIDTH, MANHOLE_HEIGHT)
{
    spriteNum = 62; //need to replace with updated spritesheet.
}

void Manhole::SetCovered(bool status)
{
    //need to replace.
    Container::SetCovered(status);
}

void Manhole::Show(SDL_Renderer* renderer)
{
    if (!GetCovered())
    {
        Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    }

}

Mosquito* Manhole::Breed()
{
    factory->GetMosquito(0);
}


Manhole::~Manhole()
{

}
