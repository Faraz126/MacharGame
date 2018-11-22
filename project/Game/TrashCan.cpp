#include "TrashCan.h"

TrashCan::TrashCan(int x, int y): Container(x,y,CAN_WIDTH, CAN_HEIGHT)
{
    spriteNum = 65;
}



void TrashCan::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    if (lid != 0)
    {
        lid->Show(renderer);
    }
}

TrashCan::~TrashCan()
{
    //dtor
}

Mosquito* TrashCan::Breed()
{

}


void TrashCan::SetCovered(bool status)
{
    Container::SetCovered(status);
}
