#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Closing.h"
class Outdoor;

class ExitMenu :public Menu
{
    private:
    SDL_Rect* exitPos;
    SDL_Rect exitCancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;
    std::string buttonText[2];



protected:

public:
    ExitMenu(Screens*, bool, bool = false, bool = false, int = 1);
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    void SetOutdoor(Outdoor*);
    ~ExitMenu();
};
