#include "CancelButton.h"

CancelButton::CancelButton(SDL_Rect rect): Clickable(rect.x,rect.y, rect.w,rect.h)
{
    diffStateBtn= 53;  //cancel button sprite number

}


void CancelButton::Show( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(diffStateBtn, gRenderer, &pos);

}


void CancelButton::Hover()
{
    diffStateBtn =54;    // if hovered sprite changed
}





