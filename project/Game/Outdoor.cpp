#include "Outdoor.h"
#include <random>
#include <iostream>

using namespace std;

Outdoor:: Outdoor()
{
    //screen dimensions
    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;

    //part of sprite clipped from spritesheet
    pos1.x = 0;
    pos1.y = 1805;
    pos1.w = 1024;
    pos1.h = 786;

    countPlants = 11;
    countWater = 3;
    countTrashcan = rand()%4;
    countManhole = rand()%3;
    countContainer = countPlants + countWater + countTrashcan + countManhole;

    container = new Container*[countContainer];
    int i = 0;
    for (int place = i; place<countPlants; place++)
    {
        container[place] = new Plant(600,600);
    }


    for (int place = i; place<countTrashcan; place++)
    {
        container[place] = new TrashCan(200,200);
    }

//    for (int place = i; place<countManhole; place++)
//    {
//        container[place] = new Manhole(125,150);
//    }

}

void Outdoor::Show(SDL_Renderer* renderer)
{
    //pos1.x += 1;
    Texture::GetInstance()->RenderBack(35, renderer, &pos1, &pos);
    container[0]->Show(renderer);
    container[5]->Show(renderer);
}


void Outdoor::Update(SDL_Event* e,Screens_Node& node)

{
        //If a key was pressed
    if( e->type == SDL_KEYDOWN )
        {
            if(pos1.x<0)
            {
                pos1.x = 0;
            }

            if(pos1.x + pos1.w >= 1024*2.5)
            {
                pos1.x = (1024*2.5) - pos1.w;
            }

            switch( e->key.keysym.sym )
            {
                case SDLK_LEFT: pos1.x -= 20; container[0]->SetX(20,0); cout<<"yes"<<endl; break;
                case SDLK_RIGHT: pos1.x += 20; container[0]->SetX(20,1); cout<<"ok"<<endl; break;
                default: break;
            }
        }
}


