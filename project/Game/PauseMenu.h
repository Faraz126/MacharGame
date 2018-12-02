#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Slider.h"
#include "Closing.h"
#include "CancelButton.h"
#include "SaveScreen.h"
#include "Outdoor.h"


class PauseMenu :public Menu
{
    private:
    SDL_Rect* pausePos;
    SDL_Rect pauseCancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;
    std::string buttonText[4];
    Outdoor* outdoor;

protected:

public:
    PauseMenu(Outdoor*);
    void HoverClick(SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~PauseMenu();
};
