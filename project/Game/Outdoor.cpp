#include "Outdoor.h"
#include <random>
#include <iostream>


using namespace std;

Outdoor:: Outdoor()
{
    //screen dimensions
    width = 1024*2.5;
    height = 460;

    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;


    //part of sprite clipped from spritesheet
    pos1.x = 0;
    pos1.y = 1805;
    pos1.w = 1024;
    pos1.h = 786;


    cartPos = new SDL_Rect;
    cartPos->x = 970;
    cartPos->y = 730;
    cartPos->w = 20;
    cartPos->h = 20;


    entrance = new Entrance*[12];
    house = new House[5]; //house count is 4 & 1 hospital

    for (int i = 0; i < 4; i++)
    {
        // Setting outdoor pointer in every house. To be used by mosquitoes and humans.
        house[i].SetOutdoor(this);
    }

    PlaceContainers();

    buildingRect= new SDL_Rect[4]; //clickable region for all 4 houses
    buildingRect[0].x=45;
    buildingRect[0].y=140;
    buildingRect[0].w=280;
    buildingRect[0].h=320;

    buildingRect[1].x=515;
    buildingRect[1].y=140;
    buildingRect[1].w=280;
    buildingRect[1].h=320;

    buildingRect[2].x=1138;
    buildingRect[2].y=140;
    buildingRect[2].w=280;
    buildingRect[2].h=320;

    buildingRect[3].x=1710;
    buildingRect[3].y=140;
    buildingRect[3].w=290;
    buildingRect[3].h=320;

    buildingRect[4].x = 2190;
    buildingRect[4].y = 130;
    buildingRect[4].w = 350;
    buildingRect[4].h = 350;
    //humans = GenerateHumans();
    //noOfEntrance = 0;
    hospital = new Hospital();
    GetHouseEntrance();
    shop = new ShoppingMenu;

//    points = new Score;

}

/*
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
*/

void Outdoor::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->RenderBack(35, renderer, &pos1, &pos);

    for(int i = 0; i<countContainer; i++ )
    {
        breedingplaces[i]->Show(renderer);
    }

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 0);
    SDL_RenderFillRect(renderer,cartPos);

    if(shop->shopShow)
        shop->Show(renderer);

    for (int i = 0; i < 12; i++)
    {
        if (entrance[i]!=NULL)
        {
            entrance[i]->ShowOutside(renderer);
        }
    }

    points.Show(renderer);
    money.Show(renderer);

    for (int i = 0; i < humans.GetLength(); i++)
    {
        humans.GiveItem(i)->Show(renderer);
    }

    //alert.Show(renderer);



//    for(int i = 0; i<4; i++)
//    {
//        SDL_RenderFillRect(renderer,&buildingRect[i]);
//    }

//
//    SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
//
//    for(int i = 0; i<4; i++)
//    {
//        SDL_RenderFillRect(renderer,&entranceRect[i]);
//    }



//    for(int i = 0; i<5; i++)
//    {
//        SDL_RenderFillRect(renderer,&buildingRect[i]);
//    }


}

int Outdoor::CountHumans()
{
    int sum = 0;
    for (int i = 0; i < 4; i++)
    {
        sum += house[i].NoOfHumans();
    }
    return sum;
}

void Outdoor::Update(int frame)
{
    for (int i = 0; i < 4; i++)
    {
        house[i].Update(frame);
    }

    for (int i = 0; i < humans.GetLength(); i++)
    {
        humans.GiveItem(i)->Update(frame);
    }

}


void Outdoor::HandleEvents(SDL_Event* e,Screens_Node& node)

{
    for (int i = 0; i<noOfBreedingPlaces; i++ ) ///to drag & drop lids on breeding places
    {
        breedingplaces[i]->HandleEvents(e,node);
    }

    shop->HandleEvents(e,node);

    if (e->type == SDL_MOUSEBUTTONDOWN)

    {
        int x = e->button.x;
        int y = e->button.y;

        for (int i = 0; i<4; i++)
        {
            if (x >= buildingRect[i].x && y >= buildingRect[i].y && x < buildingRect[i].x + buildingRect[i].w && y < buildingRect[i].y + buildingRect[i].h)
            {
                node.cur_screen = &house[i];
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
            }
        }

        if (x >= buildingRect[4].x && y >= buildingRect[4].y && x < buildingRect[4].x + buildingRect[4].w && y < buildingRect[4].y + buildingRect[4].h)
            {
                node.cur_screen = hospital;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
            }

        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            if( ( x > cartPos->x ) && ( x < (cartPos->x+cartPos->w) ) && ( y > cartPos->y ) && (y< (cartPos->y+cartPos->h) ) )
                shop->shopShow = true;
        }
    }
    if(e->key.keysym.sym == SDLK_ESCAPE)  //will open pause menu
    {
        node.cur_screen = new PauseMenu;
        node.prev_screen = this;
        node.prev_updatable = false;
        node.prev_backable = true;
    }

    HandleScrolling(e);
}

