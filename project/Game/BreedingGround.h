#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "FactoryProducer.h"
#include "AbstractFactory.h"
#include "Clickable.h"
//#include "Mosquito.h"


class BreedingGround :public Clickable
{
private:

protected:
    AbstractFactory* factory;
    int spriteNum;
public:
    BreedingGround(int, int, int, int);
    virtual void Show(SDL_Renderer*) = 0;
    virtual Mosquito* Breed() = 0;
    virtual ~BreedingGround();
    void UpdatePos(int,int);
};
