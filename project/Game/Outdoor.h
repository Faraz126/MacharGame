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
#include "Clickable.h"
#include "Human.h"
#include "DirtyWater.h"
#include "CleanWater.h"
#include "Scenario.h"
#include "Score.h"
#include "Money.h"
#include "Alert.h"
#include "Hospital.h"

#include <string>
#include <fstream>
#include <sstream>
#include <ostream>
#include <istream>
#include <iostream>



class Outdoor: public Scenario
{
private:
//    Mosquito* mosquito;
//    House* house;
//    DirtyWater* dirtywater;
//    CleanWater* cleanwater;
//    Manhole* manhole;
    //Outdoor* outdoor;


    SDL_Rect pos, pos1, shoppingPos;
    SDL_Rect* cartPos;
    Texture* texture;

    int countContainer;
    int countPlants;
    int countCleanWater;
    int countTrashcan;
    int countManhole;
    bool shopShow;
    int totalHumans;

    House* house;
    SDL_Rect* buildingRect; //rectangle for clickable region of houses & hospital



    //Container** container;
    ShoppingMenu* shop;
    //Human** humans;
    //Entrance** entrance;

    //Human** GenerateHumans();
    int CountHumans();
    void GetHouseEntrance();
    void HandleScrolling(SDL_Event*);
    void PlaceContainers();


    Money money;
    Alert alert;

protected:

public:
    Hospital* hospital;
    Outdoor(Screens*, bool);
    Outdoor(fstream*, Screens*, bool);

    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    void Save(fstream&);
    void Load(fstream*);
    //Entrance* getCurrentState();
    void Delete();
    ~Outdoor();
};




