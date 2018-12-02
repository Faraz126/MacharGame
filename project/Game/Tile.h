#pragma once
#include "Texture.h"
#include <iostream>
#include <string>
#include "string.h"
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include <string>
#include <iostream>
#include "Word.h"
#include "DDT.h"
#include "Repellant.h"
#include "Nets.h"
#include "BadMedicine.h"
class BuyableItems;

class Tile: public Clickable
{
private:
    Texture* texture;
    Word* word;
    int spriteNumber;
    int x;
    int y;
    std::string str;
    int price;

protected:

public:
    BuyableItems* buy;
    SDL_Rect iconPos;
    int sprite;
    Tile();
    Tile(int);
    //Tile(int, int, int, std::string, int);
    int tileState;
    void Show(SDL_Renderer*);
    void UpdatePos(int,int);
    void Update(int){};
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void SetTileText();
    void SetTileIcon(int);
    void SetValues(int);
    ~Tile();
};


