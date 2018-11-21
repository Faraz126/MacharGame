#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Word.h"

class ClosingMoving
{
    SDL_Rect* ClosingMovingPos;
    Word* word;

public:
    void Show(SDL_Renderer*);
    ClosingMoving();
    ~ClosingMoving();
};
