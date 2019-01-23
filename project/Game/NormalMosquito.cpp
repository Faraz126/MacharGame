#include "NormalMosquito.h"
#include <random>
#include <iostream>
#include "House.h"

NormalMosquito::NormalMosquito()  : Mosquito()
{
    diseaseCode = BITEN;
    Vision = 150;
    MaxSpeedX = 10;
    MaxSpeedY = 10;
    Range = 10;
}

NormalMosquito::NormalMosquito(Scenario* screen) :NormalMosquito()
{
    this -> screen = screen;
}


void NormalMosquito::Bite()
{
    if(IsFollowingHuman == true && abs(position.x - humans.GiveItem(human) ->GetX()) <= Range && abs(position.y - humans.GiveItem(human)-> GetY()) <= Range)
    {
        DetectHuman = false;
        IsFollowingHuman = false;       // so that it doesn't keep following human again
        //std::cout << "BITE!" << std::endl;
        //humans.GiveItem(human) -> SetInfected(diseaseCode);
        Heal();
    }
}
