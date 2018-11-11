#pragma once
#include "Screens.h"
#include "Button.h"
#include "Texture.h"

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
    Texture* texture;
protected:


public:
    Menu();
    Menu(int noOfButton, int x, int y);
    ~Menu();
    void Show(SDL_Renderer*);
    void Hover(SDL_Renderer* gRenderer);
    void SetNoOfButton(int);
    int GetNoOfButton();


};
