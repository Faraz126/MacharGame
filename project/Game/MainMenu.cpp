#include "MainMenu.h"


MainMenu::MainMenu():Menu(3,354,506,false)
{
    pos0.x= 0;
    pos0.y = 0;
    pos0.w = 1024;
    pos0.h = 786;   // for background

    pos1.x = 284;
    pos1.y = 15;
    pos1.w = 435;
    pos1.h = 330; //for mosquito

    pos2.x = 950;
    pos2.y = 10;
    pos2.w = 35;
    pos2.h = 35;    //for cancel button

    mosquitoIterator=43;
    buttonText[0]= "NEW GAME";
    buttonText[1] = "LOAD GAME";
    buttonText[2] = "SETTINGS";

    cancelBtn = new CancelButton(pos2);

    Menu::SetText(buttonText);

}

void MainMenu::HoverClick(SDL_Event* e)
{
    int hoverX = e->button.x;  //for cancel button click
    int hoverY = e->button.y;

    if( cancelBtn->WithinCancelRegion(hoverX,hoverY)==true)
    {
        if (e->type == SDL_MOUSEBUTTONDOWN)
        {
            SetMouseClicked(true);
            cancelBtn->Click();
        }
        else if (e->type == SDL_MOUSEBUTTONUP && e->button.button == SDL_BUTTON_LEFT)
        {
            SetMouseClicked(false);
            cancelBtn->diffStateBtn=4;
        }
        else
        {
            cancelBtn->Hover();
        }
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

}

void MainMenu::Show(SDL_Renderer* gRenderer)
{
    mosquitoIterator +=0.02;
     if (mosquitoIterator>=52)
        mosquitoIterator=43;
    texture = Texture::GetInstance(gRenderer);
    texture->Render(3,gRenderer,&pos0);
    texture->Render(int(mosquitoIterator),gRenderer,&pos1);
    cancelBtn->Show(gRenderer);
    Menu::Show(gRenderer);
}


void MainMenu::Update(int frame)
{

}

void MainMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    //Menu::Hover(e);
    Menu::HoverClick(e);
    HoverClick(e);
    //Hover(e);
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

            if (btn[2].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new Setting;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
            }

            if( cancelBtn->WithinCancelRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new ExitMenu;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;

            }

        }

    }
}


MainMenu::~MainMenu()
{
    delete cancelBtn;
}
