#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Texture.h"
#include "Lids.h"

const int TubLid_WIDTH = 300;
const int TubLid_HEIGHT = 96;

class TubLid: public Lids
{
    private:

    protected:

    public:
        TubLid(int, int);
        bool CorrectContainer();
        void Show(SDL_Renderer*);
        void Update(int){};
        ~TubLid();
};

