#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"

const int C_WATER_HEIGHT = 100;
const int C_WATER_WIDTH = 100;

class CleanWater : public Container
{
private:

protected:

public:
    CleanWater(int, int);
    Mosquito* Breed();
    void Show(SDL_Renderer*);
    ~CleanWater();
    void SetCovered(bool);
    void EventHandle(SDL_Event*);
};


