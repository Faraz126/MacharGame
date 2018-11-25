#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Texture.h"
#include "Lids.h"

const int TRASHCANLID_WIDTH = 80;
const int TRASHCANLID_HEIGHT = 18.694;

class TrashCanLid: public Lids
{
    private:

    protected:

    public:
        TrashCanLid(int, int);
        bool CorrectContainer();
        void Show(SDL_Renderer*);
        void Update(int){};
        void HandleEvents(SDL_Event*){};
        ~TrashCanLid();
};

