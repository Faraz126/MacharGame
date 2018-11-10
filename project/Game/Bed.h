#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Bed
{
    bool occupied;
    SDL_Rect pos;

public:
    Bed();
    Bed(int,int);
    void SetPos(int,int);
    void Draw(SDL_Renderer*);
    ~Bed();
};
