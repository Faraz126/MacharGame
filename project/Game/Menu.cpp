#include "Menu.h"

Menu::Menu()
{
    w = h = x = y = noOfButton =0;
    menu =0;
    btn = 0;

}

Menu::Menu(int noOfButton, int x, int y)
{
    this->noOfButton =noOfButton;
    btn = new Button[noOfButton];  //an array of buttons with given number of buttons to be made
    this->x = x;
    this->y = y;
    for (int i=0; i<noOfButton; i++)
    {
        btn[i].setPosition(x,y);
        y +=100;
    }


}



Menu::~Menu()
{

}

void Menu::Show(SDL_Renderer* gRenderer)
{
    for(int i=0; i<noOfButton; i++)
    {
         btn[i].render(gRenderer);
    }
}


void Menu::Hover(SDL_Renderer* gRenderer)
{
    SDL_Event e;
    int hoverX = e.button.x;
    int hoverY = e.button.y;
    if(e.type == SDL_MOUSEMOTION)
    {
        if( ( hoverX > btn->pos.x ) && ( hoverX < (btn->pos.x+btn->pos.w) ) && ( hoverY > btn->pos.y ) && (hoverY< (btn->pos.y+btn->pos.h) ) )
        {
            //SDL_SetTextureColorMod(texture,250,153,255);
            btn->Hover(gRenderer);
        }
    }
}
