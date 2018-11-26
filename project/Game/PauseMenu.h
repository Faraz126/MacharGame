#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "MainMenu.h"
#include "Slider.h"
#include "Closing.h"
#include "CancelButton.h"


class PauseMenu :public Menu
{
    private:
    SDL_Rect* pausePos;
    SDL_Rect pauseCancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;
    std::string buttonText[4];

protected:

public:
    PauseMenu();
    void HoverClick(SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~PauseMenu();
};

