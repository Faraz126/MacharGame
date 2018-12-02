#include "Tile.h"
#include "BuyableItems.h"

Tile::Tile(int a): Clickable(0,0, 0, 0)
{

    tileState = 0;
    sprite=75;

    iconPos.x = 0;
    iconPos.y = 0;
    iconPos.w = 89 * 0.3;
    iconPos.h = 188 * 0.3;

    if(a==0)  //tiles for medicine,ddt,nets, repellent
    {
        buy = new BadMedicine();
    }
    if(a == 1)
    {
        buy = new DDT;
    }
    if(a==2)
    {
        buy = new Nets;
    }
    if(a==3)
    {
        buy = new Repellant;
    }


}

Tile::Tile(): Clickable(0,0, 210, 65)
{
    word = new Word[2];
}

void Tile::SetTileText()
{
    word[0].SetText(buy->GetName()); //name of whatever product it  is
    word[0].ReduceSize(0.5);
    word[1].SetText(std::to_string(buy->GetPrice())); //price of whatever product it  is by converting into string
    word[1].ReduceSize(0.5);
}




void Tile::SetValues(int a)
{
    if(a==0)
    {
        buy = new BadMedicine();
    }
    if(a == 1)
    {
        buy = new DDT;
    }
    if(a==2)
    {
        buy = new Nets;
    }
    if(a==3)
    {
        buy = new Repellant;
    }
}

void Tile::Show(SDL_Renderer* renderer)
{
   SDL_SetRenderDrawColor( renderer, tileState, 255, 255, 0);
   SDL_RenderFillRect(renderer,&pos);
   word[0].Show(renderer);
   word[1].Show(renderer);
   texture = Texture::GetInstance(renderer);

   texture->Render(buy->GetSpriteNum(),renderer,&iconPos);
}

Tile::~Tile()
{
    //delete[] word;
}

void Tile::UpdatePos(int x, int y)
{
    word[0].SetPosition(x+33,y+5);
    word[1].SetPosition(x+33,y+35);
    iconPos.x = x+25;
    iconPos.y = y+25;
    Clickable::UpdatePos(x,y);
}

