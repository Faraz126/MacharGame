#ifndef FACTORYPRODUCER_H
#define FACTORYPRODUCER_H

#include "AbstractFactory.h"
#include "MosquitoFactory.h"

class FactoryProducer
{
    public:
        FactoryProducer();
        static AbstractFactory* GetFactory(int);
        virtual ~FactoryProducer();

    protected:
        static AbstractFactory* factory;

    private:
};

#endif // FACTORYPRODUCER_H
