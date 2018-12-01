#pragma once
#include <stdio.h>
#include "Texture.h"
#include "Word.h"
#include "SDL.h"
#include "Clickable.h"
#include <string>
#include <iostream>

class Button : public Clickable
{

    void Click(SDL_Rect*);
    Texture * texture ;
    bool buttonSprite;
    int sprite2;

    public:
    Word * word ; //public as will be used to decrease size
    int intHover;
    Button (std::string str , int x, int y);
    void setText ( std::string str );
    Button();
    void Hover();
    void Click();
    void Show( SDL_Renderer * );
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void Update(int){};
    void setPosition ( int , int );
    void SetWidth(int,int);
    ~Button();
    void SetButtonSprite(bool);

};


