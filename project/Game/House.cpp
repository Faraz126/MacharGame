#include "House.h"
#include <random>
#include "Scenario.h"
#include "Outdoor.h"
#include "EndMenu.h"

House::House(): Scenario(0, true, false, true, 1)
{
    noOfBreedingPlaces = 0;
    code = 1;
    pos.x = wall.x = 0;
    pos.y = wall.y = 0;
    pos.w = wall.w = 1024;
    pos.h = 786;
    wall.h = 488;
    houseShop = new ShoppingMenu(this, true, true, true, 1);

    ///defining the walking region
    startWidth = 0;
    endWidth = 1024;
    startHeight = 488;
    endHeight = 786;

    SetUpEntrancesAndShowPieces();


    int y = 600;
    //while (noOfBreedingPlaces < 3 && y < 740)
    {
        ///putting breeding places at pseudo random positions
        /*
        if (rand()%3 == 1)
        {
            if (rand()%2 == 1)
            {
                breedingplaces[noOfBreedingPlaces] = new Tub(15, y);

            }
            else
            {
                breedingplaces[noOfBreedingPlaces] = new Tub(900, y);
            }
            myQ.Append(breedingplaces[noOfBreedingPlaces]);
            breedingplaces[noOfBreedingPlaces++]->ReduceSize(float(y)/1600);

        }
        y += 70;
        */
    }


    btn = new Button;
    myQ.Append(btn);
    btn->setPosition(800,60);
    btn->SetWidth(200,55);
    btn->setText("OUTDOOR");
    btn->word->ReduceSize(0.8);
    btn->word->SetPosition(800+10,60+10);


    //houseShop->shopShow = false;
    cartPos = new SDL_Rect;
    SetUpScenarios();
    GenerateHumans();

    cartPos->x = 960;
    cartPos->y = 720;
    cartPos->w = 193 *0.3;
    cartPos->h = 193 *0.3;

    upperRect0 = new SDL_Rect;

    upperRect0->x = 0;
    upperRect0->y = 0;
    upperRect0->x = 1240;
    upperRect0->h = 55;

    money.SetPaisa(10000);
}

void House::GenerateHumans()
{
    Human* humanPtr;
    for (int i = 0; i < noOfHumans; i++)
    {
        int x = i * 30;
        int y = 388 + (i*90);
        humanPtr = new Human((i*30), 388 + (i*90),this);
        while (Collides(humanPtr))
        {
            humanPtr->UpdatePos(++x,y);
        }
        myQ.Append(humanPtr);
        humans.Append(humanPtr);
    }
}

void House::SetUpEntrancesAndShowPieces()
{

    noOfEntrance = (rand() % 2) + 2;
    noOfHumans = (rand()%3) + 3;
    bed = new Bed[noOfHumans];
    breedingplaces = new BreedingGround*[3];
    for (int i = 0; i< 3; i++)
    {
        breedingplaces[i] = 0;
    }
    entrance = new Entrance*[noOfEntrance];
    int x;
    if (rand() % 2) //random x co-ordinate for the door
    {
        x = 265;
        entrance[0] = new Door(100, 300);
        if (rand() % 2)
        {
            breedingplaces[1] = new Tub(15, 670);
            myQ.Append(breedingplaces[1]);
            breedingplaces[1]->ReduceSize(float(670)/1600);
            noOfBreedingPlaces++;
        }

        entrance[0]->SetScenario(this);
        breedingplaces[0] = new TrashCan(10,450);
        myQ.Append(breedingplaces[0]);
        noOfBreedingPlaces++;

    }
    else
    {
        x = 10;
        entrance[0] = new Door(750, 300);
        if (rand() % 2)
        {
            breedingplaces[1] = new Tub(900, 670);
            myQ.Append(breedingplaces[1]);
            breedingplaces[1]->ReduceSize(float(670)/1600);
            noOfBreedingPlaces++;
        }
        entrance[0]->SetScenario(this);
        breedingplaces[0] = new TrashCan(925,450);
        myQ.Append(breedingplaces[0]);
        noOfBreedingPlaces++;
    }

    for (int i = 0; i<noOfHumans; i++) //setting up beds equal to number of humans
    {
        bed[i].SetPos(x, 365);
        myQ.Append(&bed[i]);
        x += 150;
    }

    if (noOfEntrance == 3)
    {
        showpieces = new Showpiece[2];
        showpieces[0].SetPos(467, 132, 26);
        showpieces[1].SetPos(200, 600, 70);
        entrance[1] = new Window(200,125);
        entrance[2] = new Window(600,125);

    }
    else
    {
        showpieces = new Showpiece[3];
        showpieces[0].SetPos(100, 150);
        showpieces[1].SetPos(700, 150);
        showpieces[2].SetPos(200, 600, 70);
        entrance[1] = new Window(412,125);
    }

}

void House::SetOutdoor(Outdoor* outdoorPtr)
{
    ///set house to know the outdoor
    outdoor = outdoorPtr;
    prevScreen = outdoorPtr;
    SetUpScenarios();

}


