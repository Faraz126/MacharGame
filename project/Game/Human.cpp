/*

#include "Human.h"
#include "House.h"

Human::Human()
{

}

Human::Human(House* PersonHouse)
{
    infected = false;
    position.x = 0;
    position.y = 450;
    position.w = 178;
    position.h = 412;
    clip = 15;
    house = PersonHouse;
    IsIndoor = true;
    IsOutdoor = false;
}

Human::~Human()
{

}

void Human::Update()
{
    if(GetIsIndoor() == true)
    {
        Walking();
        if(Sit() == true && rand() % 5 == 4)
        {

        }
        else
        {
            Walking();
        }
    }
    if(GetIsOutdoor() == true)
    {
        Walking();
    }
}

void Human::Walking()
{
    if(position.x <= 1024)
    {
        Walk();
    }
    else if(position.x >= 0)
    {
        WalkOpposite();
    }
}


void Human::Walk()       // walk will have a flip sign to make sure where it's walking
{
    clip += 0.03;
    if(clip >= 23)      // to change the clip after a certain amount the loop runs.
    {
        clip = 15;
    }
    speed += 0.6;
    if(speed >= 1)    // to adjust the x position after a certain amount the loop runs.
    {
        speed = 0;
        position.x += 1;
    }
}


void Human::WalkOpposite()
{
    clip += 0.03;
    if(clip >= 23)      // to change the clip after a certain amount the loop runs.
    {
        clip = 15;
    }
    speed += 0.6;
    if(speed >= 1)    // to adjust the x position after a certain amount the loop runs.
    {
        speed = 0;
        position.x -= 1;
    }
}

int Human::GetBedPosition()
{
    //house->GetClosestBed();
    return 0;
}

bool Human::EnterHouse()
{
    if(house->GetDoor()->GetX() == GetXPosition() && house ->GetDoor()->GetX() == GetYPosition()) // if it reaches the x position of the bed and is not infected
    {
        return true;
    }
    return false;
}

bool Human::LeaveHouse()
{
    if(house->GetDoor()->GetX() == GetXPosition() && house ->GetDoor()->GetX() == GetYPosition()) // if it reaches the x position of the bed and is not infected
    {
        return true;
    }
    return false;
}


bool Human::Sit()
{
    //Point bedposition = GetBedPosition();
    if(house->GetDoor()->GetX() == GetXPosition() && house ->GetDoor()->GetX() == GetYPosition()  && infected == false) // if it reaches the x position of the bed and is not infected
    {
        return true;
    }

}

void Human::SetOutdoorIndoor()
{

}

bool Human::GetIsOutdoor()
{
    return IsOutdoor;
}

bool Human::GetIsIndoor()
{
    return IsIndoor;
}

bool Human::LieDown()
{
    /* The human will only lie down indoor. Means we need to have the position of the bed.
       So that it goes to the bed and suddenly falls asleep.
    */
/*
    Point bedposition = GetBedPosition();

    if(bedposition.x == GetXPosition() && bedposition.y == GetYPosition() && infected == true)   // if it reaches at the x position of the bed and is infected
    {
        return true;                                    // if it's at bed position then it lies down
    }

}



int Human::GetXPosition()
{
    return position.x;
}

int Human::GetYPosition()
{
    return position.y;
}

void Human::HumanRender(SDL_Renderer* gRenderer)
{
    Texture::GetInstance() -> Render(clip,gRenderer,&position);
}

void Human::MosquitoBite()
{

}

void Human::BackToNormal()
{

}

*/

