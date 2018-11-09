#pragma once

class Setting : public Menu
{
private:
    SDL_Img* menu;
protected:

public:
    Settings();
    virtual void Click(SDL_Render*);
    virtual void Show(SDL_Img*);
    ~Settings();
};

