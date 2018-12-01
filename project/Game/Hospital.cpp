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
    //manual = new Manual(235,70);
    //manual->SetPosition(235,70);

    btn = new Button;
    //myQ.Append(btn);
    btn->SetButtonSprite(false);
    btn->setPosition(280,80);
    btn->SetWidth(315*1.5,70*0.8);
    btn->setText("SEE PATIENT");
    btn->word->ReduceSize(0.8);



    manualShow = false;


    //Human* humanPtr;
//    humanPtr = new Human(340,570);
  //  humans.push_back(humanPtr);
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

