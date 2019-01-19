#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Texture.h"
#include "Word.h"
#include "Screens.h"
#include "DoublyLinked.h"
#include "Human.h"

class EndMenu;

class Alert
{
    SDL_Rect* alert;
    SDL_Rect* timerPos;
    SDL_Rect* wordRect;
    Texture* texture;
    Word* word;
    double timerSprite;
    int newScreenIter;
    bool screenEnd;
    std::string str1;
    std::string str2;
    std::string str3;
    int randStr3;
    static DLL<Human*>* humans;


    bool show;

public:
    Alert();
    double GetTimerSprite();
    void Show(SDL_Renderer*, int);
    static void Add(Human*);
    static void Remove(Human*);
    //void Update(double);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~Alert();
};
