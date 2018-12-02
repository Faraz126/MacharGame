#include "DDT.h"
#include "Mosquito.h"

DDT::DDT()
{
    price = 1000;
}

void DDT::Apply(House* house)
{
    int n;
    DLL<Mosquito*> mosquitoes = house->GetMosquitoes(n);

    for(int i = 0; i < n; i++)
    {
        mosquitoes.GiveItem(i)->SetIsDead(true);
    }
}

DDT::~DDT()
{

}
