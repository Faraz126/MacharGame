#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Human.h"

class Hospital
{
private:
/*    Chair* chair;
    Manual* manual;
    Medicine* medicine;
    Outdoor* outdoor;
    */
protected:

public:
    void EnterHospital();
    void LeaveHospital();
    void Click();
    void Show(SDL_Renderer*);
    void ShowManual();
    void CheckHumanDisease(Human*);
};
