#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Screens.h"
#include <string>


class Closing:public Menu
{
    private:
    SDL_Rect* closingPos;
    SDL_Rect* closingWordPos;
    Word* word;
    double counter;
    int space;

protected:

public:
    Closing(Screens* , bool, bool = false, bool = false, int = 1);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~Closing();
};
