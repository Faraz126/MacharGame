#include "Human.h"
#include <random>
#include <cmath>
#include "House.h"
#include "Scenario.h"
#include "Bed.h"
#include "Hospital.h"


Human::Human(): Clickable(0,0,197, 575)
{
    ownHouse = 0;
    health = 1000;
}


Human::Human(int x, int y, House* house): Clickable(x,y,197, 570)
{

    shake = false;
    hasRepeppant = false;
    spriteNum = 74;
    ownHouse  =  house;
    currentScenario = house;
    sizeFactor = 0.3;
    ReduceSize(sizeFactor);
    isIndoor = true;
    faceDirection = RIGHT;
    isVertical = false;
    isHorizontal = true;
    activity = WALKING;
    timeSince = 0;
    step = 1;
    slowDownFactor = 2;
    isInfected = false;
    door = ownHouse->GetDoor();
    faceSprite = 86;
    bodySprite = 83;
    legSprite = 1;
    disease = 0;
    walker = 0;
    BuildHuman();
    bedToGoTo = 0;
    sentToBed = false;
    timeToDie = 200000;
    timeSinceRepellent = 0;

}

void Human::SetCoveredInRepellant()
{
    hasRepeppant = true;
    timeSinceRepellent = 0;
}

void Human::ChangeScenario(Scenario* scenario)
{
    currentScenario = scenario;
}



void Human::BuildHuman()
{
    face.x = pos.x;
    face.y = pos.y;
    face.w = 193*sizeFactor;
    face.h = 124*sizeFactor;

    body.x = pos.x;
    body.y = face.y + face.h - (10*(3*sizeFactor));
    body.w = 193 * sizeFactor;
    body.h = 268 * sizeFactor;

    legs.x = pos.x;
    legs.y = body.y + body.h - (20*(3*sizeFactor));
    legs.w = 133*(sizeFactor)*2;
    legs.h = 166*(sizeFactor)*2;
    collideRect.x = pos.x;
    collideRect.y = legs.y + legs.h - 20;
    collideRect.w = legs.w;
    collideRect.h = 10;

}

void Human::HandleEvents(SDL_Event* e, Screens_Node&)
{
    return;
}

Human::Human(House* house): Human(0,0, house)
{

}

void Human::Damage()
{
    timeToDie = timeToDie - 10000;
}

bool Human::Collide(SDL_Rect& tempRect)
{
    DLL<Clickable*>* myQ = &currentScenario->GetQ();

    for (int i = 0; i < myQ->GetLength(); i++)
    {
        if (myQ->GiveItem(i)->Collides(tempRect) && myQ->GiveItem(i) != this)
        {
            myQ->GiveItem(i)->Collision();
            return true;
        }
    }
    return false;
}


bool Human::Collides(const SDL_Rect& rect)
{
    return Clickable::Collides(collideRect, rect);
}



