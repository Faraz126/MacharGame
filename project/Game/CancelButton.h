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

    public:
    int diffStateBtn;
    //CancelButton (int , int );
    CancelButton(SDL_Rect);
    void Hover();
    void Click();
    void Update(int){};
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void Show ( SDL_Renderer * );

};


