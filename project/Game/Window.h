#pragma once
#include "Entrance.h"
#include <SDL.h>
#include <SDL_image.h>

enum STATES {CLOSED, HALF_OPEN, OPEN};

class Window :public Entrance
{
private:
    int timeCovered, currentTime, state, endTime;
    SDL_Rect* rect;
protected:

public:
    Window(int,int);

    void Show(SDL_Renderer*);

    void Update(int);
    void ShowOutside(SDL_Renderer*);
    virtual void ChangeState();
    bool IsOpen();
    void HandleEvents(SDL_Event*, Screens_Node&){};
    //time SetTime();
    ~Window();
};
