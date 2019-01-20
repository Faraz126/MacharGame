#pragma once
#include "BuyableItems.h"

class BadMedicine : public BuyableItems
{

private:
protected:

public:
    BadMedicine();
    void Apply(House*);
    ~BadMedicine();
};
