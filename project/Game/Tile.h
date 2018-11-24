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
    Tile();
    Tile(int, int, int, std::string, int);
    int tileState;
    void Show(SDL_Renderer*);
    void UpdatePos(int,int);
    void Update(int){};
    void HandleEvents(SDL_Event*, Screens_Node&){};
    void SetTileText(std::string str1, std::string str2);
    ~Tile();
};


