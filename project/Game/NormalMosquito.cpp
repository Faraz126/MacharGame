#include "NormalMosquito.h"
#include <random>
#include <iostream>
#include "House.h"

NormalMosquito::NormalMosquito()
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
    None = new Disease();
    timer = 0;
    diseaseCode = BITEN;
}

NormalMosquito::NormalMosquito(Scenario* screen)
{
    this -> screen = screen;
}


void NormalMosquito::Update(int)
{
    timer += 1;
    Fly();
    DetectOrFollow();
}

void NormalMosquito::Fly()
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



void NormalMosquito::Bite(Human* human)
{
    if(IsFollowingHuman == true && abs(position.x - human->GetX()) <= 5 && abs(position.y - human -> GetY()) <= 5)
    {
        human -> SetInfected(diseaseCode);
        DetectHuman = false;
        IsFollowingHuman = false;
    }
}

void NormalMosquito::Follow(Human* human)
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

void NormalMosquito::Follow(Entrance* entrance)        // Going to entrance
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

void NormalMosquito::DetectOrFollow()
{
    /* The below condition is to detect either a human or entrance */

    if(DetectEntrance == false && DetectHuman == false)         // if detected neither
    {
        if(rand() % 2 == 0)         // detect an entrance if it's close enough
        {
            DetectAnEntrance();
        }
        else if(rand() % 2 == 1)   // detect a human and decide if it's close enough to follow
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
        Follow(humans[human]);
        Bite(humans[human]);
    }
}


void NormalMosquito::DetectAnEntrance()
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


void NormalMosquito::DetectAHuman()
{
    int n;
    humans = screen->GetHumans(n);
    for(int i = 0;i < humans.size();i++)
    {
        humans[i]->GetDistance(position.x,position.y);

        if(abs(position.x - humans[i] -> GetX() < 100) &&
           abs(position.y - humans[i] -> GetY() < 100) &&
          (IsFollowingEntrance == false &&
           humans[i]->GetInfected() == 0)
          )
        {
            IsFollowingHuman = true;
            DetectHuman = true;
            human = i;
            std::cout << "Break!" << std::endl;
            break;
        }
        else
        {
            IsFollowingHuman = false;
            DetectHuman = false;
        }
    }
}


void NormalMosquito::ReachedEntrance()
{
    if(entrance->GetX(indoor) == position.x && entrance->GetY(indoor) == position.y)
    {
        // will either go indoor or outdoor
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

void NormalMosquito::Show(SDL_Renderer* gRenderer)
{
    Texture::GetInstance() -> Render(int(clip),gRenderer,&position);
}
