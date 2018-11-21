#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Screens.h"
#include "closingMoving.h"

class Closing:public Menu
{
    private:
    SDL_Rect* closingPos;
    //Texture* texture;
    Word* word;
    ClosingMoving* closMove;

protected:

public:
    Closing();
    void Show(SDL_Renderer*);
    void Update(SDL_Event*, Screens_Node&);
    ~Closing();
};
