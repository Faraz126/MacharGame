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
    AbstractFactory* factory; //factory
    int spriteNum;
    int percentage;
    void AddMosquito(Mosquito*);
public:
    BreedingGround(){};
    BreedingGround(int, int, int, int);
   // virtual void Show(SDL_Renderer*) = 0;
    virtual Mosquito* Breed() = 0;
    virtual ~BreedingGround();
    void UpdatePos(int,int);
    virtual void Write(std::fstream&){};
    virtual void Read(std::fstream&){};

};
