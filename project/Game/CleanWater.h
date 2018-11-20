#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"

const int WATER_HEIGHT = 100;
const int WATER_WIDTH = 100;

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
};


