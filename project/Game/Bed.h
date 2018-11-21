#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include <cstdlib>


class Bed
{
    bool occupied;
    SDL_Rect pos;

public:
    Bed();
    Bed(int,int);
    void SetPos(int,int);
    void Draw(SDL_Renderer*);
    int GetDistance(int x); //passing on players x co-ordinate only
    bool GetOccupied();
    void SetOccupied(bool);
    ~Bed();
};
