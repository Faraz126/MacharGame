#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"
#include "Container.h"
#include "Texture.h"
#include <stdio.h>
#include"Plant.h"
#include"Soil.h"
#include"TrashCan.h"
#include"Manhole.h"
#include"House.h"

class Outdoor: public Screens
{
private:
//    Mosquito* mosquito;
//    House* house;
//    DirtyWater* dirtywater;
//    CleanWater* cleanwater;
//    Manhole* manhole;
    //Outdoor* outdoor;

    int countContainer;
    int countPlants;
    int countWater;
    int countTrashcan;
    int countManhole;

    SDL_Rect pos, pos1;
    Texture* texture;
    SDL_Rect* houseRect; //rectangle for clickable region of house
    SDL_Rect* entranceRect; //rectangle for entrance region of house
    House* house;
    Container** container;


protected:

public:
    Outdoor();
    //void AddHuman();
    //void LeaveHuman();
    //void Click();
    void Show(SDL_Renderer*);
    void Update(SDL_Event*, Screens_Node&);
    //Entrance* getCurrentState();
    ~Outdoor();
};
