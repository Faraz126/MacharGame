#pragma once
#include <stdio.h>
#include <string>
#include <iostream>

class Button
{
    Button ( Texture * Texture , std::string str , int x, int y);
    void render ( SDL_Renderer * gRenderer );
    void setPosition ( int x, int y);
    void setText ( std::string str );
    void Click();
    Word * word ;
    void Hover();
    void Draw(SDL_Renderer*);
    void Click(SDL_Rect*);

    private:
    int x, y;
    int endx,endy;
    SDL_Rect BtnRect [3];
    Texture * btnTexture ;

};


