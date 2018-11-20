#include "Door.h"
#include <random>
Door::Door(int posx, int posy):Entrance(posx, posy)
{
    spriteNum = (rand()%3)+10;
    pos.w = 145;
    pos.h = 188;
    isOpen = false;
}

void Door::Update(SDL_Event& e, Screens_Node& node)
{

}

void Door::Show(SDL_Renderer* renderer)
{
    SDL_Rect rect;
    rect.x = pos.x;
    rect.y = pos.y;
    rect.w = 145;
    rect.h = 20;

    Texture::GetInstance()->Render(spriteNum, renderer, &pos);

    if (isOpen)
    {
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &rect);
    }
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
