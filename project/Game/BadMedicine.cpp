#include "BadMedicine.h"
#include "Human.h"
#include <random>
#include "House.h"


BadMedicine::BadMedicine()
{
    price.SetPaisa(15);
    name = "Paracetamol";
    spriteNum = 38;
}

void BadMedicine::Apply(House* house)
{
    int n;
    DLL<Human*> humans =  house->GetHumans(n);
    for(int i = 0;i < n;i++)
    {
        if(rand() % 2 == 0 && humans.GiveItem(i)->GetInfected() != 0)      // this condition is basically for humans to lose health if they're infected
        {
            humans.GiveItem(i)->Damage();
        }
    }
}


BadMedicine::~BadMedicine()
{

}
