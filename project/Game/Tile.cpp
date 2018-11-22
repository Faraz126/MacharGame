#include "Tile.h"

Tile::Tile(int spriteNumber, int x, int y, std::string str, int price)
{
    this-> spriteNumber= spriteNumber;
    this-> x = x;
    this-> y = y;
    this->str = str;
    this->price =price;
}

Tile::Show()
{
   SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
   SDL_RenderDrawRect(gRenderer,);
}
