#include "MainMenu.h"


MainMenu::MainMenu():Menu(3,354,506)
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
    pos2.h = 35;

    mosquitoIterator=4;
    buttonText[0]= "NEW GAME";
    buttonText[1] = "LOAD GAME";
    buttonText[2] = "SETTINGS";

    cancelBtn = new CancelButton();

    Menu::SetText(buttonText);

}

void MainMenu::Click(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if( ( hoverX > pos2.x ) && ( hoverX < (pos2.x+pos2.w) ) && ( hoverY > pos2.y ) && (hoverY< (pos2.y+pos2.h) ) )
            {
                std::cout<<"before click";
                cancelBtn->Click();

            }
            else
            {
                cancelBtn->diffStateBtn=4;
            }
        }
    }

}

void MainMenu::Hover(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEMOTION)
    {
        if( ( hoverX > pos2.x ) && ( hoverX < (pos2.x+pos2.w) ) && ( hoverY > pos2.y ) && (hoverY< (pos2.y+pos2.h) ) )
        {
            std::cout<<"hover";
            cancelBtn->Hover();
        }
        else
        {
            cancelBtn->diffStateBtn=4;
        }

    }

}



void MainMenu::Show(SDL_Renderer* gRenderer)
{
    mosquitoIterator +=0.03;
     if (mosquitoIterator>=8)
        mosquitoIterator=4;
    texture = Texture::GetInstance(gRenderer);
    texture->Render(3,gRenderer,&pos0);
    texture->Render(int(mosquitoIterator),gRenderer,&pos1);
    cancelBtn->Render(gRenderer);


    Menu::Show(gRenderer);
}


void MainMenu::Update(SDL_Event* e, Screens_Node& node)
{
    Menu::Hover(e);
    Click(e);
    Hover(e);
    if(e->type == SDL_MOUSEBUTTONUP || e->type == SDL_MOUSEBUTTONDOWN)
        Menu::Click(e);
}

MainMenu::~MainMenu()
{

}