void Human::Update(int frame)
{
    if (hasRepeppant && timeSinceRepellent < 200000)
    {
        timeSinceRepellent++;
    }
    else if(hasRepeppant)
    {
        hasRepeppant = false;
    }


    if (isInfected && !sentToBed)
    {
        if (activity != SITTING && activity != LYING)
        {
            //isInfected = true;
            while (!myStack.IsEmpty())
            {
                myStack.Pop();
            }
            ChangeState(GOING_TO_BED);
            sentToBed = true;
        }
    }

    if (frame % slowDownFactor == 0)
    {


        switch (activity)
        {

            case (LYING):
            {
                timeSince++;
                timeToDie -= 30;
                if (timeSince > 200000)
                {
                    dead = true;
                    ChangeState();
                }
                break;
            }

            case SITTING:
            {
                timeSince++;
                if (timeSince > 2000)
                {
                    bedToGoTo->SetOccupied(false);
                    while (!myStack.IsEmpty())
                    {
                        myStack.Pop();
                    }
                    ChangeState();
                    isInfected = false;
                }
                break;
            }

            case GOING_TO_BED:
            {
                if (bedToGoTo != 0 && !bedToGoTo->GetOccupied())
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
                    if (bedToGoTo->Collides(collideRect) || bedToGoTo->Collides(legs))
                    {
                        isHorizontal = true;
                        spriteNum = 75;
                        bedToGoTo->SetOccupied(true, this);
                        if (!isInfected)
                        {
                            ChangeState(SITTING);
                            bedToGoTo->HumanState(SITTING);
                        }
                        else
                        {
                            ChangeState(LYING);
                            bedToGoTo->HumanState(LYING);
                        }
                    }

                }
                else
                {
                    ChangeBedToFollow();
                }
                Move();
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
                    if (true)
                    {

                        if (!isIndoor && (Clickable::Collides(door->GetOutdoorRect(), legs) || Clickable::Collides(door->GetOutdoorRect(), collideRect)))
                        {

                            GoIndoor();
                        }
                        else if (isIndoor && (door->Collides(collideRect) || door->Collides(legs)))
                        {
                            spriteNum = 76;
                            isHorizontal = true;
                            GoOutdoor();
                        }

                    }
                Move();
                break;
            }


            case WALKING:
            {
                if (timeSince*step > ((currentScenario->GetEndWidth()-currentScenario->GetStartWidth())*2))
                {
                    ChangeState();
                }
                if (collideRect.x >= currentScenario->GetEndWidth())
                {
                    faceDirection = LEFT;
                }
                else if (collideRect.x <= currentScenario->GetStartWidth())
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
                if (activity == AVOIDING_COLLISION)
                {
                    if(!MoveAllowed())
                    {
                        faceDirection = LEFT;
                    }
                }
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
                if (activity == AVOIDING_COLLISION)
                {
                    if(!MoveAllowed())
                    {
                        faceDirection = UP;
                    }
                }
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
                if (activity == AVOIDING_COLLISION)
                {
                    if(!MoveAllowed())
                    {
                        faceDirection = RIGHT;
                    }
                }
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
                if (activity == AVOIDING_COLLISION)
                {
                    if(!MoveAllowed())
                    {
                        faceDirection = DOWN;
                    }
                }
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

            myStack.Append(activity);
        }
        ChangeDirection();
        timeSince = 0;
        activity = AVOIDING_COLLISION;
    }
    else
    {
        walker += 0.02;
        if (walker >= 9)
        {
            walker = 0;
        }

        if (faceDirection == RIGHT)
        {

            pos.x += step;
            collideRect.x += step;
            face.x += step;
            body.x += step;
            legs.x += step;

        }
        else if (faceDirection == LEFT)
        {
            pos.x -= step;
            collideRect.x -= step;
            face.x -= step;
            body.x -= step;
            legs.x -= step;

        }
        else if (faceDirection == DOWN)
        {
            pos.y += step;
            collideRect.y += step;
            face.y += step;
            body.y += step;
            legs.y += step;

        }
        else if (faceDirection == UP)
        {
            pos.y -= step;
            collideRect.y -= step;
            face.y -= step;
            body.y -= step;
            legs.y -= step;

        }

    }

}

