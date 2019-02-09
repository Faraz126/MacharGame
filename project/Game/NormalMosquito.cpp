#include "NormalMosquito.h"
#include <random>
#include <iostream>
#include "House.h"

NormalMosquito::NormalMosquito()  : Mosquito()
{
    diseaseCode = BITEN;
    Vision = 150;
    MaxSpeedX = 1;
    MaxSpeedY = 1;
    Range = 10;

    position.h = 231*sizeFactor;
    position.w = 271*sizeFactor;

    sprites[0].x = 1276 + (231*0);
    sprites[0].y = 5827;
    sprites[0].w = 231;
    sprites[0].h = 271;

    sprites[1].x = 1276 + (231*1);
    sprites[1].y = 5827;
    sprites[1].w = 231;
    sprites[1].h = 271;

    sprites[2].x = 1276 + (231*2);
    sprites[2].y = 5827;
    sprites[2].w = 231;
    sprites[2].h = 271;

    sprites[3].x = 1276 + (231*3);
    sprites[3].y = 5827;
    sprites[3].w = 231;
    sprites[3].h = 271;

    sprites[4].x = 1276 + (231*4);
    sprites[4].y = 5827;
    sprites[4].w = 231;
    sprites[4].h = 271;

    sprites[5].x = 1276 + (231*5);
    sprites[5].y = 5827;
    sprites[5].w = 231;
    sprites[5].h = 271;

    sprites[6].x = 1276 + (231*6);
    sprites[6].y = 5827;
    sprites[6].w = 231;
    sprites[6].h = 271;

    sprites[7].x = 1276 + (231*7);
    sprites[7].y = 5827;
    sprites[7].w = 231;
    sprites[7].h = 271;

    sprites[8].x = 1276 + (231*8);
    sprites[8].y = 5827;
    sprites[8].w = 231;
    sprites[8].h = 271;

    sprites[9].x = 1276 + (231*9);
    sprites[9].y = 5827;
    sprites[9].w = 231;
    sprites[9].h = 271;

    sprites[10].x = 1276 + (231*8);
    sprites[10].y = 5827;
    sprites[10].w = 231;
    sprites[10].h = 271;

    sprites[11].x = 1276 + (231*7);
    sprites[11].y = 5827;
    sprites[11].w = 231;
    sprites[11].h = 271;

    sprites[12].x = 1276 + (231*6);
    sprites[12].y = 5827;
    sprites[12].w = 231;
    sprites[12].h = 271;

    sprites[13].x = 1276 + (231*5);
    sprites[13].y = 5827;
    sprites[13].w = 231;
    sprites[13].h = 271;

    sprites[14].x = 1276 + (231*4);
    sprites[14].y = 5827;
    sprites[14].w = 231;
    sprites[14].h = 271;

    sprites[15].x = 1276 + (231*3);
    sprites[15].y = 5827;
    sprites[15].w = 231;
    sprites[15].h = 271;

    sprites[16].x = 1276 + (231*2);
    sprites[16].y = 5827;
    sprites[16].w = 231;
    sprites[16].h = 271;

    sprites[17].x = 1276 + (231*1);
    sprites[17].y = 5827;
    sprites[17].w = 231;
    sprites[17].h = 271;


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
        humans.GiveItem(human) -> SetInfected(diseaseCode);
        Heal();
    }
}
