#include "Word.h"
#include <stdio.h>
#include <string>
#include <iostream>

Word::Word()
{
    x= 0;
    y= 0;
    characterSpacing= 25;
    length= 0;
    characters = 0;
}

Word::Word(std::string str ,  int x, int y)


{
    SetText(str);
    characterSpacing = 25;
    SetPosition(x,y);

}

void Word::Show ( SDL_Renderer * gRenderer )
{
    for(int i=0;i <length;i++)
    {
        characters[i].Show(gRenderer);
    }
}
void Word::SetText ( std::string str )
{
    length = str.length();
    if ( characters != NULL )
    {
        delete [] characters ;
    }
    characters = new Character[length];
    for ( int i = 0; i < this -> length; i ++)
    {
        characters[i].SetChar(str[i]);          //storing character from string
    }
}

void Word::SetPosition ( int x, int y)
{
    this ->x = x;
    this ->y = y;
    for ( int i = 0; i < this ->length; i ++)
    {
        characters [i]. SetPosition (x+(i*characterSpacing) ,y);
    }
}


