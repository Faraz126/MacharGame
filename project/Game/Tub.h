#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"


const int TUB_WIDTH = 235;
const int TUB_HEIGHT = 215;


class Tub : public Container
{
private:

protected:

public:
    Tub(int,int);
    Mosquito* Breed();
    void Show(SDL_Renderer*);
    void SetCovered(bool);
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void Update(int);
    ~Tub();
};

