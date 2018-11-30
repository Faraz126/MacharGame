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


const int PLANT_WIDTH = 80;
const int PLANT_HEIGHT = 150.588;

class Plant : public Container
{
    int type;
    CleanWater* water;
    public:
        Plant(int, int);
        void SetCovered(bool);
        void Show(SDL_Renderer*);
        void HandleEvents(SDL_Event*, Screens_Node&);
        void Update(int){};
        Mosquito* Breed();

        ~Plant();
};

#endif // PLANT_H
