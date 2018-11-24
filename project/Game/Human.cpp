#include "Human.h"
#include <random>
#include <cmath>
#include "House.h"

Human::Human(): Clickable(0,0,197, 575)
{
    ownHouse = 0;
}


Human::Human(int x, int y, House* house): Clickable(x,y,197, 570)
{
    spriteNum = 74;
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
    timeSince = 0;
    step = 1;
    slowDownFactor = 1;
    isInfected = false;
    door = ownHouse->GetDoor();


}

void Human::HandleEvents(SDL_Event* e)
{
    return;
}

Human::Human(House* house): Human(0,0, house)
{

}


bool Human::Collide(SDL_Rect& tempRect)
{

    if (isIndoor)
    {
        int n;
        Bed* bed = ownHouse->GetBeds(n);
        for (int i = 0; i <n; i++)
        {
            if (bed[i].Collides(tempRect))
            {
                return true;
            }
        }
        BreedingGround** breedingGrounds = ownHouse->GetBreedingGrounds(n);
        for (int i = 0; i < n; i++)
        {
            if (breedingGrounds[i]->Collides(tempRect))
            {
                return true;
            }
        }
        Human** humans = ownHouse->GetHumans(n);
        for (int i = 0; i < n; i++)
        {
            if (humans[i]->Collides(tempRect, humans[i]->collideRect) && humans[i] != this)
            {
                return true;
            }
        }
    }
    return false;
}

void Human::Update(int frame)
{
    if (frame % slowDownFactor == 0)
    {
        switch (activity)
        {
            case SITTING:
            {
                timeSince++;
                if (timeSince > 2000)
                {
                    //bedToGoTo->SetOccupied(false);
                    ChangeState();
                }
                break;
            }

            case GOING_TO_BED:
            {
                if (!bedToGoTo->GetOccupied())
                {
                    if (toFollowX > collideRect.x && isHorizontal)
                    {
                        faceDirection = RIGHT;
                    }
                    else if(toFollowX < collideRect.x && isHorizontal)
                    {
                        faceDirection = LEFT;
                    }
                    else
                    {
                        isHorizontal = !isHorizontal;
                        faceDirection = UP;
                    }
                    if (toFollowY < collideRect.y && !isHorizontal)
                    {
                        faceDirection = UP;

                    }
                    if (bedToGoTo->Collides(pos))
                    {
                        isHorizontal = true;
                        spriteNum = 75;
                        bedToGoTo->SetOccupied(true);
                        if (!isInfected)
                        {
                            ChangeState(SITTING);
                        }
                    }
                    Move();
                }
                else
                {
                    ChangeBedToFollow();
                }
                break;
            }
            case GOING_TO_DOOR:
            {
                    if (toFollowX > collideRect.x && isHorizontal)
                    {
                        faceDirection = RIGHT;
                    }
                    else if(toFollowX < collideRect.x && isHorizontal)
                    {
                        faceDirection = LEFT;
                    }
                    else
                    {
                        isHorizontal = false;
                        faceDirection = UP;
                    }
                    if (toFollowY < collideRect.y && !isHorizontal)
                    {
                        faceDirection = UP;

                    }
                    else if (door->Collides(pos))
                    {
                        spriteNum = 76;
                        ChangeState(SITTING);
                        isHorizontal = true;
                    }
                Move();
                break;
            }


            case WALKING:
            {
                if (timeSince*step > (ownHouse->GetWidth())*2)
                {
                    ChangeState();
                }
                if (collideRect.x >= ownHouse->GetWidth())
                {
                    faceDirection = LEFT;
                }
                else if (collideRect.x <= 0)
                {
                    faceDirection = RIGHT;
                }
                Move();
                timeSince++;
                break;
            }
            case AVOIDING_COLLISION:
            {
                Move();
                timeSince++;
                if (timeSince>10)
                {
                    ChangeState();
                }
                break;
            }
        }
    }

}


