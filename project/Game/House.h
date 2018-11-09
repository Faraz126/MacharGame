#pragma once

class House
{
private:
    Money money;
    bool hasRepellent;
    int noOfHumans;
    Bed bed*;
    SDL_Img* house;
    Outdoor* outdoor;
    Door* door;
protected:

public:
    House();
    ~House();
    bool GetHasRepellent();
    void AddHuman();
    void LeaveHuman();
    void click();
    void Show();
    void getWindowState();
    void getEntranceState();
};
