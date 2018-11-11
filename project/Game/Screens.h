#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Screens
{

public:
    Screens();
    virtual void Click(SDL_Renderer*)=0;
    virtual void MouseEvent(SDL_Event*) = 0;
    virtual void Show(SDL_Renderer*)=0;
    ~Screens();
};
