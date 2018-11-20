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
    countTrashcan = (rand()%4) + 2;
    countManhole = rand()%3;
    countContainer = countPlants + countTrashcan;

    container = new Container*[countContainer];

//    house1 = new house
    int PlantPos[countPlants] = {345,440,780,860,940,1030,1435,1520,1600,2025,2095}; //fixed positions of plants
    int TrashCanPos[4] = {650,1800,100,1060};
    int i = 0; //iterator for containers
    for (int place = 0; place<countPlants; place++)
    {
        container[i] = new Plant(PlantPos[place],320);
        i++;
    }

    for (int place = 0; place<countTrashcan; place++)
    {
        container[i] = new TrashCan(TrashCanPos[place],480);
        i++;

    }
//    for (int place = i; place<countManhole; place++)
//    {
//        container[place] = new Manhole(125,150);
//    }

}

void Outdoor::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->RenderBack(35, renderer, &pos1, &pos);

    for(int i = 0; i<countContainer; i++ )
    {
        container[i]->Show(renderer);
    }
}


void Outdoor::Update(SDL_Event* e,Screens_Node& node)

{
        //If a key was pressed
    if( e->type == SDL_KEYDOWN )
        {
            if(pos1.x < 0) //to stay inside screen width
            {
                pos1.x = 0;
            }

            if (pos1.x > 0) //allow left key press event only if in screen bound
            {
                if (e->key.keysym.sym == SDLK_LEFT )
                {
                    pos1.x -= 20;
                    for(int i = 0; i<countContainer; i++ )
                    {
                        container[i]->SetX(20,0);
                    }
                    cout<<"yes"<<endl;
                }
            }

            if(pos1.x + pos1.w >= 1024*2.5) //to not go beyond screen width
            {
                pos1.x = (1024*2.5) - pos1.w;
            }

            if (pos1.x + pos1.w < 1024*2.5) //allow right key press event only if in screen bound
            {
                if (e->key.keysym.sym == SDLK_RIGHT )
                {
                    pos1.x += 20;
                    for(int i = 0; i<countContainer; i++ )
                    {
                        container[i]->SetX(20,1);
                    }
                    cout<<"ok"<<endl;
                }
            }
        }
}


