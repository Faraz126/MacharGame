#include "AedesMosquito.h"
#include <random>
#include <iostream>
#include "Scenario.h"

AedesMosquito::AedesMosquito() : Mosquito()
{
    Vision = 200;
    MaxSpeedX = 15;
    MaxSpeedY = 15;
    Range = 30;
}

AedesMosquito::AedesMosquito(Scenario* screen): AedesMosquito()
{
    this -> screen = screen;
    Vision = 200;
}

void AedesMosquito::Bite()
{
    if(IsFollowingHuman == true && abs(position.x - humans.GiveItem(human)->GetX()) <= Range && abs(position.y - humans.GiveItem(human) -> GetY()) <= Range)
    {

        DetectHuman = false;
        IsFollowingHuman = false;   // so that it doesn't keep following human again

        if(rand() % 2 == 0)         // if this is true then infect with Dengue
        {
            humans.GiveItem(human) -> SetInfected(diseases[0]);
            Heal();
            //std::cout << "BITE!" << std::endl;
        }
        else    // if this is true then infect with Chikengunya
        {
            humans.GiveItem(human) -> SetInfected(diseases[1]);
            Heal();
            //std::cout << "BITE!" << std::endl;
        }
    }
}
