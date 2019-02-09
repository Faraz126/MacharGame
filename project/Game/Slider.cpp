#include "Slider.h"

Slider::Slider()
{
    sliderPos.x= 0;
    sliderPos.y= 0;
    sliderPos.w = 47 * 0.7;
    sliderPos.h = 50 * 0.7;
    mouseClicked = false;
}

void Slider::Show( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(61, gRenderer, &sliderPos);
}


bool Slider::WithinSliderRegion(int mouseX, int mouseY)
{
    if( ( mouseX > sliderPos.x ) && ( mouseX < (sliderPos.x+sliderPos.w) ) && ( mouseY > sliderPos.y ) && (mouseY< (sliderPos.y+sliderPos.h) ) )
        return true;
    else
        return false;
}

void Slider::SetMouseClicked(bool clicked)
{
    this->mouseClicked = clicked;
}

bool Slider::GetMouseClicked()
{
    return mouseClicked;
}
void Slider::setPosition ( int x, int y)
{
    sliderPos.x = x;              //setting position of buttons on the screen
    sliderPos.y = y;
}

Slider::~Slider()
{

}

void Slider::SetSliderPosX(int x)
{
    this->sliderPos.x = x;;
}

int Slider::GetSliderPosX()
{
    return sliderPos.x;
}


