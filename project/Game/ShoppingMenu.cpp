#include "ShoppingMenu.h"

ShoppingMenu::ShoppingMenu():Menu()
{
//    shoppingPos = new SDL_Rect();
//    shoppingPos->x = 200;
//    shoppingPos->y = 700;
//    shoppingPos->w = 750;
//    shoppingPos->h = 150;
//
//    repellentPos = new SDL_Rect();
//    repellentPos->x = 280;
//    repellentPos->y = 710;
//    repellentPos->w = 200;
//    repellentPos->h = 65;
//
//    ddtPos = new SDL_Rect();
//    ddtPos->x = 500;
//    ddtPos->y = 710;
//    ddtPos->w = 200;
//    ddtPos->h = 65;
//
//    windowPos = new SDL_Rect();
//    windowPos->x = 720;
//    windowPos->y = 710;
//    windowPos->w = 200;
//    windowPos->h = 65;

    shoppingExitPos.x = 220;
    shoppingExitPos.y = 710;
    shoppingExitPos.w = 25;
    shoppingExitPos.h = 25;

    cancelBtn = new CancelButton(shoppingExitPos);

}

void ShoppingMenu::Show(SDL_Renderer* gRenderer)
{
   SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
   SDL_RenderFillRect(gRenderer,shoppingPos);

   //SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
//   SDL_RenderDrawRect(gRenderer,repellentPos);
//   SDL_RenderDrawRect(gRenderer,ddtPos);
//   SDL_RenderDrawRect(gRenderer,windowPos);
   cancelBtn->Show(gRenderer);
}

void ShoppingMenu::Update(SDL_Event* e, Screens_Node&node)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

    if( cancelBtn->WithinCancelRegion(hoverX,hoverY))
    {
        if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            SetMouseClicked(true);
            cancelBtn->Click();
            shopShow = false;
        }
        else if (e->type == SDL_MOUSEBUTTONUP && e->button.button == SDL_BUTTON_LEFT)
        {
            SetMouseClicked(false);
            cancelBtn->diffStateBtn=4;
        }
        else
        {
            cancelBtn->Hover();
        }
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

}

ShoppingMenu::~ShoppingMenu()
{

}

