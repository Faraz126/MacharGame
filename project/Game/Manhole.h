#pragma once
#include "Container.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Mosquito.h"
#include "ManholeLid.h"

const int MANHOLE_WIDTH = 70;
const int MANHOLE_HEIGHT = 18.006;

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
    void HandleEvents(SDL_Event*, Screens_Node&);
    void Update(int);

};


