#pragma once
#include "Texture.h"
#include "Window.h"
#include "DoublyLinked.h"
#include <vector>

class Scenario;
class Human;

enum MOSQUITO {MALARIA, AEDES, NORMAL};
enum DISEASE {BITEN, DISEASE_MALARIA, CHICKENGUNYA, DENGUE};


class Mosquito
{
private:

    bool indoor;
    double speed_x;
    double speed_y;
    Entrance* entrance;
    int health;
    bool IsDead;
    int ReachingTimer;      //timer starts when mosquito reaches an entrance
    double clip;            // the mosquito clips from spritesheet

protected:

    int diseaseCode;        // the integer determines which disease mosquito gives
    DLL<Human*> humans;
    int human;          // to get the human
    bool IsFollowingHuman;
    bool IsFollowingEntrance;
    int DetectTimer;
    int MaxSpeedX;
    int MaxSpeedY;
    int Vision;     // how far mosquito can see
    int Range;      // how far mosquito can attack from
    bool DetectHuman;
    bool DetectEntrance;
    SDL_Rect position;
    Scenario* screen;

public:
    Mosquito();
    Mosquito(Scenario* screen);
    void Fly();                 // fly randomly
    void IsFollow(Entrance*);      // to go in the window
    void IsFollow();        //to go to human
    void Update(int);       // this is the main function which defines the mosquito movements and behavior
    void DetectAnEntrance();
    void DetectAHuman();
    void Detect();          // this function will basically allow the mosquito to detect if probability coniditon is true
    void Follow();          // allow the mosquito to follow if it is
    void ReachedEntrance(); // when it reaches the entrance
    void Heal();            // when mosquto bites it is healed too
    void Show(SDL_Renderer*);
    void SetIsDead(bool);
    void SetIndoor(bool);
    bool GetIsDead();
    Entrance* GetClosestEntrance();
    void SetX(int delta, int direction);
    void SetScenario(Scenario*);        // helps to put mosquito inside and outside
    void UpdatePositiion(int,int);
    virtual void Bite() = 0;
};

