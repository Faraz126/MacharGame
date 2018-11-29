#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Word.h"
#include <sstream>  // for string streams
#include <string>

class Score
{
    Score();
    Word* word;
    static Score* instance;
    int scr;
    //SDL_Renderer* gRenderer;
public:

    static Score* GetInstance();
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
