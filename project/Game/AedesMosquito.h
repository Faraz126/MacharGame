#pragma once
#include "Mosquito.h"
#include "Window.h"

#include "Scenario.h"

class Human;

class AedesMosquito : public Mosquito
{
private:
    double clip;
    int human;

public:
    AedesMosquito();
    AedesMosquito(Scenario*);
    void Update(int);
    void Bite(Human*);
    void Fly();
    void Follow(Human*);
    void Follow(Entrance*);
    void Show(SDL_Renderer*);
    void DetectAnEntrance();
    void DetectAHuman();
    void DetectOrFollow();
    void ReachedEntrance();
    ~AedesMosquito();
};
