#include "ShoppingMenu.h"

ShoppingMenu::ShoppingMenu():Menu()
{
    shoppingPos = new SDL_Rect();
    shoppingPos->x = 250;
    shoppingPos->y = 700;
    shoppingPos->w = 700;
    shoppingPos->h = 150;


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

