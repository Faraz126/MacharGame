#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"
#include <iostream>
#include "string"
#include "Outdoor.h"
#include "ExitMenu.h"
#include "MainMenu.h"


class EndMenu: public Menu
{
    SDL_Rect* pos0;
    SDL_Rect pos2;
    Texture* texture;
    CancelButton* cancelBtn;
    std::string buttonText[3];

public:

    EndMenu();
    void HoverClick(SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~EndMenu();
};

