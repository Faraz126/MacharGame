#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Screens.h"

class ClosingMoving
{
    SDL_Rect* ClosingMovingPos;
    Word* word;

public:
    void Show(SDL_Renderer*);
    ClosingMoving();
    ~ClosingMoving();
};
