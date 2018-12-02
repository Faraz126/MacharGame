#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Lids.h"
#include "Mosquito.h"
#include "BreedingGround.h"
#include "Lids.h"
#include "Score.h"

class Container : public BreedingGround
{
    public:
        Container(){};
        Container(int, int, int, int, bool = false);
        virtual ~Container();
        bool GetCovered();
        bool Collides(const Clickable&); //overwriding base class method, to include collision for lids as well.
        bool Collides(const SDL_Rect&);
        void SetX(int,int);

    protected:
        SDL_Rect correctLidPos;
        virtual void SetCovered(bool);
        Lids* lid;
    private:
        bool isCovered;
        //Lids* GenerateLid();

};
