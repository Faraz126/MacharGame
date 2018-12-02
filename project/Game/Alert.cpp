#include "Alert.h"
#include "EndMenu.h"
#include <random>

Alert::Alert()
{
    timerSprite = 27;
    newScreenIter = 0;
    alertPos = new SDL_Rect;
    alertPos->x = 600;
    alertPos->y = 4;
    alertPos->w = 30;
    alertPos->h = 30;

    timerPos = new SDL_Rect;
    timerPos->x = 640;
    timerPos->y = 0;
    timerPos->w = 60;
    timerPos->h = 60;

    wordRect = new SDL_Rect;
    wordRect->x = 80;
    wordRect->y = 570;
    wordRect->w = 800;
    wordRect->h  = 200;


    int randStr3 = rand()% 7;
    str1 = "The Human Died As You Were Not Able To ";
    str2 = "Stop The Mosquito Breeding From ";
    if (randStr3==0)
    {
        str3 = "Tub";
    }
    else if (randStr3==1)
    {
        str3 = "Bucket";
    }
    else if (randStr3==2)
    {
        str3 = "Dirty Water";
    }
    else if (randStr3==3)
    {
        str3 = "Clean Water ";
    }
    else if (randStr3==4)
    {
        str3 = "Trash";
    }
    else if (randStr3==5)
    {
        str3 = "Trash Can";
    }
    else if (randStr3==6)
    {
        str3 = "Manhole";
    }

    word = new Word[2];
    word[0].SetText(str1);
    word[0].SetPosition(100,600);
    word[0].ReduceSize(0.8);
    word[1].SetText(str2+str3);
    word[1].SetPosition(100,650);
    word[1].ReduceSize(0.8);

    screenEnd = false;

}
void Alert::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(38, gRenderer, alertPos);
    texture->Render(int(timerSprite), gRenderer, timerPos);

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

}

void Alert::Update(double a)
{
    //this->timerSprite = a;

    if (timerSprite>26 && timerSprite<34)
    {
        timerSprite += 0.001;
    }

}
double Alert::GetTimerSprite()
{
    return timerSprite;
}
void Alert::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    if(screenEnd==true)
    {
        node.cur_screen = new EndMenu;
        node.prev_screen = node.cur_screen;
        node.prev_backable = true;
        node.prev_updatable = false;
    }
}

Alert::~Alert()
{
    delete alertPos;
    delete timerPos;
    delete[] word;
}
