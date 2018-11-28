#pragma once
#include "Mosquito.h"
#include "Window.h"
#include "Disease.h"

class Human;


class ChickengunyaMosquito : public Mosquito
{
private:
    double clip;
    Disease* Chickengunya;
    int human;
    int frames;

public:
    ChickengunyaMosquito();
    ChickengunyaMosquito(Scenario*);
    void Update();
    void bite(Human*);
    void fly();
    void follow(Human*);
    void Show(SDL_Renderer*);
    void Detect();
    void follow(Entrance*);
    void ReachedEntrance();
    ~ChickengunyaMosquito();
};
