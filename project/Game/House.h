#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"
#include "Door.h"
#include "Window.h"
#include "Entrance.h"
#include "Texture.h"
#include "Bed.h"
#include "Showpiece.h"
#include "Plant.h"
#include "TrashCan.h"
#include "Manhole.h"
#include "Tub.h"
#include "Human.h"




class House: public Screens

{
private:
    //Money money;

    bool hasRepellent;
    int noOfHumans;
    int noOfEntrance;
    Entrance** entrance;
    Bed* bed;
    SDL_Rect pos;
    Texture* texture;
    Showpiece* showpieces;
    BreedingGround** breedingplaces;
    SDL_Rect wall;

    Human** humans;

    int noOfBreedingPlaces;
    //Outdoor* outdoor;
    //Door* door;
protected:

public:
    House();
    ~House();
    bool GetHasRepellent();
    void AddHuman();
    void LeaveHuman();
    void Click();
    void Show(SDL_Renderer*);
    void ShowOutside(SDL_Renderer*, const SDL_Rect&);
    void getWindowState();
    void getEntranceState();
    void Update(int);
    void HandleEvents(SDL_Event* e, Screens_Node&);
    int NoOfHumans();
    Bed* GetClosestBed(int);
    Door* GetDoor();
};
