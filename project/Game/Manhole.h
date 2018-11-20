#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"

const int MANHOLE_WIDTH = 354;
const int MANHOLE_HEIGHT = 92;

class Manhole : public Container
{
private:

protected:

public:
    Manhole(int,int);
    Mosquito* Breed();
    void Show(SDL_Renderer*);
    void SetCovered(bool);
    ~Manhole();
};


