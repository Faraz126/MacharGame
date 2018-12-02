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
    Soil(){};
    Soil(int, int);
    bool CorrectContainer();
    void Show(SDL_Renderer*);
    void Update(int){};
    //void HandleEvents(SDL_Event*, Screens_Node&){};
    ~Soil();
};

