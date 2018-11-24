#include "Tile.h"

Tile::Tile(): Clickable(0,0, 250, 65)
{
    word = new Word[2];
    tileState = 0;
    sprite=75;

    iconPos.x = 100;
    iconPos.y = 710;
    iconPos.w = 89 * 0.3;
    iconPos.h = 188 * 0.3;


}

void Tile::SetTileText(std::string str1, std::string str2)
{
    word[0].SetText(str1);
    word[0].ReduceSize(0.6);
    word[1].SetText(str2);
    word[1].ReduceSize(0.6);
}
Tile::Tile(int spriteNumber, int x, int y, std::string str, int price):Clickable(x,y,200,65)
{
    this-> spriteNumber= spriteNumber;
    this->str = str;
    this->price =price;


}

void Tile::Show(SDL_Renderer* renderer, int sprite)
{
   SDL_SetRenderDrawColor( renderer, tileState, 255, 255, 0);
   SDL_RenderFillRect(renderer,&pos);
   word[0].Show(renderer);
   word[1].Show(renderer);
   texture = Texture::GetInstance(renderer);
   if (sprite==75)
   {
       texture->Render(sprite, renderer, &iconPos);
   }
   if (sprite==76)
   {
       iconPos.x = 370;
       texture->Render(sprite, renderer, &iconPos);
   }
   if (sprite==13)
   {
       iconPos.x = 640;
       texture->Render(sprite, renderer, &iconPos);
   }


}

Tile::~Tile()
{
    delete[] word;
}

void Tile::UpdatePos(int x, int y)
{
    word[0].SetPosition(x+33,y+5);
    word[1].SetPosition(x+33,y+35);
    Clickable::UpdatePos(x,y);
}

