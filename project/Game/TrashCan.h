#pragma once
#ifndef TRASHCAN_H
#define TRASHCAN_H


#include "Container.h"
#include "Texture.h"
#include <SDL.h>
#include <SDL_image.h>
#include "Mosquito.h"

const int CAN_WIDTH = 121*0.65;
const int CAN_HEIGHT = 117*0.65;


class TrashCan : public Container
{
    int spriteNum;
    public:
        TrashCan(int,int);
        void Show(SDL_Renderer*);
        Mosquito* Breed(int);
        ~TrashCan();
};

#endif // TRASHCAN_H
