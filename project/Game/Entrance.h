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

protected:
    int spriteNum;


public:
    SDL_Rect OutdoorPos;
    void SetOutdoorPos(int,int,int, int);
    Entrance(int,int,int,int);
    virtual void Show(SDL_Renderer*, SDL_Rect* rect = nullptr) = 0;
    virtual void ShowOutside(SDL_Renderer*, const SDL_Rect&, float) = 0;
    virtual bool IsOpen() = 0;
    void SetState();
    void MosquitoEnter();
    //bool WithinEntrance(int, int); //returns true if the given x,y co-ordinate is within the entrance.
    int GetX();
    int GetY();
    int GetHeight();
    int GetWidth();
    virtual void Update(int) = 0;
    virtual void ChangeState() = 0;
    virtual ~Entrance();

};


