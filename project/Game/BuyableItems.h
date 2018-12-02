#include <iostream>
#include "House.h"


class BuyableItems
{
private:

protected:

    int price;

public:
    BuyableItems();
    virtual void Apply(House*) = 0;
    ~BuyableItems();
};


