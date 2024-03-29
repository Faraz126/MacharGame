#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"
#include "Screens.h"
#include "Soil.h"


const int C_WATER_HEIGHT = 135;
const int C_WATER_WIDTH = 507;

class CleanWater : public Container
{
private:
    int delay;
    int breedCount;
protected:

public:
    CleanWater(int, int);
    Mosquito* Breed();
    bool IsActive();
    int DelayLidTime();
    int GetBreedCount();
    void Show(SDL_Renderer*);
    void Update(int);
    ~CleanWater();
    void HandleEvents(SDL_Event*,Screens_Node&);
    void Write(std::ofstream&);
    void SetCovered(bool);
};


