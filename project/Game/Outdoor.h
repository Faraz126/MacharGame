#pragma once

class Outdoor
{
private:
    Mosquito* mosquito;
    House* house;
    DirtyWater* dirtywater;
    CleanWater* cleanwater;
    Manhole* manhole;
    Outdoor* outdoor;
protected:

public:
    Outdoor();
    void AddHuman();
    void LeaveHuman();
    void Click();
    void Show(SDL_Render*);
    Entrance* getCurrentState();
    ~Outdoor();
};
