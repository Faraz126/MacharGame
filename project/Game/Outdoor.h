#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"
#include "Texture.h"
#include <stdio.h>

class Outdoor: public Screens
{
private:
//    Mosquito* mosquito;
//    House* house;
//    DirtyWater* dirtywater;
//    CleanWater* cleanwater;
//    Manhole* manhole;
    //Outdoor* outdoor;

    SDL_Rect pos;
    Texture* texture;
    int countContainer;
    int countPlants;
    int countSoil;
    int countTrashcan;
    int countManhole;

protected:

public:
    Outdoor();
    void AddHuman();
    void LeaveHuman();
    void Click();
    void Show(SDL_Renderer*);
    void Update(SDL_Event*, Screens_Node&);
    //Entrance* getCurrentState();
    ~Outdoor();
};
