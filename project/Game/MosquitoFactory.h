#ifndef MOSQUITOFACTORY_H
#define MOSQUITOFACTORY_H

#include "AbstractFactory.h"
#include "Mosquito.h"
#include "NormalMosquito.h"


class MosquitoFactory : public AbstractFactory
{
    public:
        MosquitoFactory();
        virtual ~MosquitoFactory();
        Mosquito* GetMosquito(int);
        void GetHuman();

    protected:

    private:
};

#endif // MOSQUITOFACTORY_H
