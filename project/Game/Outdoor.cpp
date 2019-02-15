#include "Outdoor.h"
#include "Hospital.h"


using namespace std;

Outdoor:: Outdoor(Screens* screen, bool back): Scenario(screen, back)
{
    //screen dimensions
    Alert::SetUpRects();
    code = 0;
    startWidth = 0;
    endWidth = 1024*1.5;
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
    house = new House[4]; //house count is 4
    hospital = new Hospital(this); //one hospital in outdoor

    for (int i = 0; i < 4; i++)
    {
        // Setting outdoor pointer in every house. To be used by mosquitoes and humans.
        house[i].SetOutdoor(this);
    }

//    for (int i = 0; i < 4; i ++)
//    {
//        house[i].SetOutdoor(this);
//    }

    PlaceContainers();
    //Load(file);

    house[0].SetOutdoorPos(10,268,280,320);
    house[1].SetOutdoorPos(360,247,239,340);
    house[2].SetOutdoorPos(605,268,290,320);
    house[3].SetOutdoorPos(1060,269,290,320);
    hospital->SetOutdoorPos(1330,250,350,350);

    for(int i = 0; i<4; i++)
    {
        house[i].ReduceSize(0.6);
    }
    hospital->ReduceSize(0.6);
    //humans = GenerateHumans();
    //noOfEntrance = 0;

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

    for(int i = 0; i<4; i++)
    {
        house[i].ShowOutside(renderer,i);
    }
    hospital->ShowOutside(renderer, 4);


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



    for (int i = 0; i < noOfEntrance; i++)
    {
        entrance[i]->Update(frame);
    }

    points->people = 0;
    points->ChangeStatus(GREEN);

    for (int i = 0; i < Alert::humans->GetLength(); i++)
    {
        if (Alert::humans->GiveItem(i)->GetTimeToDie() < 0)
        {
            curScreen = new EndMenu(this, true);
        }
        else if (Alert::humans->GiveItem(i)->GetTimeToDie() < 200000/4)
        {

            if (points->status == RED)
            {
               points->people++;
            }
            else
            {
                points->people = 1;
            }
            points->ChangeStatus(RED);

        }
        else
        {
            if (points->status != RED)
            {
                points->ChangeStatus(ORANGE);
                points->people++;
            }
        }
    }
    for (int i = 0; i < myQ.GetLength(); i++)
    {


        if(myQ.GiveItem(i)->IsActive() && myQ.GiveItem(i)->DelayLidTime()>1000) //if container is covered and alloted time has passed
        {
            Clickable* myM = myQ.GiveItem(i);
            myQ.Pop(i);
            delete myM;
            break;
        }
        else
        {
            myQ.GiveItem(i)->Update(frame);
        }


    }
    for (int i = 0; i < mosquitoes.GetLength(); i++)
    {
        if (mosquitoes.GiveItem(i)->GetIsDead())
        {
            Mosquito* myM = mosquitoes.GiveItem(i);
            mosquitoes.Pop(i);
            //delete myM;
            break;
        }
        else
        {
            mosquitoes.GiveItem(i)->Update(frame);
        }
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
            if (x >= house[i].GiveOutdoorPosX() && y >= house[i].GiveOutdoorPosY() && x < house[i].GiveOutdoorPosX() + house[i].GiveOutdoorPosW() && y < house[i].GiveOutdoorPosY() + house[i].GiveOutdoorPosH())
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
        if (x >= hospital->GiveOutdoorPosX() && y >= hospital->GiveOutdoorPosY() && x < hospital->GiveOutdoorPosX() + hospital->GiveOutdoorPosW() && y < hospital->GiveOutdoorPosY() + hospital->GiveOutdoorPosH())
            {
                /*
                node.cur_screen = hospital;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
                */
                curScreen = hospital;
                Texture::GetInstance()->SetSound(HOSPITAL);

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

            entry[0]->SetOutdoorPos(house[i].GiveOutdoorPosX()+85,400,225*0.17,298*0.17); //for door
            //house[0].SetOutdoorPos(20,300,280,320);

            if(n==3) //if two windows
            {
                int center = (house[i].GiveOutdoorPosW() - (40 + 10 + 40))/2;
                entry[1]->SetOutdoorPos(house[i].GiveOutdoorPosX() + center,360,200*0.2,110*0.2);
                entry[2]->SetOutdoorPos(house[i].GiveOutdoorPosX() + center + 40 + 10,360,200*0.2,110*0.20);
            }
            if(n==2) //if one window
            {
                int center = (house[i].GiveOutdoorPosW() - (40))/2;
                entry[1]->SetOutdoorPos(house[i].GiveOutdoorPosX()+center,360,200*0.2,110*0.2);
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


                    for(int i = 0; i<4; i++)
                    {
                        house[i].SetOutdoorX(20,0);
                    }
                    hospital->SetOutdoorX(20,0);

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

            if(pos1.x + pos1.w >= 1024*1.5) //to not go beyond screen width
            {
                pos1.x = (1024*1.5) - pos1.w;
            }

            if (pos1.x + pos1.w < 1024*1.5) //allow right key press event only if in screen bound
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

                    for (int i = 0; i < myQ.GetLength(); i++)
                    {
                        myQ.GiveItem(i)->SetX(20,1);
                    }
                    for(int i = 0; i<4; i++)
                    {
                        house[i].SetOutdoorX(20,1);
                    }
                    hospital->SetOutdoorX(20,1);

                    for (int i = 0; i < mosquitoes.GetLength(); i++)
                    {
                        mosquitoes.GiveItem(i)->SetX(20,1);
                    }

                }
            }
        }
        //alert.HandleEvents(e,node);
}

