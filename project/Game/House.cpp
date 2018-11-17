#include "House.h"
#include <random>

House::House()
{
    pos.x = wall.x = 0;
    pos.y = wall.y = 0;
    pos.w = wall.w = 1024;
    pos.h = 786;
    wall.h = 488;

    noOfEntrance = rand()%2 + 2;
    noOfHumans = (rand()%3) + 3;
    bed = new Bed[noOfHumans];
    entrance = new Entrance*[noOfEntrance];
    int x;
    if (rand() % 2) //random x co-ordinate for the door
    {
        x = 265;
        entrance[0] = new Door(100, 300);
        breedingplaces = new TrashCan(10,450);
    }
    else
    {
        x = 10;
        entrance[0] = new Door(750, 300);
        breedingplaces = new TrashCan(925,450);
    }

    for (int i = 0; i<noOfHumans; i++)
    {
        bed[i].SetPos(x, 365);
        x += 150;
    }




    if (noOfEntrance == 3)
    {
        showpieces = new Showpiece[1];
        showpieces[0].SetPos(450, 150);
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
    breedingplaces->Show(renderer);

}

void House::Update(SDL_Event* e, Screens_Node& node)
{

}

