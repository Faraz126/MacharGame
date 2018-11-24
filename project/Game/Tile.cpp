#include "Tile.h"

Tile::Tile(): Clickable(0,0, 200, 65)
{
    word = new Word[2];
    tileState = 0;

}

void Tile::SetTileText(std::string str1, std::string str2)
{
    word[0].SetText(str1);
    word[0].ReduceSize(0.7);
    word[1].SetText(str2);
    word[1].ReduceSize(0.7);
}
Tile::Tile(int spriteNumber, int x, int y, std::string str, int price):Clickable(x,y,200,65)
{
    this-> spriteNumber= spriteNumber;
    this->str = str;
    this->price =price;


}

void Tile::Show(SDL_Renderer* renderer)
{
   SDL_SetRenderDrawColor( renderer, tileState, tileState, 0, 0);
   SDL_RenderFillRect(renderer,&pos);
   word[0].Show(renderer);
   word[1].Show(renderer);
}

Tile::~Tile()
{

}

void Tile::UpdatePos(int x, int y)
{
    word[0].SetPosition(x+30,y);
    word[1].SetPosition(x+30,y+29);
    Clickable::UpdatePos(x,y);
}
