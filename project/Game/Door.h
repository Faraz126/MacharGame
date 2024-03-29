#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>


class Door:public Entrance
{
private:
    //time TimeCovered;
    bool  isOpen;
    SDL_Rect* rect;

public:
    Door(int,int);
    void Show(SDL_Renderer*);
    void OutdoorPosCenter(int&, int&); //to give position of door center.
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void ShowOutside(SDL_Renderer*);
    virtual void ChangeState();
    bool IsOpen();
    //time SetTime();
    ~Door();
};
