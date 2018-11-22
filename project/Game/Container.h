#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Lids.h"
#include "Mosquito.h"
#include "BreedingGround.h"
#include "TrashCanLid.h"
#include "Lids.h"

class Container : public BreedingGround
{
    public:
        Container(int, int, int, int, bool = false);
        virtual ~Container();
        virtual void Show(SDL_Renderer*) = 0;
        bool GetCovered();
        //virtual Mosquito* Breed();
        virtual void EventHandle(SDL_Event*) = 0;
        virtual void SetCovered(bool);
        void SetX(int,int);
    protected:
        Lids* lid;
    private:
        bool isCovered;
        //Lids* GenerateLid();

};
