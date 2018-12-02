#include "Nets.h"


Nets::Nets()
{
    price.SetPaisa(250);
    name = "Window Repair";
    spriteNum = 13;
}

void Nets::Apply(House* house)
{
//    int n;
//    Entrance** windows = house->GetEntrance(n);
//    for(int i = 0;i < n;i++)
//    {
//        windows[i]->SetTimeCovered();   // Window State should be an int so that it keeps being updated when net is applied
//    }
}


Nets::~Nets()
{

}
