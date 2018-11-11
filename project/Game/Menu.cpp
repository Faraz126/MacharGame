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


//make a show function which displays all the buttons
