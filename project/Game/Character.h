#pragma once
#include "Texture.h"
#include <SDL.h>

class Character
{
    int x,y;
    SDL_Rect charRect;
    char shownChar;
    Texture * CharTexture;
    public:
        Character();
        Character( char c, Texture * gSpriteSheetTexture );
        void render ( SDL_Renderer * gRenderer );
        void setPosition ( int x , int y);
        void setChar ( char c);
        void setTexture ( Texture * gSpriteSheetTexture , char c);

};
