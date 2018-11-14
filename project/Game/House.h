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
    //Outdoor* outdoor;
    //Door* door;
protected:

public:
    House();
    ~House();
    bool GetHasRepellent();
    void AddHuman();
    void LeaveHuman();
    void click();
    void Show(SDL_Renderer*);
    void getWindowState();
    void getEntranceState();
};
