#include "Hospital.h"
#include "Manual.h"
#include <random>
#include <iostream>

using namespace std;

Hospital::Hospital(Screens* prev): Scenario(prev, true, false, true, 1)
{
    int humanPos[8] = {303,391,488,574,669,756,849,936};// position of humans sitting on chairs
    popped = NULL;

    for (int i = 0; i < 8; i++)
    {
        this->humanPos[i] = humanPos[i];
    }
    pos.x = 0;
    pos.y  = 0;
    pos.w  = 1024;
    pos.h = 786;

    btn = new Button[2];
    btn[0].SetButtonSprite(false);
    btn[0].setPosition(280,80);
    btn[0].SetWidth(315*1.5,70*0.8);
    btn[0].setText("SEE PATIENT");
    btn[0].word->ReduceSize(0.8);

    btn[1].setPosition(800,60);
    btn[1].SetWidth(200,55);
    btn[1].setText("OUTDOOR");

    upperRect = new SDL_Rect;

    upperRect->x = 0;
    upperRect-> y =0;
    upperRect->x = 1240;
    upperRect->h = 55;

    manualShow = false;


}

void Hospital::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(113, renderer, &pos);
    for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->Show(renderer);
     }

     if(humans.GetLength()>0)
     {
         btn->Show(renderer);
     }
     if(!manualShow)
     {
         btn[0].Show(renderer);
     }
     btn[1].Show(renderer);
     SDL_SetRenderDrawColor( renderer, 2,85,89,0 );
    SDL_RenderDrawRect(renderer,upperRect);
    SDL_RenderFillRect(renderer,upperRect);
    points->Show(renderer);

}

void Hospital::HandleEvents(SDL_Event* e,Screens_Node& node)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

    if (e->type == SDL_QUIT)
    {
        SDL_Quit();
    }
    if( e->type == SDL_KEYDOWN )
    {

        if(e->key.keysym.sym == SDLK_ESCAPE)    //will open pause menu
        {
//            node.cur_screen = new PauseMenu(outdoor);  //EVENT TO BE DEALT
//            node.prev_screen = this;
//            node.prev_updatable = false;
//            node.prev_backable = true;

        }
    }
    if( btn[0].WithinRegion(hoverX,hoverY)==true)
    {
        btn[0].Hover();
        if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        {
            /*
            node.cur_screen = new Manual(235,70);
            node.prev_screen = this;
            node.prev_backable = true;
            node.prev_updatable = true;
            */
            if (humans.GetLength() > 0)
            {
                curScreen = new Manual(235, 70, this);
                manualShow = true;
            }

        }

    }

    else
    {
        btn[0].SetSprite2(123);
    }

    if (btn[1].WithinRegion(hoverX,hoverY))  //for outdoor button in house
    {
        if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        {
            /*
            node.cur_screen = node.prev_screen;
            node.prev_screen = this;
            */
            curScreen = prevScreen;
            Texture::GetInstance()->SetSound(OUTDDOORINDOOR);
        }
    }

}

void Hospital::Update(int frame)
{

}

Hospital :: ~Hospital()
{
    delete[] btn;
}

 bool Hospital :: AddHuman(Human* human)
 {

     bool allowAppend = false;
     if(humans.GetLength()<=8) //only 8 humans allowed in hospital
     {
         allowAppend = true;
         humans.Append(human);
         for(int i = 0; i<20; i++)
        {
            (*Score::GetInstance())++;
        }

        humans.GiveItem(humans.GetLength()-1)->UpdatePos(humanPos[humans.GetLength()-1],465);
        humans.GiveItem(humans.GetLength()-1)->ReduceSize(1.25);
        popped = humans.GiveItem(0);
        return allowAppend;
     }
     else
     {
         return allowAppend;
     }


 }

void Hospital :: LeaveHuman(Human* human)
{
      humans.Pop();
      for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->UpdatePos(humanPos[i],465);
     }
     popped = humans.GiveItem(0);
}

void Hospital :: LeaveHuman()
{
    manualShow = false;
    Human* ptr = humans.Pop(0);
    ptr->SetInfected(0);
    ptr->GoIndoor();
    for(int i = 0; i<humans.GetLength(); i++)
    {
        humans.GiveItem(i)->UpdatePos(humanPos[i],465);
    }
    popped = humans.GiveItem(0);
}

Human* Hospital :: GetPopped() ///to display the first human on manual
{
    if (humans.GetLength()==0)
    {
        popped = NULL;
        return popped;
    }
    return popped;
}

int Hospital :: CheckHumanDisease() ///to use for correct option in manual
{
    return (humans.GiveItem(0)->GetDisease());
}
