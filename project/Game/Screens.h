#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Screens;


struct Screens_Node
{
    Screens* prev_screen;
    Screens* cur_screen;
    Screens* next_screen;
    bool prev_backable;
    bool prev_updatable;

    Screens_Node()
    {
        prev_screen = cur_screen = next_screen = 0;
        prev_backable = prev_updatable = false;
    }

};

class Screens
{

public:
    Screens();
    //virtual void Click(SDL_Renderer*) = 0;
    virtual void Show(SDL_Renderer*) = 0;
    virtual void Update(SDL_Event&, Screens_Node&) = 0;
    ~Screens();
};


