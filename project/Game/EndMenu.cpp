#include "EndMenu.h"


EndMenu::EndMenu():Menu(3,80,250,false)
{
    pos0 = new SDL_Rect;
    pos0->x= 0;
    pos0->y = 0;
    pos0->w = 1024;
    pos0->h = 786;   // for background

    pos2.x = 950;
    pos2.y = 10;
    pos2.w = 35;
    pos2.h = 35;    //for cancel button


    buttonText[0]= "RESTART";
    buttonText[1] = "MAIN MENU";
    buttonText[2] = "LOAD GAME";

    cancelBtn = new CancelButton(pos2);

    Menu::SetText(buttonText);

}

void EndMenu::HoverClick(SDL_Event* e)
{
    int hoverX = e->button.x;  //for cancel button click
    int hoverY = e->button.y;

    if( cancelBtn->WithinRegion(hoverX,hoverY)==true)
    {
        cancelBtn->Hover();
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

}

void EndMenu::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(78,gRenderer,pos0);
    cancelBtn->Show(gRenderer);
    Menu::Show(gRenderer);
}


void EndMenu::Update(int frame)
{

}

void EndMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::HoverClick(e);
    HoverClick(e);
    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {

        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new Outdoor;
                node.prev_screen = this;
                node.prev_backable = false;  //outdoor screen will open

            }

            if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new MainMenu;
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
            }

            if( cancelBtn->WithinRegion(mouseX, mouseY))
            {
                node.cur_screen = new ExitMenu;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;

            }

        }

    }
}


EndMenu::~EndMenu()
{
    delete cancelBtn;
    delete pos0;
}

