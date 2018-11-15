#pragma once
#include "Texture.h"
#include <SDL.h>

class Character
{
    SDL_Rect charRect;
    char shownChar;
    Texture* texture;

    public:
        Character();
        Character(char c);
        void Show ( SDL_Renderer * gRenderer );
        void SetPosition ( int x , int y);
        void SetChar ( char c);

};