int Outdoor::Roll(int mn, int mx)
{
    return (rand()%mx) + mn;
}

void Outdoor:: PlaceContainers()
{
    noOfEntrance = 0; //initializing count
    countPlants = 7;
    countCleanWater = Roll(1,2);
    countTrashcan = Roll(2,2);
    countManhole = Roll(2,2);
    countContainer = countPlants + countTrashcan + (countManhole*2) + countCleanWater; //countDirtyWater = countManhole
    noOfBreedingPlaces = countContainer;
    breedingplaces = new BreedingGround*[countContainer];

    int plantPos[countPlants] = {170,260,515,780,870,970,1245}; //fixed x-coordinates of plants
    int trashCanPos[3] = {550,40,1300}; //fixed x-coordinates of trash Cans
    int manholePos[3] = {900, 1320, 450};//fixed x-coordinates of manhole
    int DirtyWaterPos[3] = {830, 1250, 400};
    int CleanWaterPos[2] = {200, 1070};
    int ManholePosY[3] = {(rand()%(110))+620,(rand()%(110))+620,(rand()%(110))+620};
    int i = 0; //iterator for breedingplacess

    for (int place = 0; place<countPlants; place++) //to place plants
    {

        breedingplaces[i] = new Plant(plantPos[place],330);
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




    for (int place = 0; place<countCleanWater; place++) //to placeCleanWater
    {
        int x = CleanWaterPos[place];
        int y = (rand()%(110))+620;
        breedingplaces[i] = new CleanWater(CleanWaterPos[place],y); // y b/w 730 & 730 px
        while (Collides(breedingplaces[i]))
        {
            breedingplaces[i]->UpdatePos(++x,++y);
        }
        breedingplaces[i]->ReduceSize(0.8);
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
    int sizes = myQ.GetLength();
    for (int i = 0; i < sizes; i++)
    {
        delete myQ.Pop();
    }

    sizes = mosquitoes.GetLength();
    for (int i = 0; i < sizes; i++)
    {
        delete mosquitoes.Pop();
    }

    while (!Alert::humans->IsEmpty())

    {

        Alert::humans->Pop();
    }


    //delete house;
    delete hospital;
    delete upperRect;

}

