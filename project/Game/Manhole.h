#pragma once

class Manhole : public Container
{
private:

protected:

public:
    Manhole();
    Mosquito* breedType(int);
    void Show(SDl_Render*);
    ~Manhole();
};


