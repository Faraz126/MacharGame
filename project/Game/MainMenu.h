#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"


class MainMenu: public Menu
{
protected:

public:
    MainMenu();
    void Click(SDL_Renderer*);
    void Show(SDL_Renderer*);
    ~MainMenu();
};
