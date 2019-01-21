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
#include "Manual.h"
#include "Alert.h"

class EndMenu;
class Outdoor;



class House: public Scenario

{
private:
    //Money money;
    SDL_Rect outdoorPos;
    bool hasRepellent; //if the house has repellent
    int noOfHumans;

    Bed* bed; //array of beds
    SDL_Rect pos;
    Texture* texture;
    Showpiece* showpieces;
    SDL_Rect wall;
    //Human** humans;
    Button* btn;
    ShoppingMenu* houseShop; //shopping card
    SDL_Rect* cartPos;

    Money money;
    void SetUpScenarios();
    Outdoor* outdoor; //pointer to outdoor
    int dyingIndex;
    bool toShow;
    Alert alert;
    SDL_Rect* upperRect0;


    //Outdoor* outdoor;
    //Door* door;
protected:
    void SetUpEntrancesAndShowPieces();
    void GenerateHumans();

public:
    House();
    ~House();
    void SetOutdoorPos(int,int,int, int);
    void ShowOutside(SDL_Renderer*, int);
    void SetOutdoorX(int,int);
    bool GetHasRepellent();
    void SetOutdoor(Outdoor*);
    Outdoor* GetOutdoor();
    void Click();
    void Show(SDL_Renderer*);
    void getWindowState();
    void getEntranceState();
    void Update(int);
    void HandleEvents(SDL_Event* e, Screens_Node&);
    int NoOfHumans();
    Door* GetDoor();
    Bed* GetBeds(int&);


};
