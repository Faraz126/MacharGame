#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"
#include <iostream>
#include "string"
#include "Outdoor.h"
#include "Settings.h"
#include "ExitMenu.h"


class MainMenu: public Menu
{
    SDL_Rect pos0;
    SDL_Rect pos1;
    SDL_Rect pos2;
    SDL_Renderer* gRenderer;
    Texture* texture;
    CancelButton* cancelBtn;
    double mosquitoIterator;
    bool iteratorr;

public:

    std::string buttonText[3];
    MainMenu();
    void HoverClick(SDL_Event*);
    void Show(SDL_Renderer*);
    //void Hover(SDL_Event*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~MainMenu();
};
