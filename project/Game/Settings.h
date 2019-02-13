#pragma once
#include "Texture.h"
#include <iostream>
#include <fstream>
#include <string>
#include "string.h"
#include "CancelButton.h"
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"
#include "MainMenu.h"
#include "Slider.h"

class Setting : public Menu
{
private:
    SDL_Rect* settingPos;
    SDL_Rect* settingSliderPos;
    SDL_Rect* settingSliderPos1;
    SDL_Rect* sliderPos;
    SDL_Rect settingscancelPos;
    SDL_Rect* noVolumePos;
    SDL_Rect* noVolumePos1;
    SDL_Rect* fullVolumePos;
    SDL_Rect* noBrightnessPos;
    SDL_Rect* noBrightnessPos1;
    SDL_Rect* fullBrightnessPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Slider* slider;
    Word* word;
    std::string buttonText[2];
    int vol;

protected:

public:
    Setting(Screens*, bool, bool = false, bool = false, int = 1);
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void SetPosition(int,int);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);


    ~Setting();
};

