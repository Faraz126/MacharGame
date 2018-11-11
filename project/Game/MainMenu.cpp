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



}

void MainMenu::Click(SDL_Renderer*)
{

}

void MainMenu::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(3,gRenderer,&pos0);
    texture->Render(4, gRenderer, &pos1);
    Menu::Show(gRenderer);
}


void MainMenu::MouseEvent(SDL_Event* e)
{
    Menu::Hover(e);
}

MainMenu::~MainMenu()
{

}
