#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Word.h"
#include <sstream>  // for string streams
#include <string>
#include "Texture.h"

class Money
{
    Word* word;

    SDL_Rect* moneyPos;
    Texture* texture;
public:

    Money();
    ~Money();
    void SetPaisa(int);
    int paisa;
    int GetPaisa();
    void Show(SDL_Renderer*);
    Money operator+(const Money&);
    Money operator-(const Money&);
    Money operator*(const Money&);
    void operator++(int);
    bool operator<(const Money&);
    bool operator>(const Money&);
    bool operator==(const Money&);

    int operator+(int);
    int operator-(int);
    int operator*(int);
    bool operator<(int);
    bool operator>(int);
    bool operator==(int);



};

