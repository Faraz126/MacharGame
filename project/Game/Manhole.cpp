#include "Manhole.h"

Manhole::Manhole(int x, int y) : Container(x, y, MANHOLE_WIDTH, MANHOLE_HEIGHT)
{
    spriteNum = 62; //need to replace with updated spritesheet.
    myLid = noOflids;
    id = 3;
    lids[noOflids++] = new ManholeLid(pos.x+100,pos.y);
    percentage = 5;
    breedCount = 0;
}

void Manhole::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x+5,pos.y-20); //set to right ahead of trashcan.
    }
    Container::SetCovered(status);
}

void Manhole::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    //lid->Show(renderer);

}

void Manhole::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (!GetCovered())
    {
        for (int i =0; i < noOflids; i++)
        {

            lid = lids[i];
            if (lid != 0 && this->SameScenario(lid))
            {
                lid->HandleEvents(e, node);
            }

        }

    }

    for (int i = 0; i < noOflids; i++)
    {
        lid = lids[i];
        if (lid != 0 && this->SameScenario(lid) && lid->Collides(*this) && lid->CorrectID(this->id))
        {
            SetCovered(true);
            break;
        }
    }
}

Mosquito* Manhole::Breed()
{
    breedCount++;
    return factory->GetMosquito(AEDES);
}


void Manhole::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

int Manhole :: GetBreedCount()
{
    return breedCount;
}

Manhole::~Manhole()
{

}
