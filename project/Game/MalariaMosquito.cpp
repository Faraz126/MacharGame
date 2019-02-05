#include "MalariaMosquito.h"
#include <random>
#include <iostream>
#include "Scenario.h"


MalariaMosquito::MalariaMosquito()  : Mosquito()
{
    diseaseCode = DISEASE_MALARIA;
    Vision = 250;
    MaxSpeedX = 5;
    MaxSpeedY = 5;
    Range = 15;

    position.h = 263*sizeFactor;
    position.w = 308*sizeFactor;
    sprites[0].x = 3713;
    sprites[0].y = 308*0;
    sprites[0].w = 263;
    sprites[0].h = 308;

    sprites[1].x = 3713;
    sprites[1].y = 308*1;
    sprites[1].w = 263;
    sprites[1].h = 308;

    sprites[2].x = 3713;
    sprites[2].y = 308*2;
    sprites[2].w = 263;
    sprites[2].h = 308;

    sprites[3].x = 3713;
    sprites[3].y = 308*3;
    sprites[3].w = 263;
    sprites[3].h = 308;

    sprites[4].x = 3713;
    sprites[4].y = 308*4;
    sprites[4].w = 263;
    sprites[4].h = 308;

    sprites[5].x = 3713;
    sprites[5].y = 308*5;
    sprites[5].w = 263;
    sprites[5].h = 308;

    sprites[6].x = 3713;
    sprites[6].y = 308*6;
    sprites[6].w = 263;
    sprites[6].h = 308;

    sprites[7].x = 3713;
    sprites[7].y = 308*7;
    sprites[7].w = 263;
    sprites[7].h = 308;

    sprites[8].x = 3713;
    sprites[8].y = 308*8;
    sprites[8].w = 263;
    sprites[8].h = 308;

    sprites[9].x = 3713;
    sprites[9].y = 308*9;
    sprites[9].w = 263;
    sprites[9].h = 308;


    sprites[10].x = 3713;
    sprites[10].y = 308*10;
    sprites[10].w = 263;
    sprites[10].h = 308;

    sprites[11].x = 3713;
    sprites[11].y = 308*11;
    sprites[11].w = 263;
    sprites[11].h = 308;

    sprites[12].x = 3713;
    sprites[12].y = 308*12;
    sprites[12].w = 263;
    sprites[12].h = 308;

    sprites[13].x = 3713;
    sprites[13].y = 308*13;
    sprites[13].w = 263;
    sprites[13].h = 308;

    sprites[14].x = 3713;
    sprites[14].y = 308*14;
    sprites[14].w = 263;
    sprites[14].h = 308;

    sprites[15].x = 3713;
    sprites[15].y = 308*15;
    sprites[15].w = 263;
    sprites[15].h = 308;

    sprites[16].x = 3713;
    sprites[16].y = 308*16;
    sprites[16].w = 263;
    sprites[16].h = 308;

    sprites[17].x = 3713;
    sprites[17].y = 308*17;
    sprites[17].w = 263;
    sprites[17].h = 308;

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
        Heal();
    }
}
