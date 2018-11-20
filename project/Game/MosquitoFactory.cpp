#include "MosquitoFactory.h"

MosquitoFactory::MosquitoFactory()
{
    //ctor
}

MosquitoFactory::~MosquitoFactory()
{
    //dtor
}

Mosquito* MosquitoFactory::GetMosquito(int n)
{
    if (n == 0)
    {
        mosquito = new NormalMosquito();
    }
    return mosquito;
}

void MosquitoFactory::GetHuman()
{

}
