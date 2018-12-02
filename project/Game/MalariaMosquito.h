#pragma once
#include "Mosquito.h"
#include "Window.h"


class Human;

class MalariaMosquito : public Mosquito
{
private:
    double clip;
    int human;

public:
    MalariaMosquito();
    MalariaMosquito(Scenario*);
    void Update(int);
    void Bite(Human*);
    void Fly();
    void Follow(Human*);
    void Show(SDL_Renderer*);
    void DetectAnEntrance();
    void DetectAHuman();
    void DetectOrFollow();
    void Follow(Entrance*);
    void ReachedEntrance();
    ~MalariaMosquito();
};
