#pragma once
#include "Screens.h"
#include "Button.h"

class Menu: public Screens
{
private:
    int w;
    int h;
    int x;
    int y;
    SDL_Rect* menu;
    Button* btn;
    int noOfButton;
protected:


public:
    Menu();
    Menu(int noOfButton, int x, int y);
    ~Menu();
    Show();
    void SetNoOfButton(int);
    int GetNoOfButton();


};
