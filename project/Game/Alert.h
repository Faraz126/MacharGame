#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Texture.h"
#include "Word.h"
#include "Screens.h"
class EndMenu;

class Alert
{
    SDL_Rect* alert;
    SDL_Rect* timerPos;
    Texture* texture;
    Word* word;
    double timerSprite;
    int newScreenIter;

    bool show;

public:
    Alert();
    double GetTimerSprite();
    void Show(SDL_Renderer*, int);
    //void Update(double);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~Alert();
};
