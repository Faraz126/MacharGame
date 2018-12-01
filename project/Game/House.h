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
#include "Button.h"
#include "DoublyLinked.h"
#include "ShoppingMenu.h"
#include "EndMenu.h"
#include "PauseMenu.h"
#include "Score.h"
#include "Money.h"
#include "Scenario.h"
#include "AedesMosquito.h"

class Outdoor;



class House: public Scenario

{
private:
    //Money money;

    bool hasRepellent;
    int noOfHumans;

    Bed* bed;
    SDL_Rect pos;
    Texture* texture;
    Showpiece* showpieces;
    SDL_Rect wall;
    //Human** humans;
    Button* btn;
    ShoppingMenu* houseShop;
    SDL_Rect* cartPos;

    Money money;
    void SetUpScenarios();
    Outdoor* outdoor;

    //Outdoor* outdoor;
    //Door* door;
protected:

public:
    House();
    ~House();
    bool GetHasRepellent();
    /*
<<<<<<< HEAD
    //void AddHuman(Human*){};
    //void LeaveHuman(Human*);
=======
    bool AddHuman(Human*){};
    void LeaveHuman(Human*){};
>>>>>>> daba5613d1af045bdabb1b8193ff17be11eceb82
*/
    void SetOutdoor(Outdoor*);
    Outdoor* GetOutdoor();
    void Click();
    void Show(SDL_Renderer*);
    void getWindowState();
    void getEntranceState();
    void Update(int);
    void HandleEvents(SDL_Event* e, Screens_Node&);
    int NoOfHumans();
    Bed* GetClosestBed(int,int);
    Door* GetDoor();
    Bed* GetBeds(int&);

};
