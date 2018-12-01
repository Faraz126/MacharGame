#include "BuyableItems.h"
#include "House.h"

class BadMedicine : public BuyableItems
{

private:
protected:

public:
    BadMedicine();
    void Apply(Scenario*);
    ~BadMedicine();
};
