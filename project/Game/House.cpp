#include "House.h"
#include <random>

House::House()
{
    pos.x = wall.x = 0;
    pos.y = wall.y = 0;
    pos.w = wall.w = 1024;
    pos.h = 786;
    wall.h = 488;

    noOfEntrance = (rand() % 2) + 2;
    noOfHumans = (rand()%3) + 3;
    bed = new Bed[noOfHumans];
    breedingplaces = new BreedingGround*[3];
    //humans = new Human(this);
    entrance = new Entrance*[noOfEntrance];
    int x;
    if (rand() % 2) //random x co-ordinate for the door
    {
        x = 265;
        entrance[0] = new Door(100, 300);
        breedingplaces[0] = new TrashCan(10,450);
    }
    else
    {
        x = 10;
        entrance[0] = new Door(750, 300);
        breedingplaces[0] = new TrashCan(925,450);
    }

    for (int i = 0; i<noOfHumans; i++)
    {
        bed[i].SetPos(x, 365);
        x += 150;
    }
    if (noOfEntrance == 3)
    {
        showpieces = new Showpiece();
        showpieces[0].SetPos(467, 132, 26);
        entrance[1] = new Window(200,125);
        entrance[2] = new Window(600,125);
    }
    else
    {
        showpieces = new Showpiece[2];
        showpieces[0].SetPos(100, 150);
        showpieces[1].SetPos(700, 150);
        entrance[1] = new Window(412,125);
    }

    noOfBreedingPlaces = 1;
    x = 50;
    while (noOfBreedingPlaces < 3 && x < 800)
    {
        if (rand()%3 == 1)
        {
            breedingplaces[noOfBreedingPlaces++] = new Tub(x, 650);
        }
        else
        {
            breedingplaces[noOfBreedingPlaces] = 0;
        }
        x += 200;
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
    for(int i=0; i<noOfHumans; i++)
    {
        bed[i].Draw(renderer);
    }
    if (noOfEntrance == 3)
    {
        showpieces[0].Show(renderer);
    }
    else
    {
        showpieces[0].Show(renderer);
        showpieces[1].Show(renderer);
    }
    for (int i = 0; i < 3; i++)
    {
        if (breedingplaces[i] != 0)

        {
            breedingplaces[i]->Show(renderer);
        }

    }

}

void House::Update(SDL_Event* e, Screens_Node& node)
{
    for (int i = 0; i <noOfEntrance; i++)
    {
        entrance[i]->Update(e, node);
    }


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
    }

}

Bed* House::GetClosestBed(int x) //pass on Human x co-ordinates here
{
    Bed* minimum = &bed[0];
    int dist = bed[0].GetDistance(x);

    for (int i = 1; i < noOfHumans; i++)
    {
        if (!bed[i].GetOccupied())
        {
            int temp = bed[i].GetDistance(x);
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
