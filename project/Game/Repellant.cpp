#include "Repellant.h"
#include "Human.h"

Repellant::Repellant()
{

}

void Repellant::Apply(Scenario* house)
{
    int n;
    DLL<Human*> humans =  house->GetHumans(n);
    for(int i = 0;i < n;i++)
    {
        //humans.GiveItem(i)->SetCoveredInRepellant();        // this will basically cover every human with repellant which will not let mosquito bite anyone
    }
}
