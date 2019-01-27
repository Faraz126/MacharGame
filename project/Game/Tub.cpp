#include "Tub.h"
#include <random>

Tub::Tub(int x, int y) : Container(x, y, TUB_WIDTH, TUB_HEIGHT)
{
    spriteNum = 66 + (rand()%4); //need to replace with updated spritesheet.
    if(pos.x==15)
    {
        lid = new TubLid(pos.x+200,pos.y);
    }
    if(pos.x==900)
    {
        lid = new TubLid(pos.x-200,pos.y);
    }
    percentage = 5;
    breedCount = 0;
}

void Tub::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x,pos.y-12); //set to right ahead of trashcan.
    }
    Container::SetCovered(status);
}

void Tub::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);
}

Mosquito* Tub::Breed()
{
    breedCount++;
    return factory->GetMosquito(AEDES);
}

void Tub::Update(int n)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

void Tub::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        lid->HandleEvents(e,node);
    }
    if (lid->Collides(*this))
    {
        SetCovered(true);
    }
}

int Tub :: GetBreedCount()
{
    return breedCount;
}

Tub::~Tub()
{

}

