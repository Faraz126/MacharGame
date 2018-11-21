#include "closingMoving.h"

ClosingMoving::ClosingMoving()
{
    ClosingMovingPos = new SDL_Rect;
    ClosingMovingPos->x= 500;
    ClosingMovingPos->y= 100;
    ClosingMovingPos->w= 1240;
    ClosingMovingPos->h= 786;

    word = new Word[5];

    word[0].SetText("TEAM MEMBERS");
    word[0].SetPosition(ClosingMovingPos->x+35,ClosingMovingPos->y+15);

    word[0].SetText("FARAZ KHAN");
    word[0].SetPosition(ClosingMovingPos->x+35,ClosingMovingPos->y+75);

    word[1].SetText("HAREEM FEROZ");
    word[1].SetPosition(ClosingMovingPos->x+35,ClosingMovingPos->y+125);
}

void ClosingMoving::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
    SDL_RenderFillRect(gRenderer,ClosingMovingPos);
    for(int i=0; i<1; i++)
    {
         word[i].Show(gRenderer);
    }
}

