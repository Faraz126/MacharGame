#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>


class Door:public Entrance
{
private:
    //time TimeCovered;
protected:

public:
    Door(int,int);
    void Show(SDL_Renderer*);
    //time SetTime();
    ~Door();
};
