#include "Door.h"
#include <random>

Door::Door(int posx, int posy):Entrance(posx, posy, 145,188)
{
    spriteNum = (rand()%3)+10;
    isOpen = false;
}

void Door::Update(int frame)
{

}

void Door::Show(SDL_Renderer* renderer, SDL_Rect* rect)
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
    Show(renderer, &OutdoorPos);
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
