#include "Settings.h"

Setting::Setting():Menu(2,175,630,true)  //calling menus constructor that is constructing 2 buttons horizontally
{
    settingPos.x= 110;
    settingPos.y= 380;
    settingPos.w= 800;
    settingPos.h= 350;  //settings

    settingscancelPos.x = 850;
    settingscancelPos.y = 400;
    settingscancelPos.w = 35;
    settingscancelPos.h = 35;    //for cancel button

    settingSliderPos.x= 500-5;       //for slider bases
    settingSliderPos.y= settingPos.y+75;
    settingSliderPos.w= 397*0.8;
    settingSliderPos.h= 52*0.8;

    settingSliderPos1.x= 500-5;
    settingSliderPos1.y= settingPos.y+150;
    settingSliderPos1.w= 397*0.8;
    settingSliderPos1.h= 52*0.8;

    buttonText[0]= "SAVE";
    buttonText[1] = "RESET";
    cancelBtn = new CancelButton(settingscancelPos);  //making a cancel button
    slider = new Slider[2]; //slider for volume and brightness

    Menu::SetText(buttonText);
    word = new Word[3];  // 3 because 3 words, settings, volume and brightness

    word[0].SetText("SETTINGS");
    word[0].SetPosition(settingPos.x+290,settingPos.y+15);

    word[1].SetText("VOLUME");
    word[1].SetPosition(settingPos.x+10,settingPos.y+75);

    word[2].SetText("BRIGHTNESS");
    word[2].SetPosition(settingPos.x+10,settingPos.y+150);

    slider[0].setPosition(500,settingPos.y+75);
    slider[1].setPosition(500,settingPos.y+150);
}

void Setting::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(59,gRenderer,&settingPos);
    texture->Render(60,gRenderer,&settingSliderPos);
    texture->Render(60,gRenderer,&settingSliderPos1);
    Menu::Show(gRenderer);
    for(int i=0; i<3; i++)      //rendering all words i.e settings,volume,brightness
    {
         word[i].Show(gRenderer);
    }

    cancelBtn->Show(gRenderer);

    for(int i=0; i<2; i++)      //rendering all words i.e settings,volume,brightness
    {
         slider[i].Show(gRenderer);
    }

}

void Setting::Update(int frame)
{

}



void Setting::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::HoverClick(e);   //for button
    Click(e);       //for cancel and slider


    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if (cancelBtn->WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = node.prev_screen;
                node.prev_screen = this;
                node.prev_backable = false;  //cancel screen will close and main menu  screen will open
            }

            if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                slider[0].sliderPos.x =500;
            }
        }
    }

}



void Setting::Click(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

    //for cancel button
    if( cancelBtn->WithinRegion(hoverX,hoverY)==true)
    {
        if (e->type == SDL_MOUSEBUTTONDOWN && e->button.button == SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
        }
        else if (e->type == SDL_MOUSEBUTTONUP && e->button.button == SDL_BUTTON_LEFT)
        {
            SetMouseClicked(false);
            cancelBtn->diffStateBtn=54;
        }
        else
        {
            cancelBtn->Hover();
        }
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

    //for slider
    for(int i=0; i<2; i++)
    {
       if (slider[i].WithinSliderRegion(hoverX,hoverY))
       {
           if (e->type == SDL_MOUSEBUTTONDOWN && (e->button.button == SDL_BUTTON_LEFT) )
            {
                //slider[i].Click();
                slider[i].SetMouseClicked(true);

            }
            else if (e->type == SDL_MOUSEBUTTONUP && (e->button.button == SDL_BUTTON_LEFT))
            {
                slider[i].SetMouseClicked(false);
                //slider[i].diffStateBtn=61;
            }
       }
       else
       {
           if (e->type == SDL_MOUSEBUTTONUP)
           {
               slider[i].SetMouseClicked(false);
               //slider[i].Hover();

           }

           if (slider[i].GetMouseClicked())
           {
                slider[i].sliderPos.x = hoverX;

               if (slider[i].sliderPos.x > 780)
                {

                    slider[i].sliderPos.x= 780;
                }

                else if (slider[i].sliderPos.x <500)
                {

                    slider[i].sliderPos.x= 500;
                }

           }
       }
    }

}
Setting::~Setting()
{

    delete cancelBtn;
    delete []slider;
    delete [] word;
}
