#include "CheckBox.h"

CheckBox::CheckBox():Clickable(0,0,50,50) //inhering from clickable
{
    status = false;
    clickSprite = 84;
}

void CheckBox::ChangeState()
{
    status = !status;
}
void CheckBox::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            if (WithinRegion(mouseX,mouseY))
            {
                ChangeState();


            }
        }
    }
}

void CheckBox::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    if(status)
        texture->Render(121,gRenderer,&pos);
    else
        texture->Render(120,gRenderer,&pos);
}

void CheckBox::Update(int a)
{

}

void CheckBox::SetPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
}


CheckBox::~CheckBox()
{

}
