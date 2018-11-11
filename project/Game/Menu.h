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
    bool mouseClicked;
protected:


public:
    int state=0;
    Menu();
    Menu(int noOfButton, int x, int y);
    ~Menu();
    void Show(SDL_Renderer*);
    void Hover(SDL_Event*);
    void Click(SDL_Event*);
    void SetNoOfButton(int);
    int GetNoOfButton();


};
