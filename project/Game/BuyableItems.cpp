#include "BuyableItems.h"
#include "House.h"
//#include "Money.h"

BuyableItems::BuyableItems()
{
    name = " ";
    price.SetPaisa(0);
}

BuyableItems::~BuyableItems()
{

}

string BuyableItems::GetName()
{
    return name;
}

Money& BuyableItems::GetPrice()
{
    return price;
}

int BuyableItems::GetSpriteNum()
{
    return spriteNum;
}
