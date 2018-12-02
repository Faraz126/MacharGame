#include "Screens.h"
#include <SDL.h>
#include <SDL_image.h>
#include "MainMenu.h"

Screens* Screens::curScreen = nullptr;

void Screens::Initiate()
{
    curScreen = new MainMenu(0, false);
}

Screens::Screens(Screens* prevScreen, bool back, bool show, bool update, int factor)
{
    if (prevScreen != 0 && !back)
    {
        delete prevScreen;
        this->prevScreen = 0;
        this->prevUpdateable = this->prevShowable = false;
    }
    else
    {
        this->prevScreen = prevScreen;
        this->prevUpdateable = update;
        this->prevShowable = show;
        this->prevUpdateFactor = factor;
    }

}

void Screens::Show(SDL_Renderer* renderer)
{
    if (this->prevShowable)
    {
        this->prevScreen->Show(renderer);
    }
}




void Screens::HandleEvents(SDL_Event* e, Screens_Node& node)
{

}

void Screens::Update(int frame)
{
    if (this->prevUpdateable && (frame % this->prevUpdateFactor) == 0)
    {
        this->prevScreen->Update(frame);
    }
}


Screens::~Screens()
{

}
