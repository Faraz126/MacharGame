#include "AedesMosquito.h"
#include <random>
#include <iostream>
#include "Scenario.h"

AedesMosquito::AedesMosquito()
{
    clip = 43;
    /* x and y position will change as they'll be of the breeding grounds */
    position.x = 0;
    position.y = 500;
    position.h = 10;
    position.w = 20;
    DetectHuman = false;
    DetectEntrance = false;
    IsFollowingHuman = false;
    IsFollowingEntrance = false;
    speed_x = 0;
    speed_y = 0;
    Dengue = new Disease();
    Chikengunya = new Disease();
    timer = 0;
    diseaseCode = DENGUE;


}

AedesMosquito::AedesMosquito(Scenario* screen): AedesMosquito()
{
    this -> screen = screen;
    /* x and y position will change as they'll be of the breeding grounds */
}


void AedesMosquito::Update(int)
{
    if(timer <= 10000)
    {
        timer += 1;
        Fly();
        DetectOrFollow();
    }
    else
    {
        clip = 43;
    }
}

void AedesMosquito::Fly()
{
    if(IsFollowingHuman == false && IsFollowingEntrance == false)
    {
        clip += 0.1;
        if(clip >= 52)      // to change the clip after a certain amount the loop runs.
        {
            clip = 43;
        }
        speed_x += rand() % 5;
        speed_y += rand() % 5;
        if(rand() % 4 == 0 && speed_x  >= 10)    // to move the mosquito right
        {
            int random = rand() % 10;
            position.x += random;
            speed_x = 0;
        }
        else if(rand() % 4 == 1 && speed_x  >= 10) // to move the mosquito left
        {
            int random = rand() % 10;
            position.x -= random;
            speed_x = 0;
        }
        else if(rand() % 4 == 2 && speed_y  >= 10) // to move the mosquito up
        {
            int random = rand() % 10;
            position.y -= random;
            speed_y = 0;
        }
        else if(rand() % 4 == 3 && speed_y  >= 10) // to move the mosquito down
        {
            int random = rand() % 10;
            position.y += random;
            speed_y = 0;
        }
    }
}



void AedesMosquito::Bite(Human* human)
{
    if(IsFollowingHuman == true && abs(position.x - human->GetX()) <= 5 && abs(position.y - human -> GetY()) <= 5)
    {
        if(rand() % 2 == 0)         // if this is true then infect with Dengue
        {
            human -> SetInfected(diseaseCode);
            DetectHuman = false;
            IsFollowingHuman = false;
            timer -= 2500;
        }
        else if(rand() % 2 == 1)    // if this is true then infect with Chikengunya
        {
            human -> SetInfected(diseaseCode);
            DetectHuman = false;
            IsFollowingHuman = false;
            timer -= 2500;
        }
    }
}

void AedesMosquito::Follow(Human* human)
{
    clip += 0.1;
    if(clip >= 52)      // to change the clip after a certain amount the loop runs.
    {
        clip = 43;
    }
    speed_x += rand() % 5;
    speed_y += rand() % 5;
    if(human->GetX() + 20 > position.x && rand() % 4 == 0 && speed_x  >= 10)    // to move the mosquito right
    {
        int random = rand() % 10;
        position.x += random;
        speed_x = 0;
    }
    else if(human->GetX() - 20 < position.x && rand() % 4 == 1 && speed_x  >= 10) // to move the mosquito left
    {
        int random = rand() % 10;
        position.x -= random;
        speed_x = 0;
    }
    else if(human->GetY() + 20 > position.y && rand() % 4 == 2 && speed_y  >= 10) // to move the mosquito up
    {
        int random = rand() % 10;
        position.y += random;
        speed_y = 0;
    }
    else if(human->GetY() - 20 < position.y && rand() % 4 == 3 && speed_y  >= 10) // to move the mosquito down
    {
        int random = rand() % 10;
        position.y -= random;
        speed_y = 0;
    }
}


void AedesMosquito::Follow(Entrance* entrance)        // Going to entrance
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
        int random = rand() % 10;
        position.x += random;
        speed_x = 0;
    }
    else if(entrance -> GetX(indoor) < position.x && rand() % 4 == 1 && speed_x  >= 10) // to move the mosquito left
    {
        int random = rand() % 10;
        position.x -= random;
        speed_x = 0;
    }
    else if(entrance -> GetY(indoor) > position.y && rand() % 4 == 2 && speed_y  >= 10) // to move the mosquito up
    {
        int random = rand() % 10;
        position.y += random;
        speed_y = 0;
    }
    else if(entrance -> GetY(indoor) < position.y && rand() % 4 == 3 && speed_y  >= 10) // to move the mosquito down
    {
        int random = rand() % 10;
        position.y -= random;
        speed_y = 0;
    }
}


void AedesMosquito::DetectOrFollow()
{
    /* The below condition is to detect either a human or entrance */

    if(DetectEntrance == false && DetectHuman == false)         // if detected neither
    {
        if(rand() % 2 == 0)         // detect an entrance if it's close enough
        {
            DetectAnEntrance();
        }
        else  // detect a human and decide if it's close enough to follow
        {
            DetectAHuman();
        }
    }

    /* The below condition is to follow either human or entrance */

    if(IsFollowingEntrance == true && entrance -> IsOpen() == true)
    {
        Follow(entrance);
        ReachedEntrance();
    }
    else if(IsFollowingHuman == true)
    {
        if (humans.GiveItem(human) != 0)
        {
            Follow(humans.GiveItem(human));
            Bite(humans.GiveItem(human));
        }
        else
        {
            IsFollowingHuman = false;
        }
    }
}


void AedesMosquito::DetectAnEntrance()
{
    entrance = GetClosestEntrance();
    if( entrance != 0 &&
        (abs(position.x - entrance -> GetX(indoor))) < 200 &&
        (abs(entrance -> GetY(indoor) - position.y)) < 200 &&
        IsFollowingHuman == false
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


void AedesMosquito::DetectAHuman()
{
    int n;
    humans = screen->GetHumans(n);
    for(int i = 0;i < humans.GetLength();i++)
    {
        humans.GiveItem(i)->GetDistance(position.x,position.y);

        if(abs(position.x - humans.GiveItem(i) -> GetX() < 100) &&
           abs(position.y - humans.GiveItem(i) -> GetY() < 100) &&
          (IsFollowingEntrance == false &&
           humans.GiveItem(i)->GetInfected() == 0)
          )
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


void AedesMosquito::ReachedEntrance()
{
    if(entrance->GetX(indoor) == position.x && entrance->GetY(indoor) == position.y)
    {

        DetectEntrance = false;
        IsFollowingEntrance = false;

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

void AedesMosquito::Show(SDL_Renderer* gRenderer)
{
    Texture::GetInstance() -> Render(int(clip),gRenderer,&position);
}
