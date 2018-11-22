#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Clickable.h"

class Lids: public Clickable
{
private:

protected:


public:
    Lids();
    void Drag(SDL_Event);
    void Drop(SDL_Event);
    void Show(SDL_Renderer*);
    void Uncover();
    ~Lids();
};

