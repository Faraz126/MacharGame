#pragma once
#include "Mosquito.h"
#include "Window.h"


class Human;

class NormalMosquito : public Mosquito
{
private:

public:
    NormalMosquito();
    NormalMosquito(Scenario*);
    void Bite();
    ~NormalMosquito();
};

