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

    houseRect= new SDL_Rect[4];
    entranceRect = new SDL_Rect[4];
    house = new House[4];
    houseRect[0].x=45;
    houseRect[0].y=140;
    houseRect[0].w=280;
    houseRect[0].h=320;

    houseRect[1].x=545;
    houseRect[1].y=115;
    houseRect[1].w=210;
    houseRect[1].h=350;

    houseRect[2].x=1138;
    houseRect[2].y=150;
    houseRect[2].w=280;
    houseRect[2].h=300;

    houseRect[3].x=1710;
    houseRect[3].y=150;
    houseRect[3].w=290;
    houseRect[3].h=300;

    entranceRect[0].x=45;
    entranceRect[0].y=261;
    entranceRect[0].w=278;
    entranceRect[0].h=189;

    entranceRect[1].x=539;
    entranceRect[1].y=261;
    entranceRect[1].w=224;
    entranceRect[1].h=189;

    entranceRect[2].x=1138;
    entranceRect[2].y=305;
    entranceRect[2].w=283;
    entranceRect[2].h=141;

    entranceRect[3].x=1707;
    entranceRect[3].y=262;
    entranceRect[3].w=302;
    entranceRect[3].h=179;


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

    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
    for(int i = 0; i<4; i++)
    {
        SDL_RenderFillRect(renderer,&entranceRect[i]);
    }
}


void Outdoor::Update(SDL_Event* e,Screens_Node& node)

{
        //If a key was pressed


    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e->button.x;
        int y = e->button.y;

        for (int i = 0; i<4; i++)
        {
            if (x >= houseRect[i].x && y >= houseRect[i].y && x < houseRect[i].x + houseRect[i].w && y < houseRect[i].y + houseRect[i].h)
            {
                node.cur_screen = &house[i];
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
            }
        }
    }
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

                    for(int i = 0; i<4; i++)
                    {
                        houseRect[i].x+=20;
                        entranceRect[i].x+=20;
                    }
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

                    for(int i = 0; i<4; i++)
                    {
                        houseRect[i].x-=20;
                        entranceRect[i].x-=20;
                    }
                }
            }
        }
}

Outdoor :: ~Outdoor()
{

}
