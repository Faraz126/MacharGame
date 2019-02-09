#include "TrashCan.h"

TrashCan::TrashCan(int x, int y): Container(x,y,CAN_WIDTH, CAN_HEIGHT)
{
    id = 1;
    spriteNum = 65;
    ownRect = {x,y,CAN_WIDTH, CAN_HEIGHT};
    pos.y = (y + CAN_HEIGHT - 15);
    pos.w = CAN_WIDTH;
    pos.h = 20;
    myLid = noOflids;
    lids[noOflids++] = new TrashCanLid(ownRect.x, ownRect.y + 100); //creating trash can lid at the given point

    percentage = 5;
    breedCount = 0;
}



void TrashCan::SetX(int delta, int direction)
{
    if ( direction == 0)
    {
        ownRect.x+=delta;
    }
    if ( direction == 1)
    {
        ownRect.x -=delta;
    }
    Container::SetX(delta, direction);
}

void TrashCan::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(ownRect.x-6,ownRect.y-14); //set to right ahead of trashcan.
    }
    Container::SetCovered(status);
}

void TrashCan::Collision()
{
    if ((rand()%50) < 25)
    {
        return;
    }

    if (GetCovered())
    {
        lid->SetPosition(ownRect.x, ownRect.y + 100);
        SetCovered(false);
    }

}


void TrashCan::HandleEvents(SDL_Event* e, Screens_Node& node)
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
        if (lid != 0 && this->SameScenario(lid) && lid->Collides(ownRect) && lid->CorrectID(this->id))
        {
            SetCovered(true);
            break;
        }
    }


}


void TrashCan::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &ownRect);
    //SDL_RenderDrawRect(renderer, &pos);
    for (int i = 0; i < noOflids; i++)
    {

        if (lids[i] != 0 && this->SameScenario(lids[i]))
            lids[i]->Show(renderer);
    }

}

TrashCan::~TrashCan()
{
    //dtor
}

Mosquito* TrashCan::Breed()
{
    breedCount++;
    return factory->GetMosquito(NORMAL);
}

void TrashCan::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

int TrashCan :: GetBreedCount()
{
    return breedCount;
}
