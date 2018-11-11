#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include <stdio.h>
#include <string>
#include <iostream>

class Button
{
    Button ( Texture * texture , std::string str , int x, int y);


    void setText ( std::string str );
    void Click();
    Word * word ;
    void Hover();
    void Draw(SDL_Renderer*);
    void Click(SDL_Rect*);

    SDL_Rect pos;
    SDL_Rect BtnRect [3];
    Texture * texture ;

    public:
    Button();
    void render ( SDL_Renderer * gRenderer );
    void setPosition ( int x, int y);

};


