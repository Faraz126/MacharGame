#include "TrashCan.h"

TrashCan::TrashCan(int x, int y): Container(x,y,CAN_WIDTH, CAN_HEIGHT)
{
    spriteNum = 41;
}



void TrashCan::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}

TrashCan::~TrashCan()
{
    //dtor
}

Mosquito* TrashCan::Breed()
{

}
