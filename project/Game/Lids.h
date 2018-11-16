#pragma once
#include <SDL.h>
#include <SDL_image.h>


class Lids
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

