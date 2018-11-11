#include "Button.h"
#include <iostream>


Button::Button()
{
    pos.x = 354;
    pos.y = 506;
    pos.w = 314;
    pos.h = 64;

}
Button::Button( Texture * texture , std::string str , int x, int y)
{
    texture = 0;
    str = " ";
    x=y=0;
}

void Button::render ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(0, gRenderer, &pos);


}

void Button::setPosition ( int x, int y)
{
    pos.x = x;
    pos.y = y;
}
void Button::setText ( std::string str )
{

}
void Button::Click()
{

}
void Button::Hover(SDL_Renderer * gRenderer)
{
    texture->Render(1, gRenderer, &pos);
}



