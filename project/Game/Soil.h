#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Texture.h"
#include "Lids.h"

const int SOIL_WIDTH = 514;
const int SOIL_HEIGHT = 194;

class Soil: public Lids
{
private:

protected:

public:
    Soil(int, int);
    bool CorrectContainer();
    void Show(SDL_Renderer*);
    ~Soil();
};

