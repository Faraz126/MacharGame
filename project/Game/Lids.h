#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Clickable.h"

class Lids: public Clickable
{
    private:
        bool mouseClick;
    protected:
        int spriteNum;

    public:
        Lids(int,int,int,int);
        virtual ~Lids();
        virtual void Show(SDL_Renderer*) = 0;
        void HandleEvents(SDL_Event*, Screens_Node&);
        void SetX(int,int);
        void SetPosition(int, int);
        void Uncover();
};

