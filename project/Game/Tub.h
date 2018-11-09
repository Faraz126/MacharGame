#pragma once

class Tub : public Container
{
private:

protected:

public:
    Tub();
    Mosquito* breedType(int);
    void Show(SDl_Render*);
    ~Tub();
};

