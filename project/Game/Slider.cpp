#include "Slider.h"

Slider::Slider()
{
    sliderPos.x= 500;
    sliderPos.y= 475;
    sliderPos.w = 20;
    sliderPos.h = 20;
    diffStateBtn= 0;
}

void Slider::Show( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(diffStateBtn, gRenderer, &sliderPos);
}

void Slider::Click()
{
    diffStateBtn = 26;
}

void Slider::Hover()
{
    diffStateBtn = 30;
}


bool Slider::WithinSliderRegion(int mouseX, int mouseY)
{
    bool inRegion = false;
    if( ( mouseX > sliderPos.x ) && ( mouseX < (sliderPos.x+sliderPos.w) ) && ( mouseY > sliderPos.y ) && (mouseY< (sliderPos.y+sliderPos.h) ) )
        return true;
    else
        return false;
}
