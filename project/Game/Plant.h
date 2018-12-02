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
#include <fstream>
#include <sstream>


const int PLANT_WIDTH = 80;
const int PLANT_HEIGHT = 150.588;

class Plant : public Container
{
    int type;
    public:
        Plant(){};
        Plant(int, int);
        void SetCovered(bool);
        void Show(SDL_Renderer*);
        void Update(int);
        void HandleEvents(SDL_Event*, Screens_Node&);
        Mosquito* Breed();
        void Write(std::fstream&);
        void Read(std::fstream&);

        ~Plant();
};

#endif // PLANT_H
