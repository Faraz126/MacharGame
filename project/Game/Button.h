#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include <string>
#include <iostream>

class Button
{
    Button ( Texture * texture , std::string str , int x, int y);
    void setText ( std::string str );
    Word * word ;
    void Click(SDL_Rect*);
    SDL_Rect BtnRect [3];
    Texture * texture ;

    SDL_Event e;

    public:
    int intHover;
    SDL_Rect pos;
    Button();
    void Hover();
    void Click();
    void render ( SDL_Renderer * gRenderer );
    void setPosition ( int x, int y);

};


