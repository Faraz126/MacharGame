#include "Hospital.h"
#include "Manual.h"
#include <random>
#include <iostream>

using namespace std;

Hospital:: Hospital()
{
    int humanPos[8] = {310,400,495,580,675,760,860,945};// position of humans sitting on chairs
    popped = NULL;

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
            if(humans.GetLength()>0)
            {
                node.cur_screen = new Manual(235,70,this);
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = true;
                humans.GiveItem(0)->UpdatePos(350,170);
            }
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
    delete btn;
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
         for(int i = 0; i<20; i++)
        {
            (*Score::GetInstance())++;
        }

         for(int i = 0; i<humans.GetLength(); i++)
         {
             humans.GiveItem(i)->UpdatePos(humanPos[i],465);
         }
     }
     popped = humans.GiveItem(0);
     cout<<(humans.GiveItem(0)->GetDisease())<<endl;
     return allowAppend;
 }

void Hospital :: LeaveHuman(Human* human)
{
      humans.Pop();
      for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->UpdatePos(humanPos[i],465);
     }
}

void Hospital :: LeaveHuman()
{
      humans.Pop();
      for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->UpdatePos(humanPos[i],465);
     }
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
