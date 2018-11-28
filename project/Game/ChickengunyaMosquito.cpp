#include "ChickengunyaMosquito.h"
#include <random>
#include <iostream>
#include "Scenario.h"
#include "Human.h"

ChickengunyaMosquito::ChickengunyaMosquito()
{

}

ChickengunyaMosquito::ChickengunyaMosquito(Scenario* screen)
{
    clip = 43;
    this -> screen = screen;
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
    frames = 0;

}


void ChickengunyaMosquito::Update()
{
    frames += 1;
    fly();
    Detect();
}

void ChickengunyaMosquito::fly()
{
    if(IsFollowingHuman == false && IsFollowingEntrance == false)
    {
        std::cout << "FLYING!" << std::endl;
        clip += 0.1;
        if(clip >= 52)      // to change the clip after a certain amount the loop runs.
        {
            clip = 43;
        }
        speed_x += rand() % 5;
        speed_y += rand() % 5;
        if(rand() % 4 == 0 && speed_x  >= 5)    // to move the mosquito right
        {
            int random = rand() % 5;
            position.x += random;
            speed_x = 0;
       //     std::cout << "X Position: " << position.x << std::endl;
        }
        else if(rand() % 4 == 1 && speed_x  >= 5) // to move the mosquito left
        {
            int random = rand() % 5;
            position.x -= random;
            speed_x = 0;
       //     std::cout << "X Position: " << position.x << std::endl;
        }
        else if(rand() % 4 == 2 && speed_y  >= 5) // to move the mosquito up
        {
            int random = rand() % 5;
            position.y -= random;
            //position.w -= random;
            //position.h -= random;
            speed_y = 0;
       //     std::cout << "Y Position: " << position.y << std::endl;
        }
        else if(rand() % 4 == 3 && speed_y  >= 5) // to move the mosquito down
        {
            int random = rand() % 5;
            position.y += random;
            //position.w += random;
            //position.h += random;
            speed_y = 0;
       //     std::cout << "Y Position: " << position.y << std::endl;
        }
    }
}



void ChickengunyaMosquito::bite(Human* human)
{
    if(IsFollowingHuman == true && position.x == human->GetX() && position.y == human -> GetY())
    {
        human -> SetInfected(Chickengunya);
        IsFollowingHuman = false;
    }

}

void ChickengunyaMosquito::follow(Human* human)
{
    if(IsFollowingHuman == true)
    {
        clip += 0.1;
        if(clip >= 52)      // to change the clip after a certain amount the loop runs.
        {
            clip = 43;
        }
        speed_x += rand() % 5;
        speed_y += rand() % 5;
        if(human->GetX() > position.x && rand() % 4 == 0 && speed_x  >= 15)    // to move the mosquito right
        {
            int random = rand() % 10;
            position.x += random;
            speed_x = 0;
    //        std::cout << "X Position: " << position.x << std::endl;
        }
        else if(human->GetX() < position.x && rand() % 4 == 1 && speed_x  >= 15) // to move the mosquito left
        {
            int random = rand() % 10;
            position.x -= random;
            speed_x = 0;
    //        std::cout << "X Position: " << position.x << std::endl;
        }
        else if(human->GetY() > position.y && rand() % 4 == 2 && speed_y  >= 15) // to move the mosquito up
        {
            int random = rand() % 10;
            position.y += random;
            //position.w -= random;
            //position.h -= random;
            speed_y = 0;
    //        std::cout << "Y Position: " << position.y << std::endl;
        }
        else if(human->GetY() < position.y && rand() % 4 == 3 && speed_y  >= 15) // to move the mosquito down
        {
            int random = rand() % 10;
            position.y -= random;
        //    position.w += random;
         //   position.h += random;
            speed_y = 0;
     //       std::cout << "Y Position: " << position.y << std::endl;
        }
    }
}

void ChickengunyaMosquito::follow(Entrance* entrance)        // Going to entrance
{
    if(IsFollowingEntrance == true)
    {
        std::cout << "FOLLOWING ENTRANCE!" << std::endl;
        clip += 0.1;
        if(clip >= 52)      // to change the clip after a certain amount the loop runs.
        {
            clip = 43;
        }
        speed_x += rand() % 5;
        speed_y += rand() % 5;
        if(entrance -> GetX() > position.x && rand() % 4 == 0 && speed_x  >= 10)    // to move the mosquito right
        {
            int random = rand() % 10;
            position.x += random;
            speed_x = 0;
    //        std::cout << "X Position: " << position.x << std::endl;
        }
        else if(entrance -> GetX() < position.x && rand() % 4 == 1 && speed_x  >= 10) // to move the mosquito left
        {
            int random = rand() % 10;
            position.x -= random;
            speed_x = 0;
    //        std::cout << "X Position: " << position.x << std::endl;
        }
        else if(entrance -> GetY() > position.y && rand() % 4 == 2 && speed_y  >= 10) // to move the mosquito up
        {
            int random = rand() % 10;
            position.y += random;
            //position.w -= random;
            //position.h -= random;
            speed_y = 0;
    //        std::cout << "Y Position: " << position.y << std::endl;
        }
        else if(entrance -> GetY() < position.y && rand() % 4 == 3 && speed_y  >= 10) // to move the mosquito down
        {
            int random = rand() % 10;
            position.y -= random;
        //    position.w += random;
         //   position.h += random;
            speed_y = 0;
     //       std::cout << "Y Position: " << position.y << std::endl;
        }
    }
}


void ChickengunyaMosquito::Detect()
{

    if(DetectEntrance == false && DetectHuman == false)
    {
        std::cout << "Detecting!" << std::endl;
        /* The below conditions are detection of entrance */

        entrance = GetClosestEntrance();

        if(
           (abs(position.x - entrance -> GetX())) < 200 &&
           (abs(entrance -> GetY() - position.y)) < 200 &&
           IsFollowingHuman == false
           )
        {
            std::cout << "Entrance Detected!" << std::endl;
            IsFollowingEntrance = true;
            DetectEntrance = true;
        }
        else
        {
            entrance = NULL;
            IsFollowingEntrance = false;
            DetectEntrance = false;
        }

        /* The below conditions are for detection of human */

        int n;
        humans = screen->GetHumans(n);
        for(int i = 0;i < n;i++)
        {
            humans[i]->GetDistance(position.x,position.y);

            if(abs(position.x - humans[i] -> GetX() < 100) &&
               abs(position.y - humans[i] -> GetY() < 100) &&
               (IsFollowingEntrance == false &&
               humans[i]->GetInfected() == nullptr)
               )
            {
                std::cout << humans[i]->GetInfected() << std::endl;
                std::cout << "Human Following!" << std::endl;
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
    else
    {
        if(IsFollowingHuman == true)
        {
            follow(humans[human]);
            bite(humans[human]);
        }
        if(IsFollowingEntrance == true && entrance -> IsOpen() == true)
        {
            follow(entrance);
            ReachedEntrance();
        }
        else
        {
            entrance = NULL;
            IsFollowingEntrance = false;
            DetectEntrance = false;
        }
    }
}




void ChickengunyaMosquito::ReachedEntrance()
{
    if(entrance->GetX() == position.x && entrance->GetY() == position.y)
    {
        // will either go indoor or outdoor
    }
}

void ChickengunyaMosquito::Show(SDL_Renderer* gRenderer)
{
    Texture::GetInstance() -> Render(int(clip),gRenderer,&position);
}
