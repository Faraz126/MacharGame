#pragma once
#include <iostream>
#include "Color.h"
#include "Point.h"
#include "Texture.h"
#include "Mosquito.h"
#include "Clickable.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Bed.h"


enum DIRECTION {UP, RIGHT, DOWN, LEFT};
enum STATES_HUMAN {GOING_TO_BED, GOING_TO_DOOR, WALKING};

class House;



class Human: Clickable
{
private:
    House* ownHouse;
    SDL_Rect collideRect;
    bool isIndoor;
    bool isGoingToBed;
    bool isGoingOut;
    bool isWalking;
    Bed* bedToGoTo;
    int toFollowX;
    int toFollowY;
    int faceDirection;
    bool isVertical;
    bool isHorizontal;
    int activity;
    int step;
    void Move();


protected:

public:
    Human();
    Human(House*);
    void Update(int);
    Human(int,int, House*);
    void Show(SDL_Renderer*);
    bool Collide();

};

