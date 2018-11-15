#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"
#include <iostream>
#include "string"


class MainMenu: public Menu
{
    SDL_Rect pos0;
    SDL_Rect pos1;
    SDL_Renderer* gRenderer;
    Texture* texture;
    double mosquitoIterator;

public:

    std::string buttonText[3];
    MainMenu();
    void Click(SDL_Renderer*);
    void Show(SDL_Renderer*);
    void Hover(SDL_Renderer*);
    void MouseEvent(SDL_Event*);
    ~MainMenu();
};
