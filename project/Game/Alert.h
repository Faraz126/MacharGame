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
    static SDL_Rect* alert;
    static SDL_Rect* timerPos;
    double timerSprite;




public:
    Alert();
    double GetTimerSprite();
    static void Show(SDL_Renderer*);
    static void Add(Human*);
    static void Remove(Human*);
    static void SetUpRects();
    //void Update(double);
    void HandleEvents(SDL_Event*, Screens_Node&);
    static DLL<Human*>* humans;
    ~Alert();
};
