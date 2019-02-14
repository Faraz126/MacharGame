#ifndef INSTRUCTIONS_H
#define INSTRUCTIONS_H

#include "Screens.h"
#include "Texture.h"
#include "Scenario.h"
#include "Outdoor.h"
#include "Clickable.h"


class Instructions : public Screens
{
    public:
        Instructions(Screens*, bool);
        virtual ~Instructions();
        virtual void Show(SDL_Renderer*);
        virtual void Update(int);
        virtual void HandleEvents(SDL_Event*, Screens_Node&);
        int activeScreen;

    protected:

    private:

        SDL_Rect* sprites;
        SDL_Rect pos, left, right, pos1, pos2;
};

#endif // INSTRUCTIONS_H
