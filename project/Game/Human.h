/*
#pragma once
#include <iostream>
#include "Color.h"
#include "Point.h"
#include "Texture.h"
#include "Mosquito.h"

class House;

class Human
{
private:

    bool infected;
    bool wearRepellant;
    bool IsOutdoor;
    bool IsIndoor;
    Color* skin;
    SDL_Rect position;
    House* house;
//    Hospital* hospital;
    int clip;
    double speed;

protected:

public:
    Human();
    Human(House*);
    ~Human();
    void Walk();    // when human walks
    void WalkOpposite(); // walking opposite
    void Walking();      // Walking
    bool Sit();     // when human sits
    bool LieDown();   // when human lies down
    bool EnterHouse();
    bool LeaveHouse();
    void SetOutdoorIndoor();
    bool GetIsOutdoor();
    bool GetIsIndoor();
    int GetBedPosition();                          // So that human can walk and go to the right bed and lie down if not infected
    //void Routine(SDL_Rect*,SDL_Renderer*,Texture*);
    int GetXPosition();
    int GetYPosition();
    void Update();
    //void setPosition(Point*);
    void MosquitoBite();
    void BackToNormal();
    void HumanRender(SDL_Renderer*);
};

*/
