#include "Button.h"

Button::Button() : Clickable(354,506,314,64)
{

    intHover = 0;  //which state of button
    word = 0;
    buttonSprite = true;
    sprite2 = 123;

}
Button::Button( std::string str , int x, int y) : Button()  //after overloaded call that constructor too
{
    x = y = 0;
    word = new Word(str,x+15,y+15);

}

void Button::Show( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    if(buttonSprite)
    {
        texture->Render(intHover, gRenderer, &pos);
    }
    if(!buttonSprite)
    {
        texture->Render(sprite2, gRenderer, &pos);
    }

    word->Show(gRenderer);


}

void Button::setPosition ( int x, int y)
{
    pos.x = x;              //setting position of buttons on the screen
    pos.y = y;
}
void Button::SetWidth(int w,int h)
{
    pos.w = w;
    pos.h = h;
}

void Button::setText ( std::string str )
{
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

    if(!buttonSprite)
    {
        sprite2 = 124;
    }
}

void Button::Click()
{
    intHover=2;   // if clicked sprite changed
}

void Button::SetButtonSprite(bool sprite)
{
    buttonSprite = sprite;
}

Button::~Button()
{
    delete word;
}
