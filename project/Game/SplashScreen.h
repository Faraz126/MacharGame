#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>


class SplashScreen
{
    Texture* texture;
    SDL_Rect pos;
    SDL_Texture* sdTexture;
    SDL_Rect pos2;
public:
    SplashScreen();
    void Show(SDL_Renderer* gRenderer);
    ~SplashScreen();
};


