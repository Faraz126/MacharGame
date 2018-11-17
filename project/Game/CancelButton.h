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
    CancelButton (int x, int y);
    CancelButton();
    void Hover();
    void Click();
    void Render ( SDL_Renderer * gRenderer );
    void setPosition ( int x, int y);

};


