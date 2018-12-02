#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Texture.h"
#include "Clickable.h"
#include <iostream>

class CheckBox : public Clickable
{
    Texture* texture;
    int clickSprite;


public:
    bool status;
    CheckBox();
    void Click();
    void Show(SDL_Renderer*) ;
    void Update(int) ;
    void HandleEvents(SDL_Event*, Screens_Node&);
    void SetPosition(int,int);
    void ChangeState();
    ~CheckBox();

};
