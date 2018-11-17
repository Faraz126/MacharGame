#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"

class Entrance
{
private:
    bool State;
    SDL_Rect pos;
    int spriteNum;

protected:

public:
    Entrance(int,int,int);
    void Show(SDL_Renderer*);
    bool GetState();
    void SetState();
    void MosquitoEnter();
    bool WithinEntrance(int, int); //returns true if the given x,y co-ordinate is within the entrance.
    int GetX();
    int GetY();
    ~Entrance();
};


