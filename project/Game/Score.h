#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Word.h"
#include <sstream>  // for string streams
#include <string>

class Score
{
    Word* word;
    int scr;
    //SDL_Renderer* gRenderer;
public:

    Score();
    ~Score();
    void Show(SDL_Renderer*);
    Score operator+(const Score&);
    Score operator-(const Score&);
    Score operator*(const Score&);
    void operator++(int);
    bool operator<(const Score&);
    bool operator>(const Score&);
    bool operator==(const Score&);

    int operator+(int);
    int operator-(int);
    int operator*(int);
    bool operator<(int);
    bool operator>(int);
    bool operator==(int);


};
