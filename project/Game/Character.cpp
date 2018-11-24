#include "Character.h"

Character::Character() : Clickable(0,0,30,30)
{
}
Character::Character( char c ) : Clickable(0,0,30,30)
{
    this -> shownChar = c;
    int ascii = c;
    if (ascii >= 97)
    {
        this->pos.h = 101;
    }
    else
    {
        this -> pos .h = 73;
    }
    this -> pos .w = 73;

}

void Character::Show ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(shownChar, gRenderer, &pos);

}

void Character::SetPosition ( int x , int y)
{
    UpdatePos(x,y);
}

void Character::SetChar ( char c)
{
    shownChar= c;
    int ascii = c;
    if (ascii >= 97)
    {
       pos.h = 41;
    }
}
