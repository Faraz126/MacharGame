#pragma once
#include <stdio.h>
#include <iostream>
#include <string>
#include "Character.h"
#include "Texture.h"

class Word
{
    public :
        Word( std::string str, int x, int y);
        void Show ( SDL_Renderer * gRenderer );
        void SetText ( std::string str );
        void SetPosition ( int x, int y);
        int SetTextLength ();
    private :
        int x,y,characterSpacing;
        //std::string renderWord ;
        int length;
        Character * characters ;
};
