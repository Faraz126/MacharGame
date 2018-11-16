#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Mosquito.h"

class BreedingGround
{
private:
protected:
    SDL_Rect pos;
public:
    BreedingGround(int, int, int, int);
    virtual void Show(SDL_Renderer*) = 0;
    virtual Mosquito* Breed(int) = 0;
    virtual ~BreedingGround();
    void UpdatePos(int,int);
};
