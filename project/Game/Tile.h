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
    void Show(SDL_Renderer*);
    /*
    void Click(SDL_Event*);
    void Hover (SDL_Event*);

    void Update(SDL_Event*, Screens_Node&);
    */
    ~Tile();
};


