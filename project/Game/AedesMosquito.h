#pragma once
#include "Mosquito.h"
#include "Window.h"

#include "Scenario.h"

class Human;

class AedesMosquito : public Mosquito
{
private:
    const int diseases[2] = {DENGUE,CHICKENGUNYA};
public:
    AedesMosquito();
    AedesMosquito(Scenario*);
    void Bite();
    ~AedesMosquito();
};
