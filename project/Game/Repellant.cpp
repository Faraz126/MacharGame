#include "Repellant.h"
#include "Human.h"
#include "House.h"

Repellant::Repellant()
{
    price.SetPaisa(140);
    name = "Repellent";
    spriteNum = 75;
}

void Repellant::Apply(House* house)
{
    int n;
    DLL<Human*> humans =  house->GetHumans(n);
    for(int i = 0;i < n;i++)
    {
        humans.GiveItem(i)->SetCoveredInRepellant();        // this will basically cover every human with repellant which will not let mosquito bite anyone
    }
}
