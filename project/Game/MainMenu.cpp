#include "MainMenu.h"

MainMenu::MainMenu()
{
    pos.x= 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;   // for background

    Menu(GetNoOfButton(),pos.x,pos.y); //when mainMenu will form MEnu will form with 3 buttons

    pos1.x = 284;
    pos1.y = 15;
    pos1.w = 435;
    pos1.h = 330; //for mosquito

    gRenderer=0;

}

void MainMenu::Click(SDL_Renderer*)
{

}

void MainMenu::Show(SDL_Renderer*)
{
    texture->Render(3,gRenderer,&pos);
    texture->Render(4, gRenderer, &pos1);
    Menu::Show();
}
MainMenu::~MainMenu()
{

}
