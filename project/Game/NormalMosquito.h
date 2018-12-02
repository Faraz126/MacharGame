#pragma once
#include "Mosquito.h"
#include "Window.h"


class Human;

class NormalMosquito : public Mosquito
{
private:
    double clip;

    int human;
    int frames;

public:
    NormalMosquito();
    NormalMosquito(Scenario*);
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
    ~NormalMosquito();
};
