#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include <cstdlib>
#include "Clickable.h"


class Bed : public Clickable
{
    bool occupied;

public:
    Bed();
    Bed(int,int);
    void SetPos(int,int);
    void Draw(SDL_Renderer*);
    int GetDistance(int x, int y); //passing on players x co-ordinate only
    bool GetOccupied();
    void SetOccupied(bool);
    int GetX();
    int GetY();
    ~Bed();
};
