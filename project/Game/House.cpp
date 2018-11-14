#include "House.h"
#include <random>

House::House()
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;


    noOfEntrance = (rand()%2) + 3;
    entrance = new Entrance*[noOfEntrance];
    int x = (rand() % 850)+30; //random x co-ordinate for the door
    entrance[0] = new Door(x, 300);
    int seperation = 200 + (rand() % 100); // random distance of seperation of windows
    x = 100; //random starting position of windows

    for(int i = 1; i < noOfEntrance; i++)
    {
        entrance[i] = new Window(x +(seperation*(i-1)),125);
    }

    noOfHumans = (rand()%4) + 3;
    bed = new Bed[noOfHumans];
    x = 25;
    for(int i = 0; i <noOfHumans;)
    {
        if (!entrance[0]->WithinEntrance(x,400))
        {
            bed[i++].SetPos(x, 375);
            x += 145;
        }
        else
        {
            x += 130;
        }

    }

}

void House::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(9, renderer, &pos); //Highlight
    for(int i=0; i < noOfEntrance; i++)
    {
        entrance[i]->Show(renderer);
    }
    for(int i=0; i<noOfHumans; i++)
    {
        bed[i].Draw(renderer);
    }
}
