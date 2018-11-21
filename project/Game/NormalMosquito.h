#pragma once

#include "Mosquito.h"
#include "Human.h"

class NormalMosquito : public Mosquito
{
private:

public:
    NormalMosquito();
    void bite(Human*);
    ~NormalMosquito();
};

