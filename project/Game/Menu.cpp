#include "Menu.h"

Menu::Menu()
{
    w = h = x = y = noOfButton =0;
    menu =0;
    btn = 0;
    mouseClicked = false;

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


void Menu::Hover(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEBUTTONDOWN ||e->type == SDL_MOUSEMOTION)
    {
        for(int i=0; i<noOfButton; i++)
        {
             if( ( hoverX > btn[i].pos.x ) && ( hoverX < (btn[i].pos.x+btn[i].pos.w) ) && ( hoverY > btn[i].pos.y ) && (hoverY< (btn[i].pos.y+btn[i].pos.h) ) )
            {
                btn[i].Hover();
            }
            else
            {
                btn[i].intHover=0;
            }
        }
    }

}

void Menu::Click(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEBUTTONDOWN)
    {

        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            mouseClicked = true;
            for(int i=0; i<noOfButton; i++)
            {
                 if( ( hoverX > btn[i].pos.x ) && ( hoverX < (btn[i].pos.x+btn[i].pos.w) ) && ( hoverY > btn[i].pos.y ) && (hoverY< (btn[i].pos.y+btn[i].pos.h) ) )
                {

                    btn[i].Click();
                }
                else
                {
                    btn[i].intHover=0;
                }
            }
        }
    }

}
