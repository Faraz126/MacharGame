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
#include "Tile.h"
class House;


class ShoppingMenu : public Menu
{
private:
    SDL_Rect* shoppingPos;
    SDL_Rect* repellentPos;
    SDL_Rect* ddtPos;
    SDL_Rect* windowPos;
    SDL_Rect shoppingExitPos;
    bool shopShow;

    Texture* texture;
    CancelButton* cancelBtn;
    Tile* tile;
    House* house;

protected:

public:
    void SetShopShow(bool);
    bool GetShopShow();
    ShoppingMenu();
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void SetPosition(int,int);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    int GetShoppingExitPosX();
    int GetShoppingExitPosY();
    int GetShoppingExitPosW();
    int GetShoppingExitPosH();

    ~ShoppingMenu();
};

