#include "BuyableItems.h"
#include "Money.h"


class Nets : public BuyableItems
{

private:
    int TimeLeft;
protected:

public:
    Nets();
    void Apply(House*);
    ~Nets();
};
