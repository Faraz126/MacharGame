#include "Manhole.h"

Manhole::Manhole(int x, int y) : Container(x, y, MANHOLE_WIDTH, MANHOLE_HEIGHT)
{
    spriteNum = 62; //need to replace with updated spritesheet.
    lid = new ManholeLid(pos.x,pos.y-100);
}

void Manhole::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x-6,pos.y-14); //set to right ahead of trashcan.
    }
    Container::SetCovered(status);
}

void Manhole::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);

}

void Manhole::EventHandle(SDL_Event* e)
{
    int x = e->button.x;
    int y = e->button.y;
    if (!GetCovered())
    {
        lid->HandleEvents(e);
    }
    if (Collides(*lid))
    {
        SetCovered(true);
    }
}

Mosquito* Manhole::Breed()
{
    factory->GetMosquito(0);
}


Manhole::~Manhole()
{

}