void House::Show(SDL_Renderer* renderer)
{

    Texture::GetInstance()->Render(9, renderer, &pos);
    texture = Texture::GetInstance(renderer);
    texture->Render(115,renderer,cartPos);

    //SDL_SetRenderDrawColor(renderer, 30,30,30,0); //wall feature
    //SDL_RenderFillRect(renderer, &wall);


    for(int i=0; i < noOfEntrance; i++) //displaying entrances
    {
        entrance[i]->Show(renderer);
    }

    for (int i = 0; i < mosquitoes.GetLength(); i++) //displaying mosquitoes
    {
        mosquitoes.GiveItem(i)->Show(renderer);
    }


    for (int i = 0; i < myQ.GetLength(); i++)
    {
        myQ.GiveItem(i)->Show(renderer);
    }



    /*
    int max = 2000000;

    toShow = false;
    for (int i = 0; i< humans.GetLength(); i++)
    {
        if (humans.GiveItem(i)->GetInfected() && humans.GiveItem(i)->GetTimeToDie() < max)
        {
            if (humans.GiveItem(i)->IsDead())
            {
                curScreen = new EndMenu(outdoor, true);
            }
            else
            {

            }
            max = humans.GiveItem(i)->GetTimeToDie();
            dyingIndex = i;
            toShow = true;

        }
    }
    if (toShow)
    alert.Show(renderer, (int)(humans.GiveItem(dyingIndex)->GetTimeToDie()/22225));
    */

    if(houseShop->GetShopShow())
        houseShop->Show(renderer);

    SDL_SetRenderDrawColor( renderer, 2,85,89,0 );
    SDL_RenderDrawRect(renderer,upperRect0);
    SDL_RenderFillRect(renderer,upperRect0);
    points->Show(renderer);
    money.Show(renderer);
    Alert::Show(renderer, curScreen);

}

void House::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if (e->type == SDL_QUIT)
    {
        SDL_Quit();
    }
    if( e->type == SDL_KEYDOWN )
    {

        if(e->key.keysym.sym == SDLK_ESCAPE)    //will open pause menu
        {
            /*
            node.cur_screen = new PauseMenu(outdoor);
            node.prev_screen = this;
            node.prev_updatable = false;
            node.prev_backable = true;
            */
            curScreen = new PauseMenu(outdoor, this, true);

        }
    }
    else if( e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
    {
        int mousePosX = e->button.x;
        int mousePosY = e->button.y;

        if( ( mousePosX >cartPos->x ) && ( mousePosX < (cartPos->x+cartPos->w) ) && ( mousePosY > cartPos->y ) && (mousePosY< (cartPos->y+cartPos->h) ) )
            houseShop->SetShopShow(true);

        if( ( mousePosX >houseShop->GetShoppingExitPosX() ) && ( mousePosX < (houseShop->GetShoppingExitPosX()+houseShop->GetShoppingExitPosW()) ) && ( mousePosY > houseShop->GetShoppingExitPosY() ) && (mousePosY< (houseShop->GetShoppingExitPosY()+houseShop->GetShoppingExitPosH()) ) )
            houseShop->SetShopShow(false);

         if (btn->WithinRegion(mousePosX,mousePosY))  //for outdoor button in house
        {
            curScreen = prevScreen;

        }

    }
    for (int i = 0; i <myQ.GetLength(); i++)
    {
        myQ.GiveItem(i)->HandleEvents(e, node);
    }
    houseShop->HandleEvents(e,node);

}


void House::Update(int frame)
{
    if (curScreen == this)
    {
        Screens::Update(frame);
    }

    for (int i = 0; i <noOfEntrance; i++)
    {
        entrance[i]->Update(frame);
    }
    /*
    for (int i = 0; i < noOfHumans; i++)
    {
        humans.GiveItem(i)->Update(frame);
    }
    */
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        myQ.GiveItem(i)->Update(frame);
    }

    for (int i = 0; i < mosquitoes.GetLength();i++)
    {
        if (mosquitoes.GiveItem(i)->GetIsDead())
        {
            /*
            Mosquito* myM = mosquitoes.GiveItem(i);
            cout << mosquitoes.GetLength();
            mosquitoes.RemoveItem(myM);
            delete myM;
            cout << mosquitoes.GetLength();
            break;
            */
            Mosquito* myM = mosquitoes.GiveItem(i);
            mosquitoes.Pop(i);
            //delete myM;
            break;

        }
        else
        {
            mosquitoes.GiveItem(i)->Update(frame);
        }
    }



}


Money& House::GetMoney()
{
    return money;
}

Door* House::GetDoor()
{
    return static_cast<Door*>(entrance[0]);
}

House::~House()
{
    /*
    for (int i = 0; i < myQ.GetLength(); i++)
    {
        delete myQ.GiveItem(i++);
    }

    for (int i = 0; i < mosquitoes.GetLength(); i++)
    {
        delete mosquitoes.GiveItem(i++);
    }



//    delete[] bed;

    for (int i = 0; i <noOfEntrance; i++)
    {
        delete entrance[i];
    }
    delete[] entrance;
    delete[] showpieces;
    delete cartPos;
    delete houseShop;
    */
}


int House::NoOfHumans()
{
    return noOfHumans;
}

Bed* House::GetBeds(int &n)
{
    n = noOfHumans; //puts the no of beds in n, since the caller doesnt know the size
    return bed;
}


Outdoor* House::GetOutdoor()
{
    return outdoor;
}


void House::SetUpScenarios()
{
    Scenario::SetUpScenarios();
    for (int i = 0; i < noOfEntrance; i++)
    {
        entrance[i]->SetScenario(this);
        entrance[i]->SetOutdoor(outdoor);
        //providing outdoor pointer to entrances, since it is associated with both scenarioes.
    }
}



void House::ApplyRepellent()
{
    for (int i = 0; i < humans.GetLength(); i++)
    {
        humans.GiveItem(i)->SetCoveredInRepellant();
    }
}