void Outdoor::GetHouseEntrance()
{
    Entrance** entry;
    for(int i = 0; i<4; i++ )
    {
        int n = 0;
        entry = house[i].GetEntrance(n);

        for(int x = 0; x<n; x++ )
        {
            entrance[noOfEntrance] = entry[x];

            entry[0]->SetOutdoorPos(buildingRect[i].x+160,372,225*0.25,298*0.25); //for door

            if(n==3) //if two windows
            {
                entry[1]->SetOutdoorPos(buildingRect[i].x+60,270,200*0.35,110*0.35);
                entry[2]->SetOutdoorPos(buildingRect[i].x+160,270,200*0.35,110*0.35);
            }
            if(n==2) //if one window
            {
                entry[1]->SetOutdoorPos(buildingRect[i].x+100,270,200*0.5,110*0.5);
            }
            noOfEntrance++;
        }
    }

    for (int i = noOfEntrance; i < 12; i++) // to point remaining entrance pointers to null
    {
        entrance[i] = NULL;
    }
}

void Outdoor:: HandleScrolling(SDL_Event* e)
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
                    for(int i = 0; i<noOfBreedingPlaces; i++ )
                    {
                        breedingplaces[i]->SetX(20,0);
                    }
                    for(int i = 0; i<noOfEntrance; i++ )
                    {
                        entrance[i]->SetOutdoorX(20,0);
                    }

                    for(int i = 0; i<5; i++)
                    {
                        buildingRect[i].x+=20;
                    }

                    for (int i = 0; i < humans.GetLength(); i++)
                    {
                        humans.GiveItem(i)->SetX(20,0);
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
                    for(int i = 0; i<noOfBreedingPlaces; i++ )
                    {
                        breedingplaces[i]->SetX(20,1);
                    }
                    for(int i = 0; i<noOfEntrance; i++ )
                    {
                        entrance[i]->SetOutdoorX(20,1);
                    }

                    for(int i = 0; i<5; i++)
                    {
                        buildingRect[i].x-=20;
                    }
                    for (int i = 0; i < humans.GetLength(); i++)
                    {
                        humans.GiveItem(i)->SetX(20,1);
                    }

                }
            }
        }
        //alert.HandleEvents(e,node);
}

void Outdoor:: PlaceContainers()
{
    noOfEntrance = 0; //initializing count
    countPlants = 11;
    countCleanWater = (rand()%2) + 2;
    countTrashcan = (rand()%4) + 2;
    countManhole = (rand()%2)+2;
    countContainer = countPlants + countTrashcan + (countManhole*2) + countCleanWater; //countDirtyWater = countManhole
    noOfBreedingPlaces = countContainer;
    breedingplaces = new BreedingGround*[countContainer];

    int plantPos[countPlants] = {345,440,780,860,940,1030,1435,1520,1600,2025,2095}; //fixed x-coordinates of plants
    int trashCanPos[4] = {650,1800,80,1060}; //fixed x-coordinates of trash Cans
    int manholePos[3] = {1500, 2270, 450};//fixed x-coordinates of manhole
    int DirtyWaterPos[3] = {1430, 2240, 400};
    //int TrashCanLidPos[4] = {500, 700, 1000, 1200};
    int CleanWaterPos[3] = {200, 2050, 1700};
    int ManholePosY[3] = {rand()%(110)+620,rand()%(110)+620,rand()%(110)+620};
    int i = 0; //iterator for breedingplacess
    for (int place = 0; place<countPlants; place++) //to place plants
    {
        breedingplaces[i] = new Plant(plantPos[place],320);
        i++;
    }

    for (int place = 0; place<countTrashcan; place++) //to place trash Cans
    {
        breedingplaces[i] = new TrashCan(trashCanPos[place],480);
        i++;
    }

    for (int place = 0; place<countManhole; place++) //to place DirtyWater, countDirtyWater = countManhole
    {
        breedingplaces[i] = new DirtyWater(DirtyWaterPos[place],ManholePosY[place]); // y b/w 730 & 730 px
        i++;
    }

    for (int place = 0; place<countManhole; place++) //to place Manholes
    {
        breedingplaces[i] = new Manhole(manholePos[place],ManholePosY[place]); // y b/w 730 & 730 px
        i++;
    }

    for (int place = 0; place<countCleanWater; place++) //to placeCleanWater
    {
        breedingplaces[i] = new CleanWater(CleanWaterPos[place],rand()%(110)+620); // y b/w 730 & 730 px
        i++;
    }
}

Outdoor :: ~Outdoor()
{
    delete[] buildingRect;
    delete[] house;
}


bool Outdoor::AddHuman(Human* human)
{
    humans.Append(human);
    return true;
}


