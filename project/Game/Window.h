#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>

enum STATES {CLOSED, HALF_OPEN, OPEN};

class Window :public Entrance
{
private:
    int timeCovered, currentTime, state;
protected:

public:
    Window(int,int);
    void Show(SDL_Renderer*);
    void Update(SDL_Event*, Screens_Node&);
    virtual void ChangeState();
    bool IsOpen();
    //time SetTime();
    ~Window();
};
