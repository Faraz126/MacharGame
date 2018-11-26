#include "Door.h"
#include <random>

Door::Door(int posx, int posy):Entrance(posx, posy, 145,188)
{
    spriteNum = (rand()%3)+10;
    isOpen = false;
    rect = 0;
}

void Door::Update(int frame)
{

}

void Door::OutdoorPosCenter(int& followX, int& followY)
{
    followX = outdoorPos.x + (outdoorPos.w/2);
    followY = outdoorPos.y + (outdoorPos.h/2);
}

void Door::Show(SDL_Renderer* renderer)
{
    if (rect == 0)
    {
        rect = &pos;
    }
    SDL_Rect nrect;
    nrect.x = pos.x;
    nrect.y = pos.y;
    nrect.w = 145;
    nrect.h = 20;

    Texture::GetInstance()->Render(spriteNum, renderer, rect);

    if (isOpen)
    {
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &nrect);
    }
}


void Door::ShowOutside(SDL_Renderer* renderer)
{

    Texture::GetInstance()->Render(spriteNum, renderer, &outdoorPos);

}

void Door::ChangeState()
{
    isOpen = !isOpen;
}

bool Door::IsOpen()
{
    return isOpen;
}


Door::~Door()
{

}
