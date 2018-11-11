#include "Button.h"



Button::Button( Texture * Texture , std::string str , int x, int y)
{

}

void Button::render ( SDL_Renderer * gRenderer )
{
    pos.x = 1;
    pos.y =2;
    pos.w= 200;
    pos.h = 200;
    texture->Render(0,gRenderer,pos);   //should render first image from sprite at the given pos
}

void Button::setPosition ( int x, int y)
{

}
void Button::setText ( std::string str )
{

}
void Button::Click()
{

}



