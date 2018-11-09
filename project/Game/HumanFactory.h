#pragma once

class HumanFactory: public AbstractFactory
{
private:
    Human* human;
protected:

public:
    HumanFactory();
    Human* GetHuman(int);
    ~HumanFactory();
};

