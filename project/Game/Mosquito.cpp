#include "Scenario.h"
#include "Mosquito.h"



Mosquito::Mosquito()
{
    clip = 43;
    position.h = 10;
    position.w = 20;
    DetectHuman = false;
    DetectEntrance = false;
    IsFollowingHuman = false;
    IsFollowingEntrance = false;
    speed_x = 0;
    speed_y = 0;
    health = 15000;
    IsDead = false;
    DetectTimer = 0;
    indoor = true;
    ReachingTimer = 0;
    screen = NULL;
    entrance = NULL;
}

Mosquito::Mosquito(Scenario* screen): Mosquito()
{
    this -> screen = screen;
}

void Mosquito::SetIsDead(bool dead)
{
    IsDead = dead;
}

void Mosquito::SetIndoor(bool status)
{
    indoor = status;
}

void Mosquito::Follow()
{
    // The below condition is to follow either human or entrance

    if(IsFollowingEntrance == true && entrance -> IsOpen() == true)
    {
        IsFollow(entrance);
        ReachedEntrance();
    }
    else if(IsFollowingHuman == true)
    {
        IsFollow();
        Bite();
    }
}


void Mosquito::Update(int frame)
{
    health -= 1;

    if(health >= 0)
    {
         // to check if it needs to follow first


        if(IsFollowingEntrance == true || IsFollowingHuman == true)     // to follow if mosquito has detected either human or entrance
        {
            Follow();
        }
        if(DetectHuman == false && DetectEntrance == false && DetectTimer > 150)        //detect after every 150 frames
        {
            Detect();
        }
        else                                                                        // to fly randomly
        {
            Fly();
        }
    }
    else
    {
        clip = 43;
        IsDead = true;
    }
}


void Mosquito::Fly()
{
    ReachingTimer += 1;
    DetectTimer += 1;

    clip += 0.1;
    if(clip >= 52)      // to change the clip after a certain amount the loop runs.
    {
        clip = 43;
    }
    speed_x += rand() % 5;
    speed_y += rand() % 5;
    if(rand() % 4 == 0 && speed_x  >= MaxSpeedY)    // to move the mosquito right
    {
        int random = rand() % 13;
        position.x += random;
        speed_x = 0;
    }
    else if(rand() % 4 == 1 && speed_x  >= MaxSpeedX) // to move the mosquito left
    {
        int random = rand() % 13;
        position.x -= random;
        speed_x = 0;
    }
    else if(rand() % 4 == 2 && speed_y  >= MaxSpeedY) // to move the mosquito up
    {
        int random = rand() % 13;
        position.y -= random;
        speed_y = 0;
    }
    else if(rand() % 4 == 3 && speed_y  >= MaxSpeedY) // to move the mosquito down
    {
        int random = rand() % 13;
        position.y += random;
        speed_y = 0;
    }
}

void Mosquito::IsFollow()
{
    ReachingTimer += 1;                 // to make sure the mosquito can detect the entrance again

    clip += 0.1;
    if(clip >= 52)      // to change the clip after a certain amount the loop runs.
    {
        clip = 43;
    }
    speed_x += rand() % 5;
    speed_y += rand() % 5;

    if(humans.GiveItem(human) -> GetX()+ 20 > position.x && rand() % 4 == 0 && speed_x  >= MaxSpeedX)    // to move the mosquito right
    {
        int random = rand() % 13;
        position.x += random;
        speed_x = 0;
    }
    else if(humans.GiveItem(human) -> GetX() - 20 < position.x && rand() % 4 == 1 && speed_x  >= MaxSpeedX) // to move the mosquito left
    {
        int random = rand() % 13;
        position.x -= random;
        speed_x = 0;
    }
    else if(humans.GiveItem(human) -> GetY() + 20 > position.y && rand() % 4 == 2 && speed_y  >= MaxSpeedY) // to move the mosquito up
    {
        int random = rand() % 13;
        position.y += random;
        speed_y = 0;
    }
    else if(humans.GiveItem(human) -> GetY() - 20 < position.y && rand() % 4 == 3 && speed_y  >= MaxSpeedY) // to move the mosquito down
    {
        int random = rand() % 13;
        position.y -= random;
        speed_y = 0;
    }
}

void Mosquito::Heal()
{
    health += 1000;
    if(health > 15000)               // every mosquito maximum health is 1500
    {
        health = 15000;
    }
}

