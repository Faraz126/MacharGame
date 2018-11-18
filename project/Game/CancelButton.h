#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include <string>
#include <iostream>

class CancelButton
{
    void Click(SDL_Rect*);
    Texture * texture ;
    SDL_Event e;

    public:
    int diffStateBtn;
    SDL_Rect pos;
    CancelButton (int , int );
    CancelButton(SDL_Rect);
    void Hover();
    void Click();
    void Show ( SDL_Renderer * );
    bool WithinCancelRegion(int , int );

};


