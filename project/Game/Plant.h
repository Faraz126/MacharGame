#pragma once
#ifndef PLANT_H
#define PLANT_H

#include "Container.h"
#include "Water.h"
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
    int spriteNum;
    public:
        Plant(int, int);
        void SetCovered(bool);
        void Show(SDL_Renderer*);
        Mosquito* Breed(int);

        ~Plant();
};

#endif // PLANT_H
