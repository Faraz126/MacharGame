#include "Menu.h"

Menu::Menu()
{
    w = h = x = y = noOfButton =0;
    menu =0;
    btn = 0;
    mouseClicked = false;
    horizontal = false;

}

Menu::Menu(int noOfButton, int x, int y, bool horizontal)
{
    this->noOfButton =noOfButton;
    btn = new Button[noOfButton];  //an array of buttons with given number of buttons to be made
    this->x = x;
    this->y = y;
    for (int i=0; i<noOfButton; i++)
    {
        btn[i].setPosition(x,y);
        if (horizontal ==false)
        {
             y +=100;
        }


        if (horizontal == true)
        {
            x+=350;
        }

    }
}

Menu::~Menu()
{
    delete[] btn;
}

void Menu::Show(SDL_Renderer* gRenderer)
{
    for(int i=0; i<noOfButton; i++)
    {
         btn[i].Render(gRenderer);
    }
}


void Menu::HoverClick(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    for(int i=0; i<noOfButton; i++)
    {
        if( ( hoverX > btn[i].pos.x ) && ( hoverX < (btn[i].pos.x+btn[i].pos.w) ) && ( hoverY > btn[i].pos.y ) && (hoverY< (btn[i].pos.y+btn[i].pos.h) ))

        {
            if(e->type == SDL_MOUSEBUTTONDOWN && e->button.button ==  SDL_BUTTON_LEFT)
            {
                mouseClicked = true;
                if(e->type == SDL_MOUSEBUTTONDOWN)
                {
                    btn[i].Click();
                }
            }
            else if (e->type == SDL_MOUSEBUTTONUP && e->button.button == SDL_BUTTON_LEFT)
            {
                SetMouseClicked(false);
                btn[i].intHover=1;
            }
            else
            {
                btn[i].Hover();
            }
        }
        else
        {
            btn[i].intHover = 0;
        }

    }

}

void Menu::SetText(std::string* buttonText)
{
    for (int i=0; i < noOfButton; i++)
    {

        btn[i].setText(buttonText[i]);
    }
}

void Menu::SetMouseClicked(bool clicked)
{
    this->mouseClicked = clicked;
}

bool Menu::GetMouseClicked()
{
    return mouseClicked;
}
