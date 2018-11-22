#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>


class Door:public Entrance
{
private:
    //time TimeCovered;
    bool  isOpen;
protected:

public:
    Door(int,int);
    void Show(SDL_Renderer*, SDL_Rect* rect = nullptr);
    void Update(SDL_Event*, Screens_Node&);
    void ShowOutside(SDL_Renderer*, const SDL_Rect&, float);
    virtual void ChangeState();
    bool IsOpen();
    //time SetTime();
    ~Door();
};
