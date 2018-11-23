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
    //Texture* texture;
    Word* word;
    double counter;

protected:

public:
    Closing();
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~Closing();
};
