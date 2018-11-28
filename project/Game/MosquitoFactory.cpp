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
        }
        case AEDES:
        {
            mosquito = new AedesMosquito();
        }
        case NORMAL:
        {
            mosquito = new NormalMosquito();
        }
    }
    return mosquito;
}

void MosquitoFactory::GetHuman()
{

}
