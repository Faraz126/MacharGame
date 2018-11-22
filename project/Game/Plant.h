#pragma once
#ifndef PLANT_H
#define PLANT_H

#include "Container.h"
#include "CleanWater.h"
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Mosquito.h"
#include "Texture.h"


const int PLANT_WIDTH = 102;
const int PLANT_HEIGHT = 192;

class Plant : public Container
{
    int type;
    CleanWater* water;
    public:
        Plant(int, int);
        void SetCovered(bool);
        void Show(SDL_Renderer*);
        void EventHandle(SDL_Event*){};
        Mosquito* Breed();

        ~Plant();
};

#endif // PLANT_H