void Mosquito::IsFollow(Entrance* entrance)        // Going to entrance
{
    clip += 0.1;
    if(clip >= 52)      // to change the clip after a certain amount the loop runs.
    {
        clip = 43;
    }
    speed_x += rand() % 5;
    speed_y += rand() % 5;
    if(entrance -> GetX(indoor) > position.x && rand() % 4 == 0 && speed_x  >= 10)    // to move the mosquito right
    {
        int random = rand() % 13;
        position.x += random;
        speed_x = 0;
    }
    else if(entrance -> GetX(indoor) < position.x && rand() % 4 == 1 && speed_x  >= 10) // to move the mosquito left
    {
        int random = rand() % 13;
        position.x -= random;
        speed_x = 0;
    }
    else if(entrance -> GetY(indoor) > position.y && rand() % 4 == 2 && speed_y  >= 10) // to move the mosquito up
    {
        int random = rand() % 13;
        position.y += random;
        speed_y = 0;
    }
    else if(entrance -> GetY(indoor) < position.y && rand() % 4 == 3 && speed_y  >= 10) // to move the mosquito down
    {
        int random = rand() % 13;
        position.y -= random;
        speed_y = 0;
    }
}

void Mosquito::Detect()
{
    /* The below condition is to detect either a human or entrance */
    DetectTimer = 0;

    if(DetectEntrance == false && DetectHuman == false)         // if detected neither
    {
        if(rand() % 5 == 0 && ReachingTimer > 500)          // detect an entrance if it's close enough
        {
            DetectAnEntrance();
        }
        else if(rand() % 5 == 1)   // detect a human and decide if it's close enough to follow
        {
            DetectAHuman();
        }
    }
}

void Mosquito::DetectAnEntrance()
{
    entrance = GetClosestEntrance();
    if( entrance != 0 &&
        (abs(position.x - entrance -> GetX(indoor))) < Vision &&
        (abs(entrance -> GetY(indoor) - position.y)) < Vision &&        // if mosquito is not close enough then don't detect
        ReachingTimer > 500                                             // this timer exists to make sure the mosquito doesn't enter the entrance again
        )
    {
        IsFollowingEntrance = true;
        DetectEntrance = true;
    }
    else
    {
        entrance = NULL;
        IsFollowingEntrance = false;
        DetectEntrance = false;
    }
}


void Mosquito::DetectAHuman()
{
    int n;
    humans = screen->GetHumans(n);
    for(int i = 0;i < n;i++)
    {
        humans.GiveItem(i)->GetDistance(position.x,position.y);

        if(abs(position.x - humans.GiveItem(i) -> GetX() < Vision) &&
           abs(position.y - humans.GiveItem(i) -> GetY() < Vision) &&
           IsFollowingEntrance == false &&
           humans.GiveItem(i)->GetInfected() == 0 &&
           humans.GiveItem(i)->GetCoveredInRepellant() == 0)
        {
            IsFollowingHuman = true;
            DetectHuman = true;
            human = i;
            break;
        }
        else
        {
            IsFollowingHuman = false;
            DetectHuman = false;
        }
    }
}


void Mosquito::ReachedEntrance()
{
    if(entrance->GetX(indoor) == position.x && entrance->GetY(indoor) == position.y)
    {
        DetectEntrance = false;
        IsFollowingEntrance = false;
        ReachingTimer = 0;

        if (indoor)
        {
            screen->LeaveMosquito(this);
            SetScenario(entrance->GetOutdoor());
            indoor = false;
            screen->AddMosquito(this);
            entrance->GetOutdoorPos(position.x, position.y);

        }
        else
        {
            screen->LeaveMosquito(this);
            SetScenario(entrance->GetScenario());
            indoor = true;
            screen->AddMosquito(this);
            position.x = entrance->GetX(indoor);
            position.y = entrance->GetY(indoor);
        }
    }
}

void Mosquito::Show(SDL_Renderer* gRenderer)
{
    Texture::GetInstance() -> Render(int(clip),gRenderer,&position);
}

bool Mosquito::GetIsDead()
{
    return IsDead;
}

void Mosquito::UpdatePositiion(int x,int y)
{
    position.x = x;
    position.y = y;
}

void Mosquito::SetScenario(Scenario* cScenario)
{
    screen = cScenario;
    indoor = screen->GetCode();
}

Entrance* Mosquito::GetClosestEntrance()
{
    int x = position.x;
    int y = position.y;
    double dist = 8000000;
    int noOfEntrance;
    Entrance** entrance = screen->GetEntrance(noOfEntrance);
    Entrance* temp = 0;
    for (int i = 0; i < noOfEntrance; i++)
    {
        if (indoor)
        {
            if (entrance[i]->GetDistance(x,y) < dist && entrance[i]->IsOpen())
            {
                dist = entrance[i]->GetDistance(x,y);
                temp = entrance[i];
            }
        }
        else
        {
            if (entrance[i]->GetDistanceOutside(x,y) < dist && entrance[i]->IsOpen())
            {
                dist = entrance[i]->GetDistanceOutside(x,y);
                temp = entrance[i];
            }

        }

    }
    return temp;
}

void Mosquito::SetX(int delta, int direction)
{

    if ( direction == 0)
    {
        position.x+=delta;

    }
    if ( direction == 1)
    {
        position.x-=delta;
    }
}


