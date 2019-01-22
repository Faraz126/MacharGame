#include "Alert.h"
#include "EndMenu.h"
#include <random>

DLL<Human*>* Alert::humans = new DLL<Human*>;
SDL_Rect* Alert::alert = new SDL_Rect[9];
SDL_Rect* Alert::timerPos = new SDL_Rect;


void Alert::SetUpRects()
{
    alert[0].x = 2651;
    alert[0].y = 6375;
    alert[0].w = 83;
    alert[0].h = 93;

    alert[1].x = 2651+83;
    alert[1].y = 6375;
    alert[1].w = 83;
    alert[1].h = 93;

    alert[2].x = 2651 + 83 + 83;
    alert[2].y = 6375;
    alert[2].w = 83;
    alert[2].h = 93;

    alert[3].x = 2651;
    alert[3].y = 6375+93;
    alert[3].w = 83;
    alert[3].h = 93;

    alert[4].x = 2651 + 83;
    alert[4].y = 6375+93;
    alert[4].w = 83;
    alert[4].h = 93;

    alert[5].x = 2651+ 83 +83;
    alert[5].y = 6375+93;
    alert[5].w = 83;
    alert[5].h = 93;

    alert[6].x = 2651;
    alert[6].y = 6375+93+93;
    alert[6].w = 83;
    alert[6].h = 93;

    alert[7].x = 2651 + 83;
    alert[7].y = 6375+93+93;
    alert[7].w = 83;
    alert[7].h = 93;

    alert[8].x = 2651+ 83 +83;
    alert[8].y = 6375+93+93;
    alert[8].w = 83;
    alert[8].h = 93;

    //humanPtr = ptr;


    timerPos->x = 640;
    timerPos->y = 0;
    timerPos->w = 60;
    timerPos->h = 60;
}

Alert::Alert()
{

//    timerSprite = 0;
//    word = new Word[1];
//    word[0].SetText("H U M A N   D I E D");
//    word[0].ReduceSize(3);
//    word[0].SetPosition(250,600);
//    show = true;
//    wordRect = new SDL_Rect;
//    wordRect->x = 80;
//    wordRect->y = 570;
//    wordRect->w = 800;
//    wordRect->h  = 200;
//
//
//    int randStr3 = rand()% 7;
//    str1 = "The Human Died As You Were Not Able To ";
//    str2 = "Stop The Mosquito Breeding From ";
//    if (randStr3==0)
//    {
//        str3 = "Tub";
//    }
//    else if (randStr3==1)
//    {
//        str3 = "Bucket";
//    }
//    else if (randStr3==2)
//    {
//        str3 = "Dirty Water";
//    }
//    else if (randStr3==3)
//    {
//        str3 = "Clean Water ";
//    }
//    else if (randStr3==4)
//    {
//        str3 = "Trash";
//    }
//    else if (randStr3==5)
//    {
//        str3 = "Trash Can";
//    }
//    else if (randStr3==6)
//    {
//        str3 = "Manhole";
//    }
//
//    word = new Word[2];
//    word[0].SetText(str1);
//    word[0].SetPosition(100,600);
//    word[0].ReduceSize(0.8);
//    word[1].SetText(str2+str3);
//    word[1].SetPosition(100,650);
//    word[1].ReduceSize(0.8);
//
//    screenEnd = false;

}

void Alert::Add(Human* human)
{
    humans->Append(human);
}


void Alert::Remove(Human* human)
{
    humans->RemoveItem(human);
}

void Alert::Show(SDL_Renderer* gRenderer)
{
    int dyingHuman = -1;
    int time = 200000;
    int dyingTime = 200000;
    if (humans->GetLength() > 0)
    {
        for (int i =0; i < humans->GetLength(); i++)
        {
            dyingTime = humans->GiveItem(i)->GetTimeToDie();
            if (dyingTime < time)
            {
                time = dyingTime;
                dyingHuman = i;
            }
        }
    }

    if (dyingHuman != -1)
    {
        Texture::GetInstance()->RenderBack(1,gRenderer, &alert[(int)(time/22225)], timerPos);
    }


    /*

    if (show)
    {

    }

    if(int(timerSprite)==34)
    {
        SDL_SetRenderDrawColor( gRenderer, 2,85,89,0 );
        SDL_RenderDrawRect(gRenderer,wordRect);
        SDL_RenderFillRect(gRenderer,wordRect);
        for(int i =0; i<2 ; i++)
        {
            word[i].Show(gRenderer);
        }
        screenEnd = true;
    }
    */



}

double Alert::GetTimerSprite()
{
    //return timerSprite;
}
void Alert::HandleEvents(SDL_Event* e, Screens_Node& node)
{

}

Alert::~Alert()
{

    delete timerPos;
    //delete[] word;
}
