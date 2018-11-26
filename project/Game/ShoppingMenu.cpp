#include "ShoppingMenu.h"

ShoppingMenu::ShoppingMenu():Menu()
{
    shoppingPos = new SDL_Rect();
    shoppingPos->x = 80;
    shoppingPos->y = 700;
    shoppingPos->w = 855;
    shoppingPos->h = 150;

    shoppingExitPos.x = 900;
    shoppingExitPos.y = 710;
    shoppingExitPos.w = 25;
    shoppingExitPos.h = 25;


    cancelBtn = new CancelButton(shoppingExitPos);

    tile = new Tile[3];
    tile[0].SetTileText("REPELLENT", "PRICE");
    tile[1].SetTileText("DDT", "PRICE");
    tile[2].SetTileText("REPAIR", "PRICE");
    tile[0].UpdatePos(100,710);
    tile[1].UpdatePos(370,710);
    tile[2].UpdatePos(640,710);



}

void ShoppingMenu::Show(SDL_Renderer* gRenderer)
{
   SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
   SDL_RenderFillRect(gRenderer,shoppingPos);
   cancelBtn->Show(gRenderer);
/*
   for (int i=0; i<3; i++)
   {
       if (i==0)
        tile[i].Show(gRenderer,75);
       if (i==1)
        tile[i].Show(gRenderer,76);
       if (i==2)
        tile[i].Show(gRenderer,13);
   }
*/


}


void ShoppingMenu::Update(int frame)
{

}

void ShoppingMenu::HandleEvents(SDL_Event* e, Screens_Node&node)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

    if( cancelBtn->WithinRegion(hoverX,hoverY))
    {
        if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            shopShow = false;    //if false close shopping menu
        }
        else
        {
            cancelBtn->Hover();  //changing state at hover
        }
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

    for(int i=0; i<3; i++)    //mouse events for tiles
    {
        if (tile[i].WithinRegion(hoverX,hoverY))
        {
           if (e->type == SDL_MOUSEBUTTONDOWN)
            {
                SetMouseClicked(true);
                if(e->button.button == SDL_BUTTON_LEFT)
                    tile[i].tileState =200;
            }
            else
            {
                SetMouseClicked(false);
                tile[i].tileState=150;
            }
        }
        else
        {
            tile[i].tileState=100;
        }

    }


}

ShoppingMenu::~ShoppingMenu()
{
    delete[] tile;
    delete cancelBtn;
    delete shoppingPos;
}

