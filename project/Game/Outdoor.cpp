#include "Outdoor.h"
#include "Hospital.h"


using namespace std;

Outdoor:: Outdoor(Screens* screen, bool back): Scenario(screen, false)
{
    //screen dimensions
    code = 0;
    startWidth = 0;
    endWidth = 1024*2.5;
    startHeight = 460;
    endHeight = 786;

    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;


    //part of sprite clipped from spritesheet
    pos1.x = 0;
    pos1.y = 1805;
    pos1.w = 1024;
    pos1.h = 786;

    entrance = new Entrance*[12];
    house = new House[5]; //house count is 4 & 1 hospital

    for (int i = 0; i < 4; i++)
    {
        // Setting outdoor pointer in every house. To be used by mosquitoes and humans.
        house[i].SetOutdoor(this);
    }

    for (int i = 0; i < 4; i ++)
    {
        house[i].SetOutdoor(this);
    }

    PlaceContainers();
    //Load(file);


    buildingRect= new SDL_Rect[4]; //clickable region for all 4 houses & hospital
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
    hospital = new Hospital(this);
    GetHouseEntrance();
    SetUpScenarios();

    upperRect = new SDL_Rect;

    upperRect->x = 0;
    upperRect-> y =0;
    upperRect->x = 1240;
    upperRect->h = 55;


//    points = new Score;

}



void Outdoor::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->RenderBack(35, renderer, &pos1, &pos);

    for (int i = 0; i < 12; i++)
    {
        if (entrance[i]!=NULL)
        {
            entrance[i]->ShowOutside(renderer);
        }
    }

    for(int i = 0; i<myQ.GetLength(); i++ )
    {
        myQ.GiveItem(i)->Show(renderer);
    }

    SDL_SetRenderDrawColor( renderer, 255, 255, 255, 0);


    SDL_SetRenderDrawColor( renderer, 2,85,89,0 );
    SDL_RenderDrawRect(renderer,upperRect);
    SDL_RenderFillRect(renderer,upperRect);
    points->Show(renderer);
    Texture::GetInstance()->SoundRender(6);
   // alert.Show(renderer);



    for (int i = 0; i < mosquitoes.GetLength(); i++)
    {
        mosquitoes.GiveItem(i)->Show(renderer);
    }





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

void Outdoor::Update(int frame) ///to update all objects
{

    for (int i = 0; i < 4; i++)
    {
        if ( &house[i] != curScreen)
        {
            house[i].Update(frame);
        }

    }

    for (int i = 0; i < myQ.GetLength(); i++)
    {
        myQ.GiveItem(i)->Update(frame);
        /*
        if(myQ.GiveItem(i)->IsActive() && myQ.GiveItem(i)->DelayLidTime()>1000) //if container is covered and alloted time has passed
        {
            delete myQ.Pop(i);
        }
        */

    }
    for (int i = 0; i < mosquitoes.GetLength(); i++)
    {
        mosquitoes.GiveItem(i)->Update(frame);
    }

    for (int i = 0; i < noOfEntrance; i++)
    {
        entrance[i]->Update(frame);
    }

}


void Outdoor::HandleEvents(SDL_Event* e,Screens_Node& node)

