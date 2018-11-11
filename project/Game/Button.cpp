#include "Button.h"

Button::Button()
{
    pos.x = 354;
    pos.y = 506;
    pos.w = 314;
    pos.h = 64;
    intHover = 0;

}
Button::Button( Texture * texture , std::string str , int x, int y)
{
    texture = 0;
    str = " ";
    x = y = 0;
}

void Button::render ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(intHover, gRenderer, &pos);
    if (intHover==2)
        intHover=0;


}

void Button::setPosition ( int x, int y)
{
    pos.x = x;              //setting position of buttons on the screen
    pos.y = y;
}
void Button::setText ( std::string str )
{

}

void Button::Hover()
{
    intHover=1;     // if hovered sprite changed
}

void Button::Click()
{
    intHover=2;   // if clicked sprite changed
}


