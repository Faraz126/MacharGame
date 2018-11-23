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
    countManhole = (rand()%2)+2;
    countContainer = countPlants + countTrashcan + countManhole;

    container = new Container*[countContainer];
    entrance = new Entrance*[12];
    house = new House[4]; //house count is 4

    int plantPos[countPlants] = {345,440,780,860,940,1030,1435,1520,1600,2025,2095}; //fixed x-coordinates of plants
    int trashCanPos[4] = {650,1800,80,1060}; //fixed x-coordinates of trash Cans
    int manholePos[3] = {1500, 2270, 450};//fixed x-coordinates of manhole
    int TrashCanLidPos[4] = {500, 700, 1000, 1200};

    int i = 0; //iterator for containers
    for (int place = 0; place<countPlants; place++) //to place plants
    {
        container[i] = new Plant(plantPos[place],320);
        i++;
    }

    for (int place = 0; place<countTrashcan; place++) //to place trash Cans
    {
        container[i] = new TrashCan(trashCanPos[place],480);
        //Lids[i] = new TrashCanLid(TrashCanLidPos[place], 540);
        i++;
    }

    for (int place = 0; place<countManhole; place++) //to place Manholes
    {
        container[i] = new Manhole(manholePos[place],730);
        i++;
    }

    houseRect= new SDL_Rect[4]; //clickable region for all 4 houses
    entranceRect = new SDL_Rect[4]; //region for windows & doors for all 4 houses
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
    entranceRect[0].h=185;

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
    humans = GenerateHumans();
    GetHouseEntrance();
}

Human** Outdoor::GenerateHumans()
{
    int n = CountHumans();
    Human** temp = new Human*[n];
    for (int i = 0; i < n; i++)
    {
        temp[i] = 0;
    }
    return temp;
}

void Outdoor::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->RenderBack(35, renderer, &pos1, &pos);

    for(int i = 0; i<countContainer; i++ )
    {
        container[i]->Show(renderer);
    }

    for (int i = 0; i < 12; i++)
    {
        if (entrance[i]!=NULL)
        {
            entrance[i]->ShowOutside(renderer);
        }
    }


//    for(int i = 0; i<4; i++)
//    {
//        SDL_RenderFillRect(renderer,&houseRect[i]);
//    }

//    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
//    for(int i = 0; i<4; i++)
//    {
//        SDL_RenderFillRect(renderer,&entranceRect[i]);
//    }
}

int Outdoor::CountHumans()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += house[i].NoOfHumans();
    }
}

void Outdoor::Update(int frame)
{
    for (int i = 0; i < 4; i++)
    {
        house[i].Update(frame);
    }
}


void Outdoor::HandleEvents(SDL_Event* e,Screens_Node& node)

{
    for (int i = 0; i<countContainer; i++ )
    {
        container[i]->EventHandle(e);
    }

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

                    for(int i = 0; i<4; i++)
                    {
                        houseRect[i].x+=20;
                        entranceRect[i].x += 20;
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
                        entranceRect[i].x -= 20;
                    }

                }
            }
        }
}

Outdoor :: ~Outdoor()
{
    for (int i = 0; i <countContainer; i++)
    {
        delete container[i];
    }

    delete[] entranceRect;
    delete[] houseRect;
    delete[] house;
}

void Outdoor::GetHouseEntrance()
{
    int c = 0;
    Entrance** entry;
    for(int i = 0; i<4; i++ )
    {
        int n = 0;
        entry = house[i].GetEntrance(n);

        for(int x = 0; x<n; x++ )
        {
            entrance[c] = entry[x];

            entry[0]->SetOutdoorPos(houseRect[i].x+150,200,145,188);

            if(n==3)
            {
                entry[1]->SetOutdoorPos(houseRect[i].x+100,70,110,200);
                entry[2]->SetOutdoorPos(houseRect[i].x+200,70,110,200);
            }
            if(n==2)
            {
                entry[1]->SetOutdoorPos(houseRect[i].x+100,70,110,200);
            }
            c++;
        }
    }

    for (int i = c; i < 12; i++)
    {
        entrance[i] = NULL;
    }
}
