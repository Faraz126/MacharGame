#include "MalariaMosquito.h"
#include <random>
#include <iostream>
#include "House.h"

MalariaMosquito::MalariaMosquito()  : Mosquito()
{
    diseaseCode = DISEASE_MALARIA;
    Vision = 250;
    MaxSpeedX = 5;
    MaxSpeedY = 5;
    Range = 15;
}

MalariaMosquito::MalariaMosquito(Scenario* screen) :MalariaMosquito()
{
    this -> screen = screen;
}


void MalariaMosquito::Bite()
{
    if(IsFollowingHuman == true && abs(position.x - humans.GiveItem(human)->GetX()) <= Range && abs(position.y - humans.GiveItem(human)-> GetY()) <= Range)
    {
        humans.GiveItem(human) -> SetInfected(diseaseCode);
        DetectHuman = false;
        IsFollowingHuman = false;
        //std::cout << "BITE!" << std::endl;
        Heal();
    }
}
