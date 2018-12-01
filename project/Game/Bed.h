#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Human.h"
#include "Clickable.h"


class Bed : public Clickable
{
    bool occupied;
    Human* bedOccupied;
    int state;
    SDL_Rect* sitting;
    SDL_Rect* lying;

public:
    Bed();
    Bed(int,int);
    void SetPos(int,int);
    void Show(SDL_Renderer*);
    void Update(int){};
    void HandleEvents(SDL_Event*, Screens_Node&);
    //passing on players x co-ordinate only
    bool GetOccupied();
    void SetOccupied(bool, Human* = 0);
    int GetX();
    int GetY();
    void HumanState(int);
    ~Bed();
};
