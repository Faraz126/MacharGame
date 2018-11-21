#ifndef ABSTRACTFACTORY_H
#define ABSTRACTFACTORY_H
#include "Mosquito.h"


class AbstractFactory
{
    public:
        AbstractFactory();
        virtual ~AbstractFactory();
        virtual Mosquito* GetMosquito(int) = 0;
        virtual void GetHuman() = 0;
    protected:
        Mosquito* mosquito;

    private:
};

#endif // ABSTRACTFACTORY_H
