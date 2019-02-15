#include "DDT.h"
#include "Mosquito.h"
#include "House.h"

DDT::DDT()
{
    name = "Spray";
    price.SetPaisa(230);
    spriteNum = 76;

}

void DDT::Apply(House* house)
{
    int n;
    DLL<Mosquito*> mosquitoes = house->GetMosquitoes(n);

    for(int i = 0; i < n; i++)
    {
        mosquitoes.GiveItem(i)->SetIsDead(true);
    }
    for(int i = 0; i<200; i++)
        {
            (*Score::GetInstance())++;
        }
}

DDT::~DDT()
{

}
