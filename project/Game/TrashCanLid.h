#pragma once
#ifndef TRASHCANLID_H
#define TRASHCANLID_H

#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Texture.h"
#include "Lids.h""

const int TRASHCANLID_WIDTH = 80;
const int TRASHCANLID_HEIGHT = 15.914;

class TrashCanLid: public Lids
{
    private:

    protected:

    public:
        TrashCanLid(int, int);
        bool CorrectContainer();
        void Show(SDL_Renderer*);
        ~TrashCanLid();
};

#endif
