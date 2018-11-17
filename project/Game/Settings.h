#pragma once
#include "Texture.h"
#include <iostream>
#include <string>
#include "string.h"
#include "CancelButton.h"
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "CancelButton.h"

class Setting : public Menu
{
private:
    SDL_Rect* settingPos;
    SDL_Rect* cancelPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;
protected:

public:
    Setting();
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void SetPosition(int,int);
    void Update(SDL_Event*, Screens_Node&);
    std::string buttonText[2];

    ~Setting();
};

