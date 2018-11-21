#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Screens.h"

class Entrance
{
private:
    bool state;

protected:
    SDL_Rect pos;
    int spriteNum;

public:
    Entrance(int,int);
    virtual void Show(SDL_Renderer*) = 0;
    virtual bool IsOpen() = 0;
    void SetState();
    void MosquitoEnter();
    bool WithinEntrance(int, int); //returns true if the given x,y co-ordinate is within the entrance.
    int GetX();
    int GetY();
    virtual void Update(SDL_Event*, Screens_Node&) = 0;
    virtual void ChangeState() = 0;
    virtual ~Entrance();

};


