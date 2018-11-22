#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"

const int WATER_HEIGHT = 100;
const int WATER_WIDTH = 100;

class DirtyWater : public Container
{
private:

protected:

public:
    DirtyWater(int, int);
    Mosquito* Breed();
    void Show(SDL_Renderer*);
    ~DirtyWater();
    void SetCovered(bool);
    void EventHandle(SDL_Event*){};
};


