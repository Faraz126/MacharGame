#include "Outdoor.h"
#include <random>

Outdoor:: Outdoor()
{
    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;

    countPlants = 11;
    countSoil = 2;
    countTrashcan = rand()%4;
    countManhole = rand()%3;
    countContainer = countPlants + countSoil + countTrashcan + countManhole;
}

void Outdoor::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(35, renderer, &pos); //Highlight
}

void Outdoor::Update(SDL_Event* e, Screens_Node& node)
{

}
