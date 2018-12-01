#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"
#include "Soil.h"

const int WATER_HEIGHT = 136;
const int WATER_WIDTH = 509;

class DirtyWater : public Container
{
private:
    int delay;
protected:

public:
    DirtyWater(int, int);
    Mosquito* Breed();
    void Show(SDL_Renderer*);
    void Update(int);
    int DelayLidTime();
    ~DirtyWater();
    void SetCovered(bool);
    bool IsActive();
    void HandleEvents(SDL_Event*, Screens_Node&);

};


