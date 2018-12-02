#pragma once
#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "Texture.h"
#include <iostream>
#include <string>
#include "string.h"
class House;
#include "Money.h"

class BuyableItems
{
private:

protected:

    Money price;
    std::string name;
    int spriteNum;


public:
    BuyableItems();
    virtual void Apply(House*) = 0;
    std::string GetName();
    int GetSpriteNum();
    int GetPrice();
    ~BuyableItems();
};


