#pragma once
#include "Mosquito.h"
#include "Window.h"

class Human;

class MalariaMosquito : public Mosquito
{
private:

protected:

public:
    MalariaMosquito();
    MalariaMosquito(Scenario*);
    void Bite();
    ~MalariaMosquito();
};
