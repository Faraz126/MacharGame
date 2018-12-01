#include "Manhole.h"

Manhole::Manhole(int x, int y) : Container(x, y, MANHOLE_WIDTH, MANHOLE_HEIGHT)
{
    spriteNum = 62; //need to replace with updated spritesheet.
    lid = new ManholeLid(pos.x,pos.y-100);
    percentage = 5;
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

void Manhole::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        lid->HandleEvents(e,node);
    }
    if (lid->Collides(*this))
    {
        SetCovered(true);
    }
}

Mosquito* Manhole::Breed()
{
    return factory->GetMosquito(NORMAL);
}


void Manhole::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

Manhole::~Manhole()
{

}
