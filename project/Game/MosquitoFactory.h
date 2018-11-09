#pragma once

class MosquitoFactory: public AbstractFactory
{
private:
    Mosquito* mosquito;
protected:

public:
    Mosquito* GetMosquito(int);
};
