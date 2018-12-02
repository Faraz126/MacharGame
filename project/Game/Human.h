#pragma once
#include <iostream>
#include "Color.h"
#include "Point.h"
#include "Texture.h"
#include "Mosquito.h"
#include "Clickable.h"
#include <SDL.h>
#include <SDL_image.h>

#include <stack>
#include "Door.h"
//#include "Scenario.h"
#include "DoublyLinked.h"
#include "Disease.h"



enum DIRECTION {UP, RIGHT, DOWN, LEFT};
enum STATES_HUMAN {GOING_TO_BED, WALKING, GOING_TO_DOOR, SITTING, LYING, AVOIDING_COLLISION, IN_HOSPITAL};

class Scenario;
class House;
class Bed;


class Human: public Clickable
{
private:
    bool hasRepeppant;
    SDL_Rect face, body, legs;
    House* ownHouse;
    Scenario* currentScenario;
    SDL_Rect collideRect;
    double sizeFactor;
    int faceSprite,bodySprite,legSprite;
    double walker;
    Bed* bedToGoTo;
    int toFollowX;
    int toFollowY;
    int health;
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
    Door* door; //pointer to ownHouses door
    DLL<int> myStack; //activities to do.
    void GoOutdoor();
    void GoIndoor();
    void ChangeScenario(Scenario*);
    int disease;
    bool isIndoor;
    bool sentToBed;
    void BuildHuman();
    void ChangeState(int = -1);
    void ChangeBedToFollow();
    void ChooseBed();
    void ChooseDoor();
    bool MoveAllowed();
    void ChangeDirection();
    int timeToDie;
    bool dead;


public:
    bool IsDead(){return dead;}
    int GetTimeToDie(){return timeToDie;}
    Human();
    Human(House*);
    void Update(int);
    Human(int,int, House*);
    void Show(SDL_Renderer*);
    bool Collide(SDL_Rect&);
    void HandleEvents(SDL_Event*, Screens_Node&);
    bool GetIndoor();
    void SetX(int, int);
    void SetInfected(int); //for mosquito
    int GetInfected();
    void UpdatePos(int x, int y);
    bool Collides(const SDL_Rect&);
    void GoToHospital();
    void Damage();
    int GetDisease();
    bool GetCoveredInRepellant(){return hasRepeppant;}



};


