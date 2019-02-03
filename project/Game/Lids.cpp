#include "Lids.h"

Lids::Lids(int x, int y, int w, int h): Clickable(x,y,w,h)
{
    mouseClick = false;

}

Lids::~Lids()
{

}


void Lids::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int x = e->button.x;
    int y = e->button.y;
    if ((e->type == SDL_MOUSEBUTTONDOWN) && (e->button.button == SDL_BUTTON_LEFT) && WithinRegion(x,y))
    {
        lidOrignalPosX = pos.x;
        lidOrignalPosY = pos.y;
        mouseClick = true;
    }

    if ((e->type == SDL_MOUSEBUTTONUP) && mouseClick)

    {
        mouseClick = false;
        pos.x = lidOrignalPosX;
        pos.y = lidOrignalPosY;
    }
    if (mouseClick == true)
    {
        pos.x = x;
        pos.y = y;
    }

}

void Lids::Write(std::fstream& file)
{
    file << pos.x << "\n";
    file << pos.y << "\n";
    file << pos.w << "\n";
    file << pos.h << "\n";
}

void Lids::Read(std::fstream& file)
{
    std::string myString;
    getline(file, myString);
    pos.x = std::stoi(myString);
    getline(file, myString);
    pos.y = std::stoi(myString);
    getline(file, myString);
    pos.w = std::stoi(myString);
    getline(file, myString);
    pos.h = std::stoi(myString);
}


void Lids::SetPosition(int x, int y)
{
    pos.x = x;
    pos.y = y;
    mouseClick = false;
}

void Lids:: SetX(int delta, int direction)
{
    if ( direction == 0)
    {
        pos.x+=delta;

    }
    if ( direction == 1)
    {
        pos.x-=delta;
    }
}
