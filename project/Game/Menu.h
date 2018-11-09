#pragma once

class Menu: public Screens
{
private:
    int w;
    int h;
    SDL_Rect* menu;
protected:


public:
    Menu();
    ~Menu();

};
