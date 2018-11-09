#pragma once

class DirtyWater : public BreedingGround
{
private:

protected:

public:
    DirtyWater();
    Mosquito* breedType(int);
    void Show(SDl_Render*);
    ~DirtyWater();
};