void Human::ChangeDirection()
{
    switch (faceDirection)
    {
        case (UP):
        {
            if( rand()%2 == 0)
            {
                faceDirection = RIGHT;
            }
            else
            {
                faceDirection = LEFT;
            }
            break;
        }
        case (RIGHT):
        {
            if (rand()%2 == 0)
            {
                faceDirection = DOWN;
            }
            else
            {
                faceDirection = UP;
            }
            break;
        }
        case (DOWN):
        {
            if (rand()%2 == 0)
            {
                faceDirection = DOWN;
            }
            else
            {
                faceDirection = RIGHT;
            }
            break;
        }
        case (LEFT):
        {
            if (rand()%2 == 0)
            {
                faceDirection = UP;
            }
            else
            {
                faceDirection = DOWN;
            }
            break;
        }
    }
}

void Human::Move()
{
    if (!MoveAllowed())
    {
        if (activity != AVOIDING_COLLISION)
        {
            myStack.push(activity);
        }
        ChangeDirection();
        timeSince = 0;
        activity = AVOIDING_COLLISION;
    }
    else
    {

        if (faceDirection == RIGHT)
        {

            pos.x += step;
            collideRect.x += step;

        }
        else if (faceDirection == LEFT)
        {
            pos.x -= step;
            collideRect.x -= step;

        }
        else if (faceDirection == DOWN)
        {
            pos.y += step;
            collideRect.y += step;

        }
        else if (faceDirection == UP)
        {
            pos.y -= step;
            collideRect.y -= step;

        }

    }

}

void Human::ChangeState(int n)
{
    timeSince = 0;
    if (!myStack.empty())
    {
        activity = myStack.top();
        myStack.pop();
    }
    else if (n != -1)
    {
        activity = n;
    }
    else
    {
        activity = rand()%3;
        switch (activity)
        {
            case (WALKING):
            {
                break;
            }
            case (GOING_TO_BED):
            {
                if (!isIndoor)
                {
                    myStack.push(GOING_TO_BED);
                    activity = GOING_TO_DOOR;
                }
            }
            case (GOING_TO_DOOR):
            {
                break;
            }
        }
    }

    if (activity == GOING_TO_BED)
    {
        ChooseBed();
    }
    else if (activity == GOING_TO_DOOR)
    {
        ChooseDoor();
    }

}

void Human::ChangeBedToFollow()
{
    ChooseBed();
}

void Human::ChooseBed()
{
    int n;
    Bed* myBeds = ownHouse->GetBeds(n);
    for (int i = 0; i < n; i++)
    {
        if (!myBeds[i].GetOccupied())
        {
            myBeds[i].GetCenter(toFollowX, toFollowY);
            bedToGoTo = &myBeds[i];
            break;
        }
    }
}

bool Human::MoveAllowed()
{
    SDL_Rect tempRect = collideRect;
    switch (faceDirection)
    {
        case (RIGHT):
        {
            tempRect.x++;
            if (tempRect.x > 1024)
            {
                return false;
            }
            break;
        }
        case (LEFT):
        {
            tempRect.x--;
            if (tempRect.x < 0)
            {
                return false;
            }
            break;
        }
        case (UP):
        {
            tempRect.y--;
            if (tempRect.y <= 488)
            {
                return false;
            }
            break;
        }
        case (DOWN):
        {
            tempRect.y++;
            if (tempRect.y >= 786)
            {
                return false;
            }
            break;
        }
    }
    if (Collide(tempRect))
    {
        return false;
    }
    return true;
}

void Human::ChooseDoor()
{
    door->GetCenter(toFollowX, toFollowY);
}

void Human::Show(SDL_Renderer* renderer)
{
    if (activity == WALKING || activity == GOING_TO_BED || activity == GOING_TO_DOOR)
    {
        if (faceDirection == RIGHT || faceDirection == LEFT)
        {
            Texture::GetInstance()->Render(80,renderer, &pos);
        }
        else if (faceDirection == UP)
        {
            Texture::GetInstance()->Render(79,renderer, &pos);
        }
        else
        {
            Texture::GetInstance()->Render(74, renderer, &pos);
        }
    }
    else if (activity == SITTING)
    {
        Texture::GetInstance()->Render(spriteNum, renderer, &pos);
    }

    SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    SDL_RenderDrawRect(renderer, &collideRect);
}
