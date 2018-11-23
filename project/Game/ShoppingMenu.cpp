#include "ShoppingMenu.h"

ShoppingMenu::ShoppingMenu():Menu()
{
    shoppingPos = new SDL_Rect();
    shoppingPos->x = 200;
    shoppingPos->y = 700;
    shoppingPos->w = 750;
    shoppingPos->h = 150;

    shoppingExitPos.x = 220;
    shoppingExitPos.y = 710;
    shoppingExitPos.w = 25;
    shoppingExitPos.h = 25;

    cancelBtn = new CancelButton(shoppingExitPos);

    tile = new Tile[3];
    tile[0].SetTileText("REPELLENT", "PRICE");
    tile[1].SetTileText("DDT", "PRICE");
    tile[2].SetTileText("WINDOW REPAIR", "PRICE");
    tile[0].UpdatePos(280,710);
    tile[1].UpdatePos(500,710);
    tile[2].UpdatePos(720,710);


}

void ShoppingMenu::Show(SDL_Renderer* gRenderer)
{
   SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
   SDL_RenderFillRect(gRenderer,shoppingPos);
   cancelBtn->Show(gRenderer);

   for (int i=0; i<3; i++)
   {
       tile[i].Show(gRenderer);
   }
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
                    tile[i].tileState =100;
            }
            else
            {
                SetMouseClicked(false);
                tile[i].tileState=0;
            }
        }
        else
        {
            tile[i].tileState=200;
        }

    }


}

ShoppingMenu::~ShoppingMenu()
{

}

