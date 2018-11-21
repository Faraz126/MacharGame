#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include <string>
#include <iostream>

class Button
{
    Word * word ;
    void Click(SDL_Rect*);
    Texture * texture ;
    SDL_Event e;

    public:
    int intHover;
    SDL_Rect pos;
    Button (std::string str , int x, int y);
    void setText ( std::string str );
    Button();
    void Hover();
    void Click();
    void Render ( SDL_Renderer * );
    void setPosition ( int , int );
    bool WithinRegion (int, int);
    ~Button();

};


