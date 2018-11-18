#include "CancelButton.h"

CancelButton::CancelButton(SDL_Rect rect)
{
    pos.x = rect.x ;
    pos.y = rect.y;
    pos.w = rect.w;
    pos.h = rect.h;
    diffStateBtn= 38;



}
CancelButton::CancelButton(int x, int y)   //after overloaded call that constructor too
{
    x = y = 0;

}

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
    diffStateBtn=39;   // if clicked sprite changed

}

bool CancelButton::WithinCancelRegion(int mouseX, int mouseY)
{
    bool inRegion = false;
    if( ( mouseX > pos.x ) && ( mouseX < (pos.x+pos.w) ) && ( mouseY > pos.y ) && (mouseY< (pos.y+pos.h) ) )
        return true;
    else
        return false;
}

