#include "House.h"
#include <random>

House::House()
{
    pos.x = wall.x = 0;
    pos.y = wall.y = 0;
    pos.w = wall.w = width = 1024;
    pos.h = height = 786;
    wall.h = 488;

    noOfEntrance = (rand() % 2) + 2;
    noOfHumans = (rand()%3) + 3;
    bed = new Bed[noOfHumans];
    breedingplaces = new BreedingGround*[3];
    for (int i = 0; i< 3; i++)
    {
        breedingplaces[i] = 0;
    }
    entrance = new Entrance*[noOfEntrance];
    int x;
    if (rand() % 2) //random x co-ordinate for the door
    {
        x = 265;
        entrance[0] = new Door(100, 300);
        breedingplaces[0] = new TrashCan(10,450);
        myQ.push_back(breedingplaces[0]);
    }
    else
    {
        x = 10;
        entrance[0] = new Door(750, 300);
        breedingplaces[0] = new TrashCan(925,450);
        myQ.push_back(breedingplaces[0]);
    }

    for (int i = 0; i<noOfHumans; i++)
    {
        bed[i].SetPos(x, 365);
        myQ.push_back(&bed[i]);
        x += 150;
    }
    if (noOfEntrance == 3)
    {
        showpieces = new Showpiece[2];
        showpieces[0].SetPos(467, 132, 26);
        showpieces[1].SetPos(200, 600, 70);
        entrance[1] = new Window(200,125);
        entrance[2] = new Window(600,125);
    }
    else
    {
        showpieces = new Showpiece[3];
        showpieces[0].SetPos(100, 150);
        showpieces[1].SetPos(700, 150);
        showpieces[2].SetPos(200, 600, 70);
        entrance[1] = new Window(412,125);
    }

    noOfBreedingPlaces = 1;
    int y = 500;
    while (noOfBreedingPlaces < 3 && y < 800)
    {
        if (rand()%3 == 1)
        {
            if (rand()%2 == 1)
            {
                breedingplaces[noOfBreedingPlaces] = new Tub(15, y);

            }
            else
            {
                breedingplaces[noOfBreedingPlaces] = new Tub(900, y);
            }
            myQ.push_back(breedingplaces[noOfBreedingPlaces]);
            breedingplaces[noOfBreedingPlaces++]->ReduceSize(float(y)/1600);

        }
        y += 100;
    }
    btn = new Button;
    myQ.push_back(btn);
    btn->setPosition(800,10);
    btn->SetWidth(200,55);
    btn->setText("OUTDOOR");
    btn->word->ReduceSize(0.8);
    humans = new Human*[noOfHumans];
    for (int i = 0; i < noOfHumans; i++)
    {
        humans[i] = new Human((i*30), 388 + (i*90),this);
        myQ.push_back(humans[i]);
    }



}

void House::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(9, renderer, &pos);

    //SDL_SetRenderDrawColor(renderer, 30,30,30,0); //wall feature
    //SDL_RenderFillRect(renderer, &wall);


    for(int i=0; i < noOfEntrance; i++)
    {
        entrance[i]->Show(renderer);
    }
    /*
    for(int i=0; i<noOfHumans; i++)
    {
        bed[i].Show(renderer);
    }
    if (noOfEntrance == 3)
    {
        showpieces[0].Show(renderer);
        showpieces[1].Show(renderer);
    }
    else
    {
        showpieces[0].Show(renderer);
        showpieces[1].Show(renderer);
        showpieces[2].Show(renderer);
    }
    for (int i = 0; i < 3; i++)
    {
        if (breedingplaces[i] != 0)
        {
            breedingplaces[i]->Show(renderer);
        }
    }

    for (int i = 0; i < noOfHumans; i++)
    {
        humans[i]->Show(renderer);
    }
//    humans->Show(renderer);

    btn->Show(renderer);
    */
    for (int i = 0; i < myQ.size(); i++)
    {
        myQ[i]->Show(renderer);
    }

}

void House::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (e->type == SDL_QUIT)
    {
        SDL_Quit();
    }
    else if( e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int mousePosX = e->button.x;
        int mousePosY = e->button.y;

        for (int i = 0; i < noOfEntrance; i++)
        {
            if (entrance[i]->WithinRegion(mousePosX, mousePosY))
            {
                entrance[i]->ChangeState();
            }

        }
         if (btn->WithinRegion(mousePosX,mousePosY))  //for outdoor button in house
        {
            node.cur_screen = node.prev_screen;
            node.prev_screen = this;
        }

        for (int i = 0; i < noOfHumans; i++)
        {
            humans[i]->HandleEvents(e, node);
        }
    }

}


void House::Update(int frame)
{
    for (int i = 0; i <noOfEntrance; i++)
    {
        entrance[i]->Update(frame);
    }

    for (int i = 0; i < noOfHumans; i++)
    {
        humans[i]->Update(frame);
    }
}

Bed* House::GetClosestBed(int x, int y) //pass on Human x co-ordinates here
{
    Bed* minimum = &bed[0];
    int dist = bed[0].GetDistance(x,y);

    for (int i = 1; i < noOfHumans; i++)
    {
        if (!bed[i].GetOccupied())
        {
            int temp = bed[i].GetDistance(x,y);
            if (temp < dist)
            {
                minimum = &bed[i];
                dist = temp;
            }
        }
    }
    return minimum;
}

Door* House::GetDoor()
{
    return static_cast<Door*>(entrance[0]);
}

House::~House()
{
    delete[] bed;

    for (int i = 0; i <noOfEntrance; i++)
    {
        delete entrance[i];
    }
    delete[] entrance;
    delete breedingplaces;
    delete[] showpieces;
}

void House::ShowOutside(SDL_Renderer* renderer, const SDL_Rect& rect)
{
    float div = wall.w / rect.w;
    for (int i = 0; i < noOfEntrance; i++)
    {
        entrance[i]->ShowOutside(renderer, rect, div);
    }

}


int House::NoOfHumans()
{
    return noOfHumans;
}


Bed* House::GetBeds(int &n)
{
    n = noOfHumans;
    return bed;
}



Human** House::GetHumans(int & n)
{
    n = noOfHumans;
    return humans;
}


int House::GetWidth()
{
    return width;
}

int House::GetHeight()
{
    return height;
}
