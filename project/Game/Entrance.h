#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Entrance
{
private:
    bool State;


protected:
    SDL_Rect pos;
    int spriteNum;

public:
    Entrance(int,int);
    virtual void Show(SDL_Renderer*) = 0;
    bool GetState();
    void SetState();
    void MosquitoEnter();
    bool WithinEntrance(int, int); //returns true if the given x,y co-ordinate is within the entrance.
    ~Entrance();
};


