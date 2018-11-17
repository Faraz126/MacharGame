#include "CancelButton.h"

CancelButton::CancelButton()
{
    pos.x = 950;
    pos.y = 10;
    pos.w = 35;
    pos.h = 35;
    diffStateBtn= 4;

    SettingscancelPos.x = 880;
    SettingscancelPos.y = 400;
    SettingscancelPos.w = 35;
    SettingscancelPos.h = 35;


}
CancelButton::CancelButton(int x, int y) : CancelButton()  //after overloaded call that constructor too
{
    x = y = 0;

}

void CancelButton::Render ( SDL_Renderer * gRenderer )
{
    texture = Texture::GetInstance(gRenderer); //singelton here, static method
    texture->Render(diffStateBtn, gRenderer, &pos);



}

void CancelButton::setPosition ( int x, int y)
{
    pos.x = x;              //setting position of buttons on the screen
    pos.y = y;
}

void CancelButton::Hover()
{
    diffStateBtn =0;    // if hovered sprite changed
}

void CancelButton::Click()
{
    diffStateBtn=3;   // if clicked sprite changed

}

bool CancelButton::WithinCancelRegion(int mouseX, int mouseY)
{
    bool inRegion = false;
    if( ( mouseX > pos.x ) && ( mouseX < (pos.x+pos.w) ) && ( mouseY > pos.y ) && (mouseY< (pos.y+pos.h) ) )
        return true;
    else
        return false;
}

