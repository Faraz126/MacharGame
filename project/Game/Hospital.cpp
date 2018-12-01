#include "Hospital.h"
#include <random>
#include <iostream>

using namespace std;

Hospital:: Hospital()
{
    int humanPos[8] = {310,400,495,580,675,760,860,945};

    for (int i = 0; i < 8; i++)
    {
        this->humanPos[i] = humanPos[i];
    }
    pos.x = 0;
    pos.y  = 0;
    pos.w  = 1024;
    pos.h = 786;

}

void Hospital::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(113, renderer, &pos);
    for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->Show(renderer);
     }
}

void Hospital::HandleEvents(SDL_Event* e,Screens_Node& node)
{

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
             humans.GiveItem(i)->UpdatePos(humanPos[i],460);
         }
     }
     return allowAppend;
 }

void Hospital :: LeaveHuman(Human* human)
{
      humans.Pop();
      for(int i = 0; i<humans.GetLength(); i++)
     {
         humans.GiveItem(i)->UpdatePos(humanPos[i],460);
     }
}

