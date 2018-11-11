#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"


class MainMenu: public Menu
{
    SDL_Rect pos0;
    SDL_Rect pos1;
    SDL_Renderer* gRenderer;
    Texture* texture;

public:
    MainMenu();
    void Click(SDL_Renderer*);
    void Show(SDL_Renderer*);
    void Hover(SDL_Event*,SDL_Renderer*);
    void MouseEvent(SDL_Event*,SDL_Renderer*);
    ~MainMenu();
};
