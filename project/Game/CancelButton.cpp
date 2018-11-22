#include "CancelButton.h"

CancelButton::CancelButton(SDL_Rect rect): Clickable(rect.x,rect.y, rect.w,rect.h)
{
    diffStateBtn= 53;



}
/*
CancelButton::CancelButton(int x, int y)   //after overloaded call that constructor too
{
    x = y = 0;

}
*/

void CancelButton::Show( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(diffStateBtn, gRenderer, &pos);

}


void CancelButton::Hover()
{
    diffStateBtn =4;    // if hovered sprite changed
}

void CancelButton::Click()
{
    diffStateBtn=54;   // if clicked sprite changed

}



