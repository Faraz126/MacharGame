#pragma once
#ifndef TRASHCAN_H
#define TRASHCAN_H


#include "Container.h"
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Mosquito.h"

const int CAN_WIDTH = 70;
const int CAN_HEIGHT = 73.234;


class TrashCan : public Container
{
    public:
        TrashCan(int,int);
        void Show(SDL_Renderer*);
        Mosquito* Breed();
        ~TrashCan();
};

#endif // TRASHCAN_H
