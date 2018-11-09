#pragma once

class LoadMenu : public Menu
{
private:
    SDL_Img* menu;
protected:

public:
    LoadMenu();
    LoadGame* loadgame;
    virtual void Click(SDL_Render*);
    virtual void Show(SDL_Img*);
    ~LoadMenu();
};

