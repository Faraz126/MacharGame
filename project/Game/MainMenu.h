#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"

#include "string"
#include "Outdoor.h"
#include "Settings.h"
#include "ExitMenu.h"
#include <fstream>
#include <sstream>
#include <ostream>
#include <istream>
#include <iostream>



class MainMenu: public Menu
{
    SDL_Rect pos0;
    SDL_Rect pos1;
    SDL_Rect pos2;
    //SDL_Renderer* gRenderer;
    Texture* texture;
    CancelButton* cancelBtn;
    double mosquitoIterator;
    bool iteratorr;
    std::string buttonText[3];


public:

    MainMenu(Screens*, bool);
    void HoverClick(SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~MainMenu();
};
