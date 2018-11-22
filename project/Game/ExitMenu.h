#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Slider.h"
#include "Closing.h"


class ExitMenu :public Menu
{
    private:
    SDL_Rect* exitPos;
    SDL_Rect exitCancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Slider* slider;
    Word* word;

protected:

public:
    ExitMenu();
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void SetPosition(int,int);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    std::string buttonText[2];
    ~ExitMenu();
};
