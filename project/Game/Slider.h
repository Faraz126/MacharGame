#pragma once
#include <stdio.h>
#include "Texture.h"
#include "SDL.h"
#include "SDL_image.h"


class Slider
{
private:
    int value;
    Texture * texture ;
    SDL_Event e;
protected:

public:
    Slider();
    int GetValue();
    void SetValue(int);
    void Show(SDL_Renderer*);
    ~Slider();
    void Click();
    void Hover();
    bool WithinSliderRegion(int, int);
    int diffStateBtn;
    SDL_Rect sliderPos;

};

