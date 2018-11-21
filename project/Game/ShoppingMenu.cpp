#include "ShoppingMenu.h"

ShoppingMenu::ShoppingMenu():Menu()
{
    shoppingPos->x = 100;
    shoppingPos->y = 680;
    shoppingPos->w = 300;
    shoppingPos->h = 200;

}

void ShoppingMenu::Show(SDL_Renderer* gRenderer)
{
   SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
   SDL_RenderFillRect(gRenderer,shoppingPos);
}

void ShoppingMenu::Update(SDL_Event* e, Screens_Node&node)
{

}

ShoppingMenu::~ShoppingMenu()
{

}

