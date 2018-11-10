#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>

class Window :public Entrance
{
private:
//    time TimeCovered;
protected:

public:
    Window(int,int);
    void Show(SDL_Renderer*);
    //time SetTime();
    ~Window();
};
