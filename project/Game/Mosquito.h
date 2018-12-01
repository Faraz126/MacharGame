#pragma once
#include "Texture.h"
#include "Window.h"
#include "DoublyLinked.h"
#include <vector>

class Scenario;
class Human;

enum MOSQUITO {MALARIA, AEDES, NORMAL};
enum DISEASE {BITEN = 1, DISEASE_MALARIA, CHICKENGUNYA, DENGUE};


class Mosquito
{
private:

protected:
    bool indoor;
    double speed_x;
    double speed_y;
    bool DetectHuman;
    bool DetectEntrance;
    SDL_Rect position;
    bool IsFollowingHuman;
    bool IsFollowingEntrance;
    Scenario* screen;
    DLL<Human*> humans;
    Entrance* entrance;
//    bool indoor;
    int timer;
    int diseaseCode;

public:
    Mosquito();         // confused about what to do with this
    void SetScenario(Scenario*);
    void UpdatePositiion(int,int);
    virtual void Fly() = 0;
    virtual void Bite(Human*) = 0;
    virtual void Follow(Entrance*) = 0;      // to go in the window
    virtual void Follow(Human*) = 0;        //to go to human
    virtual void Update(int) = 0;
    virtual void DetectAnEntrance() = 0;
    virtual void DetectAHuman() = 0;
    virtual void DetectOrFollow() = 0;
    virtual void ReachedEntrance() = 0;
    virtual void Show(SDL_Renderer*) = 0;
    void SetIndoor(bool);
    Entrance* GetClosestEntrance();
    void SetX(int delta, int direction);

    //virtual ~Mosquito();
};

