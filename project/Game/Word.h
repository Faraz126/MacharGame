#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "Character.h"

class Word
{
    public :
        Word( std::string str, int x, int y);
        void render ( SDL_Renderer * gRenderer );
        void setText ( std::string str );
        void setPosition ( int x, int y);
        int getTextLength ();

    private :
        int x,y;
        std::string renderWord ;
        Character * characters ;
};
