#include "House.h"
#include <random>

House::House()
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;


    noOfEntrance = (rand()%2) + 2;
    noOfHumans = (rand()%3) + 3;
    bed = new Bed[noOfHumans];
    entrance = new Entrance*[noOfEntrance];
    int x;
    if (rand() % 2) //random x co-ordinate for the door
    {
        x = 265;
        entrance[0] = new Door(100, 300);
    }
    else
    {
        x = 25;
        entrance[0] = new Door(750, 300);
    }

    for (int i = 0; i<noOfHumans; i++)
    {
        bed[i].SetPos(x, 365);
        x += 150;
    }




    if (noOfEntrance == 3)
    {
        entrance[1] = new Window(200,125);
        entrance[2] = new Window(600,125);
    }
    else
    {
        entrance[1] = new Window(412,125);
    }


}

void House::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(9, renderer, &pos);
    for(int i=0; i < noOfEntrance; i++)
    {
        entrance[i]->Show(renderer);
    }
    for(int i=0; i<noOfHumans; i++)
    {
        bed[i].Draw(renderer);
    }
}
