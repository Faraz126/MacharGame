#include "Human.h"
#include "House.h"
#include "Bed.h"
#include <random>

Human::Human(): Clickable(0,0,0,0)
{

}

Human::Human(House* PersonHouse) : Clickable(rand()%1024, 450, 100, 150)
{
    infected = false;
    clip = 15;
    house = PersonHouse;
    IsIndoor = true;
    IsOutdoor = false;
    IsWalkingHorizontal = true;
    IsWalkingVertical = false;
    IsSitting = false;
    IsLyingDown = false;
    Right = true;
    Left = false;
    Up = false;
    Down = false;
    // there needs to be some functionality for when the human is clicked on. Then it should imo have a determined path to hospital
}

Human::~Human()
{

}


void Human::Update()
{
    if(IsIndoor == true && IsOutdoor == false)
    {
        LieDown();          // if this is true then walk up and lie down
        SitOnBed();              // if this is true then walk up and lie down
        Walking();
        WalkAgain();
    }
    if(IsOutdoor == true && IsIndoor == false)
    {
        Walking();
    }
}



void Human::Walking()
{
    if(pos.x <= 1024 && Right == true && IsWalkingHorizontal == true)
    {
        Walk();
        if(pos.x == 1024)
        {
            Left = true;                            // to make sure it goes left and not write since it'll check both the conditions
            Right = false;
        }
    }
    else if(pos.x >= 0 && Left == true && IsWalkingHorizontal == true)
    {
        WalkOpposite();
        if(pos.x == 0)
        {
            Right = true;
            Left = false;
        }
    }
}

void Human::WalkUp()
{
    if(Up == true && IsWalkingVertical == true)
    {
        clip += 0.03;
        if(clip >= 23)      // to change the clip after a certain amount the loop runs.
        {
            clip = 15;
        }
        speed += 0.6;
        if(speed >= 1)    // to adjust the x pos after a certain amount the loop runs.
        {
            speed = 0;
            pos.y -= 1;
        }
    }
}

void Human::WalkDown()
{
    if(Down == true && IsWalkingVertical == true)
    {
        clip += 0.03;
        if(clip >= 23)      // to change the clip after a certain amount the loop runs.
        {
            clip = 15;
        }
        speed += 0.6;
        if(speed >= 1)    // to adjust the x pos after a certain amount the loop runs.
        {
            speed = 0;
            pos.y += 1;
        }
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
    if(speed >= 1)    // to adjust the x pos after a certain amount the loop runs.
    {
        speed = 0;
        pos.x += 1;
    }
}


void Human::WalkOpposite()
{
    clip -= 0.03;
    if(clip <= 15)      // to change the clip after a certain amount the loop runs.
    {
        clip = 23;
    }
    speed += 0.6;
    if(speed >= 1)    // to adjust the x pos after a certain amount the loop runs.
    {
        speed = 0;
        pos.x -= 1;
    }
}

void Human::WalkAgain()
{
    if(IsSitting == true && rand() % 500 == 0) // if it reaches the x pos of the bed and is not infected
    {
        IsWalkingHorizontal = false;
        IsWalkingVertical = true;
        IsLyingDown = false;
        Down = true;
        Up = false;
        if(450 == GetYPosition())
        {
            IsSitting = false;
            IsWalkingVertical = false;
            IsWalkingHorizontal = true;
            Down = false;
            clip = 15;          // this will be the clip where it starts to walk again
        }
        WalkDown();
    }
}

void Human::SitOnBed()               // this sit will be for sitting on bed in house
{
    if(GetBedXPosition() == GetXPosition() && infected == false && rand() % 5 == 0) // if it reaches the x pos of the bed and is not infected
    {
        IsSitting = true;
        IsWalkingHorizontal = false;
        IsWalkingVertical = true;
        IsLyingDown = false;
        Down = false;
        Up = true;
        if(GetBedYPosition() == GetYPosition())
        {
            IsWalkingVertical = false;
            Up = false;
            otherclip = 17;          // this will be the clip where it sits
        }
        WalkUp();



    }
}

int Human::GetBedXPosition()
{
    Bed* pos = house -> GetClosestBed(GetXPosition());
    return pos -> GetX();
}

int Human::GetBedYPosition()
{
    Bed* pos = house -> GetClosestBed(GetYPosition());
    return pos -> GetY();
}


void Human::SetOutdoorIndoor()
{

}


void Human::LieDown()
{
    if(GetBedXPosition() == GetXPosition() && infected == true)   // if it reaches at the x pos of the bed and is infected
    {
        IsWalkingHorizontal = false;
        IsWalkingVertical = true;
        IsSitting = true;
        IsLyingDown = false;
        Up = true;
        Down = false;
        otherclip = 20;          // this will be the clip where it lies down
    }
}

int Human::GetXPosition()

{
    return pos.x;
}

int Human::GetYPosition()
{
    return pos.y;
}

void Human::Show(SDL_Renderer* gRenderer)
{
    if(IsWalkingHorizontal == true || IsWalkingVertical == true)
    {
        Texture::GetInstance() -> Render(int(clip),gRenderer,&pos);
    }
    else if(IsWalkingHorizontal == false || IsWalkingVertical == false)
    {
        Texture::GetInstance() -> Render(otherclip,gRenderer,&pos);
    }
}
//now work on this. Yeah Okay


void Human::EnterHouse()
{
    //
}

void Human::LeaveHouse()
{
/*    if(house->entrance == GetXPosition())
    {
        Up = true;
        IsWalkingVertical = true;
        IsWalkingHorizontal = false;
        Down = false;
        Right = false;
        Left = false;
        WalkUp();
    }
*/
}

void Human::MosquitoBite()
{

}

void Human::BackToNormal()
{

}

