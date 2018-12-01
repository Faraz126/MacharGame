#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"

class Scenario;

class Clickable
{
    public:
        Clickable(int,int,int,int);
        bool WithinRegion(int, int);
        virtual void UpdatePos(int,int);
        virtual bool Collides(const SDL_Rect&);
        bool Collides(const int, const int, const int, const int);
        virtual bool Collides(const Clickable&);
        static bool Collides(const SDL_Rect&, const SDL_Rect&);
        void ReduceSize(double);
        virtual void SetX(int,int);
        virtual ~Clickable();
        int GetDistance(int,int);
        void GetCenter(int&, int&);
        virtual void Show(SDL_Renderer*) = 0;
        virtual void Update(int) = 0;
        virtual void HandleEvents(SDL_Event*, Screens_Node&) = 0;
        int GetX();
        int GetY();
        virtual void Collision(){};

        void SetScenario(Scenario*);
        Scenario* GetScenario();
    protected:
        SDL_Rect pos;
        Scenario* currentScenario; //whether the breeding place is in in house or outdoor.



    private:
};
