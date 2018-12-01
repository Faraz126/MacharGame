#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Texture.h"
#include "Lids.h"

const int MANHOLELID_WIDTH = 125;
const int MANHOLELID_HEIGHT = 108;

class ManholeLid: public Lids
{
private:

protected:

public:
    ManholeLid(int, int);
    bool CorrectContainer();
    void Show(SDL_Renderer*);
    void Update(int){};
    //void HandleEvents(SDL_Event*, Screens_Node&){};
    ~ManholeLid();
};

