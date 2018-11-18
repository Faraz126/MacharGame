#ifndef FACTORY_H
#define FACTORY_H
#include "Mosquito.h"


class Factory
{
    public:
        Factory();
        virtual ~Factory();
        virtual Mosquito* GetMosquito(int) = 0;

    protected:

    private:
};

#endif // FACTORY_H
