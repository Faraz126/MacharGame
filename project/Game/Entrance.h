#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Texture.h"
#include "Screens.h"
#include "Clickable.h"

class Entrance : public Clickable
{
private:
    bool state;
    Scenario* outdoorPtr;
protected:
    int spriteNum;
    SDL_Rect outdoorPos;


public:
    void SetOutdoorPos(int,int,int, int);
    Entrance(int,int,int,int);
    void GetOutdoorPos(int& , int& );
    SDL_Rect& GetOutdoorRect();
    virtual void Show(SDL_Renderer*) = 0;
    virtual void ShowOutside(SDL_Renderer*) = 0;
    virtual bool IsOpen() = 0;
    void SetState();
    void MosquitoEnter();
    void SetOutdoorX(int,int);
    //bool WithinEntrance(int, int); //returns true if the given x,y co-ordinate is within the entrance.
    int GetDistanceOutside(int, int);
    int GetX(bool);
    int GetY(bool);
    int GetHeight();
    int GetWidth();
    virtual void Update(int) = 0;
    virtual void ChangeState() = 0;
    virtual ~Entrance();
    void SetOutdoor(Scenario*);
    Scenario* GetOutdoor();

};


