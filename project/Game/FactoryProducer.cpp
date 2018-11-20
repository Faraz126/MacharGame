#include "FactoryProducer.h"

AbstractFactory* FactoryProducer::factory = 0;

FactoryProducer::FactoryProducer()
{
    //ctor
}

FactoryProducer::~FactoryProducer()
{
    //dtor
}

AbstractFactory* FactoryProducer::GetFactory(int n)
{

    factory = new MosquitoFactory();
    return factory;
}
