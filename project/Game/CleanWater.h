#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"
#include "Soil.h"

const int C_WATER_HEIGHT = 135;
const int C_WATER_WIDTH = 507;

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


