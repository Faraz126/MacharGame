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
#include <stack>
#include "Door.h"
#include "Scenario.h"
#include "DoublyLinked.h"


enum DIRECTION {UP, RIGHT, DOWN, LEFT};
enum STATES_HUMAN {GOING_TO_BED, WALKING, GOING_TO_DOOR, SITTING, LYING, AVOIDING_COLLISION};

class House;



class Human: public Clickable
{
private:
    SDL_Rect face, body, legs;
    House* ownHouse;
    Scenario* currentScenario;
    SDL_Rect collideRect;
    double sizeFactor;
    int faceSprite,bodySprite,legSprite;
    double walker;
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
    bool isInfected;
    int activity;
    int step;
    void Move();
    int timeSince;
    int slowDownFactor;
    int spriteNum;
    Door* door;
    DLL<int> myStack;
    void GoOutdoor();
    void GoIndoor();
    void ChangeScenario(Scenario*);


protected:

public:
    Human();
    Human(House*);
    void Update(int);
    Human(int,int, House*);
    void Show(SDL_Renderer*);
    void ChangeState(int = -1);
    bool Collide(SDL_Rect&);
    void ChangeBedToFollow();
    void ChooseBed();
    void ChooseDoor();
    bool MoveAllowed();
    void ChangeDirection();
    void BuildHuman();
    void HandleEvents(SDL_Event*, Screens_Node&);
    bool GetIndoor();
    void SetX(int, int);



};


