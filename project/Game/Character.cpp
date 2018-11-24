#include "Character.h"

Character::Character()
{
    this -> charRect .w = 30;
    this -> charRect .h = 30;

}
Character::Character( char c )
{
    this -> shownChar = c;
    int ascii = c;
    if (ascii >= 97)
    {
        this->charRect.h = 101;
    }
    else
    {
        this -> charRect .h = 73;
    }
    this -> charRect .w = 73;
}

void Character::Show ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(shownChar, gRenderer, &charRect);

}

void Character::SetPosition ( int x , int y)
{
    this->charRect.x= x;
    this->charRect.y=y;
}

void Character::SetChar ( char c)
{
    shownChar= c;
    int ascii = c;
    if (ascii >= 97)
    {
        charRect.h = 41;
    }
}
