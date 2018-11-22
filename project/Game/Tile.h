#pragma once
#include "Texture.h"
#include <iostream>
#include <string>
#include "string.h"
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"



class Tile
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
    bool shopShow;
    Tile();
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(SDL_Event*, Screens_Node&);

    ~Tile();
};


