#include "TrashCan.h"

TrashCan::TrashCan(int x, int y): Container(x,y,CAN_WIDTH, CAN_HEIGHT)
{
    spriteNum = 65;
    lid = new TrashCanLid(pos.x, pos.y + 100); //creating trash can lid at the given point
}


void TrashCan::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x-6,pos.y-14); //set to right ahead of trashcan.
    }
    Container::SetCovered(status);
}


void TrashCan::EventHandle(SDL_Event* e)
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


void TrashCan::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);
}

TrashCan::~TrashCan()
{
    //dtor
}

Mosquito* TrashCan::Breed()
{

}

