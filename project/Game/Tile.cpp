#include "Tile.h"

Tile::Tile(): Clickable(0,0, 200, 65)
{

}
Tile::Tile(int spriteNumber, int x, int y, std::string str, int price):Clickable(x,y,200,65)
{
    this-> spriteNumber= spriteNumber;
    this->str = str;
    this->price =price;
}

void Tile::Show(SDL_Renderer* renderer)
{
   SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
   SDL_RenderDrawRect(renderer,&pos);
}

Tile::~Tile()
{

}
