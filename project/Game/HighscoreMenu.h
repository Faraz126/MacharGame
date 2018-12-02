#pragma once
#include "Texture.h"
#include <iostream>
#include <string>
#include "string.h"
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"
#include "MainMenu.h"


class Highscore : public Menu
{
private:
    SDL_Rect* highscorePos;
    SDL_Rect highscoreCancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;


protected:

public:
    Highscore();
    void Show(SDL_Renderer*);
    void Update(int );
    void HandleEvents(SDL_Event*, Screens_Node&);
    ~Highscore();
    void ClickAndHover(SDL_Event* e);
};


