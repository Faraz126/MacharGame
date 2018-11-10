#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Screens
{

public:
    Screens();
    virtual void Click(SDL_Renderer*);
    virtual void Show(SDL_Renderer*);
    ~Screens();
};
