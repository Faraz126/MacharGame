#pragma once
#include <iostream>
#include "Color.h"
#include "Point.h"
#include "Texture.h"
#include "Mosquito.h"
#include "Clickable.h"

class House;



class Human: Clickable
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
    double clip;
    int otherclip;
    bool IsWalkingHorizontal;
    bool IsWalkingVertical;
    bool IsSitting;
    bool IsLyingDown;
    double speed;
    bool Right;
    bool Left;
    bool Up;
    bool Down;


protected:

public:
    Human();
    Human(House*);
    ~Human();
    void Walk();    // when human walks
    void WalkOpposite(); // walking opposite
    void Walking();      // Walking
    void SitOnBed();     // when human sits
    void LieDown();   // when human lies down
    void WalkAgain();
    void WalkUp();
    void WalkDown();
    void EnterHouse();
    void LeaveHouse();
    void SetOutdoorIndoor();
    int GetBedXPosition();                          // So that human can walk and go to the right bed and lie down if not infected
    int GetBedYPosition();                          // So that human can walk and go to the right bed and lie down if not infected
    //void Routine(SDL_Rect*,SDL_Renderer*,Texture*);
    int GetXPosition();
    int GetYPosition();
    void Update();
    //void setPosition(Point*);
    void MosquitoBite();
    void BackToNormal();
    void HumanRender(SDL_Renderer*,int,bool);
    void Show(SDL_Renderer*);
};

