#pragma once

class Window :public Entrance
{
private:
    time TimeCovered;
protected:

public:
    Window();
    void Show(SDL_Render*);
    time SetTime();
    ~Window();
};
