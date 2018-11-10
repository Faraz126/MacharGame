#include "Character.h"

Character::Character(){};
Character::Character( char c, LTexture * gSpriteSheetTexture )
{
        this -> shownChar = c;
        this -> CharTexture = gSpriteSheetTexture ;
        this -> charRect .w = 44;
        this -> charRect .h = 48;
        this -> setPosition (10 , 10);
        this -> setChar (c);
}

void Character::render ( SDL_Renderer * gRenderer )
{
    CharTexture -> render (this ->x, this ->y, gRenderer , & charRect );
}

void Character::setPosition ( int x , int y)
{
    this ->x = x;
    this ->y = y;
}

void Character::setChar ( char c)
{
    int ascii = c;
    if (c == ' ')
    {
        this -> charRect .x = 4*44;
        this -> charRect .y = 5*48;
    }
    if ( ascii <= 90 && ascii >= 65)
    {
        ascii -=65;
        this -> charRect .x = ( ascii %11)*44;
        this -> charRect .y = ( ascii /11)*48;
    }
}
void Character::setTexture ( LTexture * gSpriteSheetTexture , char c)
{
    this -> shownChar = c;
    this -> CharTexture = gSpriteSheetTexture ;
    this -> charRect .w = 44;
    this -> charRect .h = 48;
    this -> setPosition (10 , 10);
    this -> setChar (c);
}
