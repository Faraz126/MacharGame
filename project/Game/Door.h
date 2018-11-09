#pragma once

class Door:public Entrance
{
private:
    time TimeCovered;
protected:

public:
    Door();
    void Show(SDL_Render*);
    time SetTime();
    ~Door();
};
