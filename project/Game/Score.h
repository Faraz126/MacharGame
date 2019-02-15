#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Word.h"
#include <sstream>  // for string streams
#include <string>

enum STATUS {GREEN, ORANGE, RED};
class Score
{
    Score();
    Word* word;
    static Score* instance;
    SDL_Rect* scorePos;
    Texture* texture;

    //SDL_Renderer* gRenderer;
public:
    int timeStart;
    int timeEnd;
    void SetMessage(int);
    int scr;
    static Score* GetInstance();
    ~Score();
    int GetScore();
    void Show(SDL_Renderer*);
    void ShowStatus(SDL_Renderer*);
    Score operator+(const Score&);
    Score operator-(const Score&);
    Score operator*(const Score&);
    int status;
    int people;
    void ChangeStatus(int i){status = i;}
    void operator++(int);
    void operator--(int);
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
