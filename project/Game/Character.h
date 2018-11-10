#pragma once

class Character
{
    int x,y;
    SDL_Rect charRect;
    char shownChar;
    LTexture * CharTexture;
    public:
        Character();
        Character( char c, LTexture * gSpriteSheetTexture );
        void render ( SDL_Renderer * gRenderer );
        void setPosition ( int x , int y);
        void setChar ( char c);
        void setTexture ( LTexture * gSpriteSheetTexture , char c);

};
