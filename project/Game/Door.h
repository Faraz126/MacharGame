#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>


class Door:public Entrance
{
private:
    //time TimeCovered;
    bool  isOpen;
protected:

public:
    Door(int,int);
    void Show(SDL_Renderer*, SDL_Rect* rect = nullptr);
    void Update(int);
    void ShowOutside(SDL_Renderer*);
    virtual void ChangeState();
    bool IsOpen();
    //time SetTime();
    ~Door();
};
