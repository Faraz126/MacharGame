#include "ShoppingMenu.h"
#include "House.h"

ShoppingMenu::ShoppingMenu():Menu()
{
    shoppingPos = new SDL_Rect();
    shoppingPos->x = 20;
    shoppingPos->y = 680;
    shoppingPos->w = 925;
    shoppingPos->h = 100;

    shoppingExitPos.x = 910;
    shoppingExitPos.y = 690;
    shoppingExitPos.w = 25;
    shoppingExitPos.h = 25;


    cancelBtn = new CancelButton(shoppingExitPos);

    tile = new Tile[4];  //setting the position and text for each tile
    tile[0].UpdatePos(40,700);
    tile[1].UpdatePos(260,700);
    tile[2].UpdatePos(480,700);
    tile[3].UpdatePos(700,700);

    tile[0].SetValues(0);
    tile[0].SetTileText();
    tile[1].SetValues(1);
    tile[1].SetTileText();
    tile[2].SetValues(2);
    tile[2].SetTileText();
    tile[3].SetValues(3);
    tile[3].SetTileText();

    house = new House;

}


void ShoppingMenu::Show(SDL_Renderer* gRenderer)
{
   SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
   SDL_RenderFillRect(gRenderer,shoppingPos);
   cancelBtn->Show(gRenderer);
   for(int i=0; i<4; i++)
   {
       tile[i].Show(gRenderer);  //rendering all tiles
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

    for(int i=0; i<4; i++)    //mouse events for tiles
    {
        if (tile[i].WithinRegion(hoverX,hoverY))
        {
           if (e->type == SDL_MOUSEBUTTONDOWN)
            {
                SetMouseClicked(true);
                if(e->button.button == SDL_BUTTON_LEFT)
                    tile[i].tileState =200;
                    //tile[i].buy->Apply(house);
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

int ShoppingMenu::GetShoppingExitPosX()
{
    return shoppingExitPos.x;
}

int ShoppingMenu::GetShoppingExitPosY()
{
    return shoppingExitPos.y;
}

int ShoppingMenu::GetShoppingExitPosW()
{
    return shoppingExitPos.w;
}

int ShoppingMenu::GetShoppingExitPosH()
{
    return shoppingExitPos.h;
}
void ShoppingMenu::SetShopShow(bool show)
{
    shopShow = show;
}
bool ShoppingMenu::GetShopShow()
{
    return shopShow;
}
ShoppingMenu::~ShoppingMenu()
{
    delete[] tile;
    delete cancelBtn;
    delete shoppingPos;
}

