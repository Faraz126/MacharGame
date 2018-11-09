#pragma once

class AbstractFactory
{
private:

protected:

public:
    AbstractFactory();
    Mosquito* GetMosquito(int);
    Human* GetHuman(int);
    ~AbstractFactory();
};
