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
    house->ApplyRepellent();
}
