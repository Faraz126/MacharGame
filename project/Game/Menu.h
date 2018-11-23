#pragma once
#include "Screens.h"
#include "Button.h"
#include "Texture.h"
//#include <iostream>
#include <string>
#include "string.h"

class Menu: public Screens
{
private:
    int x,y,w,h;
    SDL_Rect* menu;
    int noOfButton;
    Texture* texture;
    bool mouseClicked;
    bool horizontal;
protected:
    Button* btn;

public:
    int state=0;
    Menu();
    Menu(int,int,int,bool);
    ~Menu();
    void Show(SDL_Renderer*);
    //void Hover(SDL_Event*);
    void HoverClick(SDL_Event*);
    void SetNoOfButton(int);
    int GetNoOfButton();
    void SetMouseClicked(bool);
    bool GetMouseClicked();
    void SetText(std::string*);

};
