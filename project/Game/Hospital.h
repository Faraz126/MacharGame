#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Human.h"
#include "Scenario.h"
#include "Button.h"

class Outdoor;
class Manual;

#include "PauseMenu.h"

class Hospital: public Scenario
{
private:
    SDL_Rect pos;
    Texture* texture;
    int humanPos[8];
    Manual* manual;
    Button* btn;
    Human* popped;
    bool manualShow;
    SDL_Rect* upperRect;

//    Outdoor* outdoor;
protected:

public:
    Hospital(Screens*);
    ~Hospital();
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    bool AddHuman(Human*);
    void LeaveHuman(Human*);
    void LeaveHuman();
    void Click();
    void Show(SDL_Renderer*);
    void ShowManual();
    Human* GetPopped();
    int CheckHumanDisease();
    void CheckHumanDisease(Human*);

};
