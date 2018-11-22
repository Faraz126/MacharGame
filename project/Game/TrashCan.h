#pragma once
#ifndef TRASHCAN_H
#define TRASHCAN_H


#include "Container.h"
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Mosquito.h"

const int CAN_WIDTH = 121*0.5;
const int CAN_HEIGHT = 117*0.5;


class TrashCan : public Container
{
    public:
        TrashCan(int,int);
        void Show(SDL_Renderer*);
        void SetCovered(bool);
        void EventHandle(SDL_Event*);
        Mosquito* Breed();
        ~TrashCan();
};

#endif // TRASHCAN_H