void Human::ChangeState(int n)
{
    timeSince = 0;
    if (!myStack.IsEmpty())
    {
        activity = myStack.Pop();
    }
    else if (n != -1)
    {
        activity = n;
    }
    else
    {
        activity = rand()%3;
    }

    if (activity == GOING_TO_BED)
    {
        if (!isIndoor)
        {
            myStack.Append(GOING_TO_BED);
            activity = GOING_TO_DOOR;
        }
        else
        {
            ChooseBed();
        }
    }
    if (activity == GOING_TO_DOOR)
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
            return;
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

            if (tempRect.x +1> currentScenario->GetEndWidth())
            {
                return false;
            }
            else
            {
                tempRect.x += 10;
            }
            break;
        }
        case (LEFT):
        {

            if (tempRect.x -1 < currentScenario->GetStartWidth())
            {
                return false;
            }
            else
            {
                tempRect.x -= 10;
            }
            break;
        }
        case (UP):
        {

            if (tempRect.y -1 <= currentScenario->GetStartHeight())
            {
                return false;
            }
            else
            {
                tempRect.y -= 10;
            }
            break;
        }
        case (DOWN):
        {
            if (tempRect.y + 1>= currentScenario->GetEndHeight())
            {
                return false;
            }
            else
            {
                tempRect.y += 10;
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
    if (isIndoor)
    {
        door->GetCenter(toFollowX, toFollowY);
    }
    else
    {
        door->OutdoorPosCenter(toFollowX, toFollowY);
    }

}

void Human::Show(SDL_Renderer* renderer)
{
    SDL_Rect leg;


    if (activity == WALKING || activity == GOING_TO_BED || activity == GOING_TO_DOOR || activity == AVOIDING_COLLISION)
    {
        int face = 0;
        int body = 0;
        //int leg = 0;

        bool flipped = false;

        if (faceDirection == UP)
        {
            face = 85;
//            leg = 93;
            leg = {50, 6331, 179,159};
            body = 82;
            if (isIndoor)
            {
                legs.x = pos.x- 20;
            }
            else
            {
                legs.x = pos.x-15;
            }
        }
        else if (faceDirection == RIGHT)
        {
            leg = {79, 6100, 138,166};
            face = 86;
//            leg = 103;
            body = 83;
            flipped = false;
            legs.x = pos.x;
        }
        else if (faceDirection == LEFT)
        {
            leg = {79, 6100, 138,166};
            face = 86;
            //leg = 103;
            body = 83;
            flipped = true;
            if (isIndoor)
            {
                legs.x = pos.x- 20;
            }
            else
            {
                legs.x = pos.x-15;
            }

        }
        else if (faceDirection == DOWN)
        {
            face = 84;
            //leg = 93;
            leg = {50, 6331, 179,159};
            body = 81;
            if (isIndoor)
            {
                legs.x = pos.x- 20;
            }
            else
            {
                legs.x = pos.x-15;
            }
        }

        if (isInfected)
        {
            face += 3;
        }
        else if (disease == BITEN)
        {
            face += 6;
        }

        leg.x =  leg.x + (((int)walker)*leg.w);

        if (!flipped)
        {
            if (hasRepeppant)
            {
                Texture::GetInstance()->Render(76,renderer, &this->face);
                Texture::GetInstance()->RenderBack(76, renderer, &leg , &legs, true);
                Texture::GetInstance()->Render(76,renderer, &this->body);
            }
            else
            {
                Texture::GetInstance()->Render(face,renderer, &this->face);
                Texture::GetInstance()->RenderBack(2, renderer, &leg , &legs, true);
                Texture::GetInstance()->Render(body,renderer, &this->body);
            }


        }
        else
        {

            if (hasRepeppant)
            {
                Texture::GetInstance()->Render(76,renderer, &this->face);
                Texture::GetInstance()->RenderBack(76, renderer, &leg , &legs, true);
                Texture::GetInstance()->Render(76,renderer, &this->body);
            }
            else
            {
                Texture::GetInstance()->RenderFlipped(face,renderer, &this->face);
                Texture::GetInstance()->RenderBack(2, renderer, &leg , &legs);
                //Texture::GetInstance()->RenderFlipped((int)(leg+ walker), renderer, &legs);
                Texture::GetInstance()->RenderFlipped(body,renderer, &this->body);
            }

        }

    }
    else if (activity == SITTING)
    {
        //Texture::GetInstance()->Render(spriteNum, renderer, &pos);
    }

    else if (activity == IN_HOSPITAL)
    {
        if(disease == DISEASE_MALARIA)
        {
            SDL_Rect newR;
            newR = pos;
            newR.x += 10;
            //Texture::GetInstance()->Render(135, renderer, &pos); ///HAVE TO CHANGE
            Texture::GetInstance()->Render(134, renderer, &newR);
        }
        else if(disease == CHICKENGUNYA)
        {
            Texture::GetInstance()->Render(135, renderer, &pos); ///HAVE TO CHANGE
        }
        else if(disease == DENGUE)
        {
            Texture::GetInstance()->Render(136, renderer, &pos); ///HAVE TO CHANGE
        }
        else
        {
            //Texture::GetInstance()->Render(134, renderer, &pos);
        }

    }
    //SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
    //SDL_RenderDrawRect(renderer, &collideRect);
}


void Human::GoIndoor()
{
    isIndoor = true;
    ownHouse->GetOutdoor()->LeaveHuman(this);
    ownHouse->AddHuman(this);
    ChangeScenario(ownHouse);
    door = ownHouse->GetDoor();
    door->GetCenter(pos.x, pos.y);
    sizeFactor = 0.3;
    //ReduceSize(sizeFactor);
    BuildHuman();
    ChangeState();
}

void Human::GoOutdoor()
{
    isIndoor = false;
    ownHouse->GetOutdoor()->AddHuman(this);
    ownHouse->LeaveHuman(this);
    ChangeScenario(ownHouse->GetOutdoor());
    door = ownHouse->GetDoor();
    door->OutdoorPosCenter(pos.x, pos.y);
    sizeFactor = 0.2;
    //ReduceSize(sizeFactor);
    BuildHuman();
    ChangeState(WALKING);
}

bool Human::GetIndoor()
{
    return isIndoor;
}

void Human::UpdatePos(int x, int y)
{
    Clickable::UpdatePos(x,y);
    BuildHuman();
}


void Human::SetX(int delta, int direction)
{
    if ( direction == 0)
    {
        collideRect.x+=delta;
        face.x += delta;
        body.x += delta;
        legs.x += delta;
    }
    if ( direction == 1)
    {
        collideRect.x -=delta;
        face.x -= delta;
        body.x -= delta;
        legs.x -= delta;
    }
    Clickable::SetX(delta, direction);
}


void Human::SetInfected(int code)
{
/*
    if (activity != SITTING && activity != LYING)
    {

        this -> disease = code;
        if (code)
        {
            isInfected = true;
//        while (!myStack.IsEmpty())
//        {
//            myStack.Pop();
//        }
            ChangeState(GOING_TO_DOOR);
        }
        else
        {
            isInfected = false;
        }

    }
    */

    if (this->disease <= BITEN)
    {
       this->disease = code;
    }


    if (code == 0)
    {
        isInfected  = false;
    }
    if (code > BITEN)
    {
        Alert::Add(this);
        isInfected = true;
        if (code == MALARIA)
        {
            shake = true;
        }
        disease = code;


    }

    //std::cout << disease << std::endl;

}

int Human::GetInfected()
{
    return isInfected;

}

void Human::GoToHospital()
{
    Alert::Remove(this);

    timeToDie = 200000;
    isInfected = false;
    isIndoor = false;
    ownHouse->LeaveHuman(this);
    bedToGoTo->SetOccupied(false);
    bedToGoTo = 0;
    ChangeScenario(ownHouse->GetOutdoor()->hospital);
    ownHouse->GetOutdoor()->hospital->AddHuman(this);
    ChangeState(IN_HOSPITAL);
}


int Human::GetDisease()
{
    return disease;
}


void Human::ShowAlert(SDL_Renderer* gRenderer, SDL_Rect* sprites, Screens* curHouse)
{
    SDL_Rect bedPos;
    if (bedToGoTo == 0)
    {
        return;
    }

    bedPos.x = bedToGoTo->GetX() + 76/2;
    bedPos.y = bedToGoTo->GetY() - 50;
    bedPos.w = 50;
    bedPos.h = 50;

    if (curHouse == ownHouse)
    Texture::GetInstance()->RenderBack(1,gRenderer, &sprites[(int)(timeToDie/22225)], &bedPos);
}
