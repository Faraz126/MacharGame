#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include "Clickable.h"
#include <string>
#include <iostream>

class Button : public Clickable
{
    Word * word ;
    void Click(SDL_Rect*);
    Texture * texture ;
    SDL_Event e;

    public:
    int intHover;
    Button (std::string str , int x, int y);
    void setText ( std::string str );
    Button();
    void Hover();
    void Click();
    void Render ( SDL_Renderer * );
    void setPosition ( int , int );
    ~Button();

};


