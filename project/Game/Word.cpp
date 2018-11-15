#include "Word.h"
#include <stdio.h>
#include <string>
#include <iostream>



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
    std::cout << str;
    length = str.length();
    std::cout <<length;
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


