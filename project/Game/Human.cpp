#include "Human.h"
#include <random>
#include <cmath>
#include "House.h"

Human::Human(): Clickable(0,0,117, 575)
{
    ownHouse = 0;
}


Human::Human(int x, int y, House* house): Clickable(x,y,117, 575)
{
    ownHouse = house;
    ReduceSize(0.3);
    collideRect.x = pos.x + 10;
    collideRect.y = pos.y + pos.h - 10;
    collideRect.w = pos.w-10;
    collideRect.h = 10;
    isIndoor = true;
    faceDirection = RIGHT;
    isGoingToBed = true;
    isGoingOut = false;
    isVertical = false;
    isHorizontal = true;
    isWalking = false;
    activity = WALKING;
    step = 1;
}

Human::Human(House* house): Human(0,0, house)
{

}


bool Human::Collide()
{

    if (isIndoor)
    {
        int n;
        Bed* bed = ownHouse->GetBeds(n);
        for (int i = 0; i <n; i++)
        {
            if (bed[i].Collides(collideRect))
            {
                return true;
            }
        }
        BreedingGround** breedingGrounds = ownHouse->GetBreedingGrounds(n);
        for (int i = 0; i < n; i++)
        {
            if (breedingGrounds[i]->Collides(collideRect))
            {
                return true;
            }
        }
        Human** humans = ownHouse->GetHumans(n);
        for (int i = 0; i < n; i++)
        {
            if (humans[i]->Collides(collideRect) && humans[i] != this)
            {
                return true;
            }
        }
    }
    return false;
}

void Human::Update(int frame)
{
    switch (activity)
    {
    case GOING_TO_DOOR:
        break;
    case WALKING:
        {
            if (collideRect.x >= 1024)
            {
                faceDirection = LEFT;
            }
            else if (collideRect.x <= 0)
            {
                faceDirection = RIGHT;
            }
            break;
        }

    }


    /*
    if (frame % 500000 == 0 && !isGoingOut && !isGoingToBed)
    {
        int n = rand()% 150;
        if (n < 30)
        {
            isGoingToBed = true;
            bedToGoTo = ownHouse->GetClosestBed(pos.x, pos.y);
            toFollowX = bedToGoTo->GetX();
            toFollowY = bedToGoTo->GetY();

            isGoingOut = false;
            isWalking = false;
        }
        else if(n < 60)
        {
            isGoingToBed = false;
            isGoingOut = true;
            isWalking = false;
        }
        else
        {
            isGoingToBed = false;
            isGoingOut = false;
            isWalking = true;
        }
    }
    /*
    if (isGoingToBed)
    {
        int curDist = (sqrt(pow((toFollowX-collideRect.x),2))+(pow((toFollowY-collideRect.y),2)));
        if  (curDist < 10)
        {
            moving  = 5;
            isGoingToBed = false;
            isWalking = true;
        }
        int random = rand()%2;
        if (random == 0 && toFollowX- collideRect.x < 0)
        {
            moving = RIGHT;
        }
        else if (random == 0 && toFollowX- collideRect.x > 0)
        {
            moving = LEFT;
        }
        else if (random == 1 && toFollowY - collideRect.x > 0)
        {
            moving = UP;
        }

    }

    if (isWalking)
    {
        int random = rand()% 4;
        if (faceDirection == RIGHT)
        {
            if (random != LEFT)
            {
                faceDirection = random;
                Move();
            }
        }
        else if (faceDirection == LEFT)
        {
            if (random != RIGHT)
            {
                faceDirection = random;
                Move();
            }
        }
        else if (faceDirection == UP)
        {
            if (random != DOWN)
            {
                faceDirection = random;
                Move();
            }
        }
        else if (faceDirection == DOWN)
        {
            if (random != UP)
            {
                faceDirection = random;

            }
        }
    }
    if (isGoingToBed)
    {
        toFollowX = ownHouse->GetDoor()->GetX();
        toFollowY = ownHouse->GetDoor()->GetY();

        if (isHorizontal)
        {
            if (collideRect.x == toFollowX)
            {
                isHorizontal = false;
                isVertical = true;
            }
            else if (collideRect.x > toFollowX)
            {
                faceDirection = LEFT;
            }
            else if (collideRect.x < toFollowX)
            {
                faceDirection = RIGHT;
            }
        }
        else if (isVertical)
        {
            if (collideRect.y == toFollowY)
            {
                isHorizontal = false;
                isVertical = true;
            }
            else if (collideRect.y > toFollowY)
            {
                faceDirection = UP;
            }
        }
        else if (toFollowX == collideRect.x && toFollowY == collideRect.y)
        {
            faceDirection = 5;
        }
    }
    */
    Move();
}


void Human::Move()
{
    if (faceDirection == RIGHT)
    {
        pos.x += step;
        collideRect.x += step;
        /*
        if (Collide())
        {
            pos.x -= step;
            collideRect.x -= step;
        }
        */
    }
    else if (faceDirection == LEFT)
    {
        pos.x -= step;
        collideRect.x -= step;
        /*
        if (Collide())
        {
            pos.x += step;
            collideRect.x += step;
        }
        */
    }
    else if (faceDirection == DOWN)
    {
        pos.y += step;
        collideRect.y += step;
        /*
        if (Collide())
        {
            pos.y -= step;
            collideRect.y -= step;
        }
        */
    }
    else if (faceDirection == UP)
    {
        pos.y -= step;
        collideRect.y -= step;
        /*
        if (Collide())
        {
            pos.y += step;
            collideRect.y += step;
        }
        */
    }

}

void Human::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(74,renderer, &pos);
    SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    SDL_RenderDrawRect(renderer, &collideRect);
}
