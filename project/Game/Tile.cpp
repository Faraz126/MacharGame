#include "Tile.h"
#include "BuyableItems.h"
#include "House.h"

Tile::Tile(int a): Clickable(0,0, 0, 0)
{

    if(a==0)  //tiles for medicine,ddt,nets, repellent
    {
        buy = new BadMedicine();
        sprite=148;
    }
    if(a == 1)
    {
        buy = new DDT;
        sprite=146;
    }
    if(a==2)
    {
        buy = new Nets;
        sprite=149;
    }
    if(a==3)
    {
        buy = new Repellant;
        sprite=147;
    }



}

Tile::Tile()
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 212;
    pos.h = 72;
}


//void Tile::SetTileText()
//{
//    word[0].SetText(buy->GetName()); //name of whatever product it  is
//    word[0].ReduceSize(0.5);
//    word[1].SetText(std::to_string(buy->GetPrice().GetPaisa())); //price of whatever product it  is by converting into string
//    word[1].ReduceSize(0.5);
//}

bool Tile::Buyable(Money& houseMoney)
{
    return houseMoney > buy->GetPrice();
}

void Tile::Buy(House* house)
{
    buy->Apply(house);
    house->GetMoney()-(buy->GetPrice().GetPaisa());
}


void Tile::SetValues(int a)
{
    if(a==0)  //tiles for medicine,ddt,nets, repellent
    {
        buy = new BadMedicine();
        sprite=148;
    }
    if(a == 1)
    {
        buy = new DDT;
        sprite=146;
    }
    if(a==2)
    {
        buy = new Nets;
        sprite=149;
    }
    if(a==3)
    {
        buy = new Repellant;
        sprite=147;
    }
}

void Tile::Hover()
{
    if (sprite < 150)
    {
        sprite +=4;
    }
}

void Tile::UnHover()
{
    if (sprite > 149)
    {
        sprite -= 4;
    }
}

void Tile::Show(SDL_Renderer* renderer)
{

//   word[0].Show(renderer);
//   word[1].Show(renderer);
   texture = Texture::GetInstance(renderer);
   texture->Render(sprite,renderer, &pos);
   //texture->Render(buy->GetSpriteNum(),renderer,&iconPos);
}

Tile::~Tile()
{
    //delete[] word;
}

void Tile::UpdatePos(int x, int y)
{
//    word[0].SetPosition(x+33,y+5);
//    word[1].SetPosition(x+33,y+35);
    iconPos.x = x+25;
    iconPos.y = y+25;
    Clickable::UpdatePos(x,y);
}

