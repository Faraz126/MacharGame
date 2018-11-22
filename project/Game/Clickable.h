#pragma once

#include <SDL.h>
#include <SDL_image.h>


class Clickable
{
    public:
        Clickable(int,int,int,int);
        bool WithinRegion(int, int);
        void UpdatePos(int,int);
        bool Collides(const SDL_Rect&);
        bool Collides(const int, const int, const int, const int);
        void ReduceSize(double);
        virtual ~Clickable();


    protected:
        SDL_Rect pos;



    private:
};
