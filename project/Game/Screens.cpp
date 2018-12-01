#include "Screens.h"
#include <SDL.h>
#include <SDL_image.h>

Screens* Screens::curScreen = 0;

Screens::Screens(Screens* prevScreen, bool back, bool show, bool update, int factor)
{
    if (prevScreen != 0 && !back)
    {
        delete prevScreen;
        this->prevScreen = 0;
        this->prevUpdateable = this->prevShowable = this->prevBackable = false;
    }
    else
    {
        this->prevScreen = prevScreen;
        this->prevUpdateable = update;
        this->prevShowable = update;
        this->prevUpdateFactor = factor;
    }

}

void Screens::Show(SDL_Renderer* renderer)
{
    if (this->prevShowable)
    {
        this->prevScreen->Show();
    }
}




void Screens::HandleEvents(SDL_Event* e, Screens_Node& node)
{

}

void Screens::Update(int frame)
{
    if (this->prevUpdateable && (frame % this->prevUpdateFactor) == 0)
    {
        this->prevScreen->Update(int);
    }
}


Screens::~Screens()
{
    if (prevScreen != 0)
    {
        delete prevScreen;
    }
}
