#pragma once
#include "BuyableItems.h"

class Repellant : public BuyableItems
{

private:

protected:

public:
    Repellant();
    void Apply(House*);
    ~Repellant();
};
