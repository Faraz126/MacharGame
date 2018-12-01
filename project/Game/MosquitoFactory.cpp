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
    switch (n)
    {
        case MALARIA:
        {
            mosquito = new MalariaMosquito();
            break;
        }
        case AEDES:
        {
            mosquito = new AedesMosquito();
            break;
        }
        case NORMAL:
        {
            mosquito = new NormalMosquito();
            break;
        }
    }
    return mosquito;
}

void MosquitoFactory::GetHuman()
{

}
