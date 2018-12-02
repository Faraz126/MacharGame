#include "Hospital.h"
#include <random>
#include <iostream>

using namespace std;

Hospital:: Hospital()
{
    int humanPos[8] = {340,427,523,610,705,792,885,972};

    for (int i = 0; i < 8; i++)
    {
        this->humanPos[i] = humanPos[i];
    }
    pos.x = 0;
    pos.y  = 0;
    pos.w  = 1024;
    pos.h = 786;

    btn = new Button;
    btn->SetButtonSprite(false);
    btn->setPosition(280,80);
    btn->SetWidth(315*1.5,70*0.8);
    btn->setText("SEE PATIENT");
    btn->word->ReduceSize(0.8);

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

     if(!manualShow)
     {
         btn->Show(renderer);
     }
     SDL_SetRenderDrawColor( renderer, 2,85,89,0 );
    SDL_RenderDrawRect(renderer,upperRect);
    SDL_RenderFillRect(renderer,upperRect);
    points->Show(renderer);
}

void Hospital::HandleEvents(SDL_Event* e,Screens_Node& node)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if( btn->WithinRegion(hoverX,hoverY)==true)
    {
        btn->Hover();
        if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        {
            node.cur_screen = new Manual(235,70);
            node.prev_screen = this;
            node.prev_backable = true;
            node.prev_updatable = true;
            manualShow = true;
        }
    }
    else
    {
        btn->SetSprite2(123);
    }

}

void Hospital::Update(int frame)
{

}

Hospital :: ~Hospital()
{

}

 bool Hospital :: AddHuman(Human* human)
 {
     bool allowAppend = false;
     if(humans.GetLength()<=8) //only 8 humans allowed in hospital
     {
         allowAppend = true;
     }
     if(allowAppend==true)
     {
         humans.Append(human);

         for(int i = 0; i<humans.GetLength(); i++)
         {
             humans.GiveItem(i)->UpdatePos(humanPos[i],570);
         }
     }
     return allowAppend;
 }

void Hospital :: LeaveHuman(Human* human)
{
      humans.Pop();
      for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->UpdatePos(humanPos[i],570);
     }
}

