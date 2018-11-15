#include "CancelButton.h"

CancelButton::CancelButton()
{
    pos.x = 900;
    pos.y = 50;
    pos.w = 150;
    pos.h = 50;
    diffStateBtn= 0;

}
CancelButton::CancelButton(int x, int y) : CancelButton()  //after overloaded call that constructor too
{
    x = y = 0;

}

void CancelButton::Render ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(4, gRenderer, &pos);



}

void CancelButton::setPosition ( int x, int y)
{
    pos.x = x;              //setting position of buttons on the screen
    pos.y = y;
}

void CancelButton::Hover()
{
    diffStateBtn =0;    // if hovered sprite changed
}

void CancelButton::Click()
{
    diffStateBtn=3;   // if clicked sprite changed
}



