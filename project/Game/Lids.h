#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Clickable.h"

class Lids: public Clickable
{
    private:

    protected:
        int spriteNum;

    public:
        Lids(int,int,int,int);
        virtual ~Lids();
        void Drag(SDL_Event*);
        void Drop(SDL_Event);
        virtual void Show(SDL_Renderer*) = 0;
        void Uncover();
};

