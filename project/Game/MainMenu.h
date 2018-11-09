#pragma once

class MainMenu: public Menu
{
private:
    SDL_Img* menu;
protected:

public:
    MainMenu();
    virtual void Click(SDL_Render*);
    virtual void Show(SDL_Img*);
    ~MainMenu();
};
