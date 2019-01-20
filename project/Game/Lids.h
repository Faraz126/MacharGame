#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include "Clickable.h"
#include "fstream"

class Lids: public Clickable
{
    private:
        int lidOrignalPosX;
        int lidOrignalPosY;
        bool mouseClick;
    protected:
        int spriteNum;

    public:
        Lids(){}
        Lids(int,int,int,int);
        virtual ~Lids();
        virtual void Show(SDL_Renderer*) = 0;
        void HandleEvents(SDL_Event*, Screens_Node&);
        void SetX(int,int);
        void SetPosition(int, int);
        void Uncover();
        void Write(std::fstream&);
        void Read(std::fstream&);
};

