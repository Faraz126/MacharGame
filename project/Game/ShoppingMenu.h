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

class ShoppingMenu : public Menu
{
private:
    SDL_Rect* shoppingPos;
    Texture* texture;
    CancelButton *cancelBtn;
    Word* word;

protected:

public:
    ShoppingMenu();
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void SetPosition(int,int);
    void Update(SDL_Event*, Screens_Node&);

    ~ShoppingMenu();
};

