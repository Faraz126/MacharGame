#pragma once
#include "BuyableItems.h"
#include "Alert.h"

class BadMedicine : public BuyableItems
{

private:
protected:

public:
    BadMedicine();
    void Apply(House*);
    ~BadMedicine();
};
