#include "Button.h"

Button::Button()
{
    pos.x = 354;
    pos.y = 506;
    pos.w = 314;
    pos.h = 64;
    intHover = 0;
    word = 0;

}
Button::Button( std::string str , int x, int y) : Button()  //after overloaded call that constructor too
{
    x = y = 0;
    word = new Word(str,x+15,y+15);

}

void Button::Render ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(intHover, gRenderer, &pos);
    word->Show(gRenderer);


}

void Button::setPosition ( int x, int y)
{
    pos.x = x;              //setting position of buttons on the screen
    pos.y = y;
}
void Button::setText ( std::string str )
{
    std::cout << str;
    std::cout << str.length();
    if (word == 0)
    {
        word = new Word(str, pos.x +(pos.w-(25*str.length()))/2, pos.y+15);
    }
    else
    {
        word->SetText(str);
    }

}

void Button::Hover()
{
    intHover=1;     // if hovered sprite changed
}

void Button::Click()
{
    intHover=2;   // if clicked sprite changed
}


