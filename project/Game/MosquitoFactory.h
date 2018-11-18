#pragma once
#include "Mosquito.h"



class MosquitoFactory //public Factory
{
private:
    Mosquito* mosquito;
protected:

public:
    MosquitoFactory();
    ~MosquitoFactory();
    //Mosquito* GetMosquito(int);
};
