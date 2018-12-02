#include "BadMedicine.h"
#include "Human.h"
#include "House.h"
#include <random>


BadMedicine::BadMedicine()
{
    price = 100;
}

void BadMedicine::Apply(Scenario* house)
{
    int n;
    DLL<Human*> humans =  house->GetHumans(n);
    for(int i = 0;i < n;i++)
    {
        if(rand() % 2 == 0 && humans.GiveItem(i)->GetInfected() != NULL)      // this condition is basically for humans to lose health if they're infected
        {
            humans.GiveItem(i)->Damage();
        }
    }
}


BadMedicine::~BadMedicine()
{

}
