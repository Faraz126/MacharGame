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
    if (frame % slowDownFactor == 0)
    {
        switch (activity)
        {
            case SITTING:
            {
                timeSince++;
                if (timeSince > 2000)
                {
                    bedToGoTo->SetOccupied(false);
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
                        Move();
                    }
                    else if(toFollowX < collideRect.x && isHorizontal)
                    {
                        faceDirection = LEFT;
                        Move();
                    }
                    else
                    {
                        isHorizontal = !isHorizontal;
                        faceDirection = UP;
                    }
                    if (toFollowY < collideRect.y && !isHorizontal)
                    {
                        faceDirection = UP;
                        Move();
                    }
                    else if (toFollowY == collideRect.y && !isHorizontal)
                    {
                        isHorizontal = true;
                        spriteNum = 75;
                        bedToGoTo->SetOccupied(true);
                        if (!isInfected)
                        {
                            ChangeState(SITTING);
                        }

                    }
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
                        Move();
                    }
                    else if(toFollowX < collideRect.x && isHorizontal)
                    {
                        faceDirection = LEFT;
                        Move();
                    }
                    else
                    {
                        isHorizontal = !isHorizontal;
                        faceDirection = UP;
                    }
                    if (toFollowY < collideRect.y && !isHorizontal)
                    {
                        faceDirection = UP;
                        Move();
                    }
                    else if (toFollowY == collideRect.y && !isHorizontal)
                    {
                        spriteNum = 75;
                        ChangeState(SITTING);
                        isHorizontal = true;
                    }
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
        }
    }


    /*
    if (frame % 500000 == 0 && !isGoingOut && !isGoingToBed)
    {
        int n = rand()% 150;
        if (n < 30)
        {
<<<<<<< HEAD
<<<<<<< HEAD
            isGoingToBed = true;
            bedToGoTo = ownHouse->GetClosestBed(pos.x, pos.y);
            toFollowX = bedToGoTo->GetX();
            toFollowY = bedToGoTo->GetY();
=======
            //std:: cout << "Walk Right!" << std::endl;
=======
>>>>>>> 6f0251d7d8c54a492201badeeed4528e18c5218b
            Right = true;
            Left = false;
        }
    }
}
>>>>>>> 9c7eea37c0327259caa32326d0ab9eb75c2422aa

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

<<<<<<< HEAD
=======
{
    clip += 0.03;
<<<<<<< HEAD
    //std::cout << "CLIP: " << clip << std::endl;
    if(clip >= 23)      // to change the clip after a certain amount the loop runs.
    {
        //std::cout << "YES" << std::endl;
=======
    if(clip >= 23)      // to change the clip after a certain amount the loop runs.
    {
>>>>>>> 6f0251d7d8c54a492201badeeed4528e18c5218b
        clip = 15;
    }
    speed += 0.6;
    if(speed >= 1)    // to adjust the x pos after a certain amount the loop runs.
    {
        speed = 0;
        pos.x += 1;
>>>>>>> 9c7eea37c0327259caa32326d0ab9eb75c2422aa
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
<<<<<<< HEAD
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
=======
            IsSitting = false;
            IsWalkingVertical = false;
            IsWalkingHorizontal = true;
            Down = false;
            clip = 15;          // this will be the clip where it starts to walk again
<<<<<<< HEAD
           // std::cout << "starting from default!" << std::endl;
        }
        //std::cout << "Walk Down!" << std::endl;
=======
        }
>>>>>>> 6f0251d7d8c54a492201badeeed4528e18c5218b
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
<<<<<<< HEAD
            //std::cout << "Reached Bed!" << std::endl;
        }
        //std::cout << "Walk Up!" << std::endl;
=======
        }
>>>>>>> 6f0251d7d8c54a492201badeeed4528e18c5218b
        WalkUp();



>>>>>>> 9c7eea37c0327259caa32326d0ab9eb75c2422aa
    }
    */
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

void Human::ChangeState(int n)
{
    timeSince = 0;
    if (!myStack.empty())
    {
        activity = myStack.top();
        myStack.pop();
    }
    if (n != -1)
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

void Human::ChooseDoor()
{
    door->GetCenter(toFollowX, toFollowY);
}

void Human::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    SDL_RenderDrawRect(renderer, &collideRect);
}
