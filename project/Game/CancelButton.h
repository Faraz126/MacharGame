#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include <string>
#include <iostream>
#include "Clickable.h"

class CancelButton : public Clickable
{
    void Click(SDL_Rect*);
    Texture * texture ;
    SDL_Event e;

    public:
    int diffStateBtn;
    //CancelButton (int , int );
    CancelButton(SDL_Rect);
    void Hover();
    void Click();
    void Show ( SDL_Renderer * );

};


