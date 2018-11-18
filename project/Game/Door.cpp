#include "Door.h"
#include <random>

Door::Door(int posx, int posy):Entrance(posx, posy)
{
    spriteNum = (rand()%3)+10;
    pos.w = 145;
    pos.h = 188;

}


void Door::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &pos);
}
