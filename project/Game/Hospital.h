#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Human.h"
#include "Scenario.h"
#include "Manual.h"
#include "Button.h"

class Outdoor;

class Hospital: public Scenario
{
private:
/*    Chair* chair;
    Manual* manual;
    Medicine* medicine;
    Outdoor* outdoor;
    */
    SDL_Rect pos;
    Texture* texture;
    int humanPos[8];
    Manual* manual;
    bool manualShow;
    Button* btn;
    SDL_Rect* upperRect;
//    Outdoor* outdoor;
protected:

public:
    Hospital();
    ~Hospital();
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    bool AddHuman(Human*);
    void LeaveHuman(Human*);
    void Click();
    void Show(SDL_Renderer*);
    void ShowManual();
    void CheckHumanDisease(Human*);
};
