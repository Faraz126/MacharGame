#include "Bed.h"
#include "Texture.h"

Bed::Bed()
{

}

Bed::Bed(int x, int y)
{
    pos.x = x;
    pos.y = y;
    pos.w = 153;
    pos.h = 174;
    occupied = false;
}

void Bed::Draw(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(14, renderer, &pos);
}

void Bed::SetPos(int x, int y)
{
    pos.x = x;
    pos.y = y;
    pos.w = 153;
    pos.h = 174;
}

Bed::~Bed()
{

}