{
   // alert.HandleEvents(e,node);
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        myQ.GiveItem(i)->HandleEvents(e, node);
    }

    if (e->type == SDL_MOUSEBUTTONDOWN)

    {
        int x = e->button.x;
        int y = e->button.y;

        for (int i = 0; i<4; i++)
        {
            if (x >= buildingRect[i].x && y >= buildingRect[i].y && x < buildingRect[i].x + buildingRect[i].w && y < buildingRect[i].y + buildingRect[i].h)
            {
                /*
                node.cur_screen = &house[i];
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
                */
                curScreen = &house[i];

                //speed
            }
        }
            //for hospital
        if (x >= buildingRect[4].x && y >= buildingRect[4].y && x < buildingRect[4].x + buildingRect[4].w && y < buildingRect[4].y + buildingRect[4].h)
            {
                /*
                node.cur_screen = hospital;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
                */
                curScreen = hospital;
            }


    }
    if(e->key.keysym.sym == SDLK_ESCAPE)  //will open pause menu
    {
        /*
        node.cur_screen = new PauseMenu(this);
        node.prev_screen = this;
        node.prev_updatable = false;
        node.prev_backable = true;
        */
        curScreen = new PauseMenu(this, this, true);
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
                    startWidth += 20;
                    endWidth += 20;
                    pos1.x -= 20;
                    for(int i = 0; i<myQ.GetLength(); i++ )
                    {
                        myQ.GiveItem(i)->SetX(20,0);
                    }
                    for(int i = 0; i<noOfEntrance; i++ )
                    {
                        entrance[i]->SetOutdoorX(20,0);
                    }

                    for(int i = 0; i<5; i++)
                    {
                        buildingRect[i].x+=20;
                    }
                    /*
                    for (int i = 0; i < humans.GetLength(); i++)
                    {
                        humans.GiveItem(i)->SetX(20,0);
                    }
                    */
                    for (int i = 0; i < mosquitoes.GetLength(); i++)
                    {
                        mosquitoes.GiveItem(i)->SetX(20,0);
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
                    startWidth -= 20;
                    endWidth -= 20;
                    pos1.x += 20;

                    for(int i = 0; i<noOfEntrance; i++ )
                    {
                        entrance[i]->SetOutdoorX(20,1);
                    }

                    for(int i = 0; i<5; i++)
                    {
                        buildingRect[i].x-=20;
                    }
                    for (int i = 0; i < myQ.GetLength(); i++)
                    {
                        myQ.GiveItem(i)->SetX(20,1);
                    }
                    for (int i = 0; i < mosquitoes.GetLength(); i++)
                    {
                        mosquitoes.GiveItem(i)->SetX(20,1);
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
        myQ.Append(breedingplaces[i]);
        i++;
    }

    for (int place = 0; place<countTrashcan; place++) //to place trash Cans
    {
        int x = trashCanPos[place];
        int y = 480;
        breedingplaces[i] = new TrashCan(trashCanPos[place],480);
        while (Collides(breedingplaces[i]))
        {
            breedingplaces[i]->UpdatePos(++x,++y);
        }
        myQ.Append(breedingplaces[i]);
        i++;
    }

    for (int place = 0; place<countManhole; place++) //to place DirtyWater, countDirtyWater = countManhole
    {
        breedingplaces[i] = new DirtyWater(DirtyWaterPos[place],ManholePosY[place]); // y b/w 730 & 730 px
        myQ.Append(breedingplaces[i]);
        i++;
    }

    for (int place = 0; place<countManhole; place++) //to place Manholes
    {
        breedingplaces[i] = new Manhole(manholePos[place],ManholePosY[place]); // y b/w 730 & 730 px
        myQ.Append(breedingplaces[i]);
        i++;
    }

    for (int place = 0; place<countCleanWater; place++) //to placeCleanWater
    {
        int x = CleanWaterPos[place];
        int y = rand()%(110)+620;
        breedingplaces[i] = new CleanWater(CleanWaterPos[place],y); // y b/w 730 & 730 px
        while (Collides(breedingplaces[i]))
        {
            breedingplaces[i]->UpdatePos(++x,++y);
        }
        myQ.Append(breedingplaces[i]);

        i++;
    }
}

void Outdoor::Delete()
{
    delete this;
}

Outdoor :: ~Outdoor()
{
    //delete[] buildingRect;
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        delete myQ.GiveItem(i);
    }

    for (int i = 0; i < mosquitoes.GetLength(); i++)
    {
        if ((mosquitoes.GiveItem(i)) != 0)
        {
            delete mosquitoes.GiveItem(i);
        }
    }

    delete[] house;
    delete hospital;
    delete upperRect;
}


