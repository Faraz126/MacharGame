#include "BuyableItems.h"
#include "House.h"
#include "Scenario.h"


class Nets : public BuyableItems
{

private:
    int TimeLeft;
protected:

public:
    Nets();
    void Apply(Scenario*);
    ~Nets();
};
