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

    for(int i = 0;i < Alert::humans->GetLength();i++)
    {
        if(Alert::humans->GiveItem(i)->GetOwnHouse() == house && Alert::humans->GiveItem(i)->GetInfected() != 0)      // this condition is basically for humans to lose health if they're infected
        {
            Alert::humans->GiveItem(i)->Damage();
        }
    }
}


BadMedicine::~BadMedicine()
{

}
