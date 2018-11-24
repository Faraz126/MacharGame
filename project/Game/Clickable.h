#pragma once

#include <SDL.h>
#include <SDL_image.h>


class Clickable
{
    public:
        Clickable(int,int,int,int);
        bool WithinRegion(int, int);
        bool Collides(const SDL_Rect&);
        bool Collides(const int, const int, const int, const int);
        bool Collides(const Clickable&);
        void ReduceSize(double);
        void SetX(int,int);
        virtual ~Clickable();


    protected:
        SDL_Rect pos;



    private:
};
