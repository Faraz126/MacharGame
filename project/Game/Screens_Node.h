#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"

struct Screens_Node
{
    Screens* prev_screen;
    Screens* cur_screen;
    Screens* next_screen;
    bool prev_backable;
    bool prev_updatable;

};
