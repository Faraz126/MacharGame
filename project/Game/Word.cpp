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
    characters = 0;
    SetText(str);
    characterSpacing = 25;
    SetPosition(x,y);

}


void Word::AddPosition(int y)
{
    this->y += y;
    SetPosition(x, this->y);
}


void Word::Show ( SDL_Renderer * gRenderer )
{
    for(int i=0;i <length;i++)  //rendering characters
    {
        characters[i].Show(gRenderer);
    }
}
void Word::SetText ( std::string str )
{
    length = str.length();
    if ( characters != 0 )
    {
        delete[] characters ;
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

void Word::ReduceSize(double n)
{
    int x = this->x;
    int y = this->y;
    int characterSpacing = this->characterSpacing*n;
    for (int i = 0; i <this->length; i++)
    {
        characters[i].ReduceSize(n);
        characters[i].SetPosition(x+(i*characterSpacing) ,y);
    }
}

//int Word::CenteralizeWord(int x, int y, int w)
//{
//    return x +(w-(25*str.length()))/2, y+15
//}
