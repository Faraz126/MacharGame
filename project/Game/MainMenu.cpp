#include "MainMenu.h"

MainMenu::MainMenu():Menu(3,pos.x,pos.y)
{
    pos.x= 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;   // for background


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
    texture = Texture::GetInstance(gRenderer);
    texture->Render(1,gRenderer,&pos);
    texture->Render(0, gRenderer, &pos1);
    Menu::Show();
}

MainMenu::~MainMenu()
{

}
