#pragma once

class NormalMosquito : public Mosquito
{
private:

public:
    NormalMosquito(){};
    void bite(Human*);
    ~NormalMosquito();
};

