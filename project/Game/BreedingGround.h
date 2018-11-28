#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "FactoryProducer.h"
#include "AbstractFactory.h"
#include "Clickable.h"
#include "Scenario.h"
//#include "Mosquito.h"


class BreedingGround :public Clickable
{
private:

protected:
    AbstractFactory* factory;
    Scenario* currentScenario; //whether the breeding place is in in house or outdoor.
    int spriteNum;
    int percentage;
public:
    BreedingGround(int, int, int, int);
   // virtual void Show(SDL_Renderer*) = 0;
    virtual Mosquito* Breed() = 0;
    void AddMosquito(Mosquito*);
    virtual ~BreedingGround();
    void UpdatePos(int,int);
    void SetScenario(Scenario*);
};
