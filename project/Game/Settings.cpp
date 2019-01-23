#include "Settings.h"

Setting::Setting(Screens* prevScreen, bool back, bool show, bool update, int factor):Menu(2,185,640,true, prevScreen, back, show, update, factor)  //calling menus constructor that is constructing 2 buttons horizontally
{
    settingPos = new SDL_Rect;
    settingSliderPos1 = new SDL_Rect;
    settingSliderPos = new SDL_Rect;
    noVolumePos1 = new SDL_Rect;
    noVolumePos = new SDL_Rect;
    fullVolumePos = new SDL_Rect;
    noBrightnessPos1 = new SDL_Rect;
    noBrightnessPos = new SDL_Rect;
    fullBrightnessPos = new SDL_Rect;

    settingPos->x= 110;
    settingPos->y= 390;
    settingPos->w= 800;
    settingPos->h= 380;  //settings

    settingscancelPos.x = 860;
    settingscancelPos.y = 400;
    settingscancelPos.w = 35;
    settingscancelPos.h = 35;    //for cancel button

    settingSliderPos->x= 500-5;       //for slider bases
    settingSliderPos->y= settingPos->y+85;
    settingSliderPos->w= 397*0.8;
    settingSliderPos->h= 52*0.8;

    settingSliderPos1->x= 500-5;
    settingSliderPos1->y= settingPos->y+160;
    settingSliderPos1->w= 397*0.8;
    settingSliderPos1->h= 52*0.8;

    noVolumePos->x = settingSliderPos->x -50;
    noVolumePos->y = settingSliderPos->y +5;
    noVolumePos->w = 30 * 0.8;
    noVolumePos->h = 37 * 0.8;

    noVolumePos1->x = settingSliderPos->x+settingSliderPos->w +15;
    noVolumePos1->y = noVolumePos->y;
    noVolumePos1->w = 30 * 0.8;
    noVolumePos1->h = 37 * 0.8;

    fullVolumePos->x = noVolumePos1->x+30;
    fullVolumePos->y = noVolumePos1->y;
    fullVolumePos->w =  noVolumePos1->w;
    fullVolumePos->h =  noVolumePos1->h;

    noBrightnessPos->x = settingSliderPos1->x -50;
    noBrightnessPos->y = settingSliderPos1->y +5;
    noBrightnessPos->w = 38 * 0.8;
    noBrightnessPos->h = 38 * 0.8;

    noBrightnessPos1->x = settingSliderPos1->x+settingSliderPos1->w +30;
    noBrightnessPos1->y =noBrightnessPos->y;
    noBrightnessPos1->w = 38 * 0.8;
    noBrightnessPos1->h = 38 * 0.8;

    fullBrightnessPos->x = noBrightnessPos1->x -13;
    fullBrightnessPos->y = noBrightnessPos->y - 10;
    fullBrightnessPos->w = 67 * 0.8;
    fullBrightnessPos->h = 67 * 0.8;

    buttonText[0]= "SAVE";
    buttonText[1] = "RESET";
    cancelBtn = new CancelButton(settingscancelPos);  //making a cancel button
    slider = new Slider[2]; //slider for volume and brightness

    Menu::SetText(buttonText);
    word = new Word[3];  // 3 because 3 words, settings, volume and brightness

    word[0].SetText("SETTINGS");
    word[0].SetPosition(settingPos->x+290,settingPos->y+25);

    word[1].SetText("VOLUME");
    word[1].SetPosition(settingPos->x+10,settingPos->y+85);

    word[2].SetText("BRIGHTNESS");
    word[2].SetPosition(settingPos->x+10,settingPos->y+160);

    float bright;
    ifstream myfile ("setting.txt");
    if (myfile.is_open())
    {
        while (!myfile.eof())
        {
            myfile>>bright;
            int sliderResetPos = (bright *495) + settingSliderPos1->x;
            slider[0].setPosition(sliderResetPos,settingPos->y+85);
            slider[1].setPosition(sliderResetPos,settingPos->y+160);

        }
        myfile.close();
    }

}


void Setting::Show(SDL_Renderer* gRenderer)
{
    Screens::Show(gRenderer);
    texture = Texture::GetInstance(gRenderer);
    texture->Render(59,gRenderer,settingPos);
    texture->Render(60,gRenderer,settingSliderPos);
    texture->Render(60,gRenderer,settingSliderPos1);
    texture->Render(55,gRenderer,noVolumePos);
    texture->Render(55,gRenderer,noVolumePos1);
    texture->Render(56,gRenderer,fullVolumePos);
    texture->Render(57,gRenderer,noBrightnessPos);
    texture->Render(57,gRenderer,noBrightnessPos1);
    texture->Render(58,gRenderer,fullBrightnessPos);
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
    Screens::Update(frame);
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
                curScreen = prevScreen;
                delete this;
            }
            else if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                ofstream myfile;
                myfile.open ("setting.txt");
                float bright = (slider[1].GetSliderPosX() - settingSliderPos1->x)/495.0;
                if (bright > 0)
                {
                    myfile << bright;
                    myfile << "\n";
                }
                myfile.close();


            }

            else if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                float bright;
                ifstream myfile ("setting.txt");
                if (myfile.is_open())
                {
                    while (!myfile.eof())
                    {
                        myfile>>bright;
                        int sliderResetPos = (bright *495) + settingSliderPos1->x;
                        slider[0].SetSliderPosX(sliderResetPos);
                        slider[1].SetSliderPosX(sliderResetPos);

                    }
                    myfile.close();
                }

                  else cout << "Unable to open file";

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
        else if ((e->type == SDL_MOUSEBUTTONUP) && (e->button.button == SDL_BUTTON_LEFT))
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
           if ((e->type == SDL_MOUSEBUTTONDOWN)&& (e->button.button == SDL_BUTTON_LEFT))
            {
                //slider[i].Click();
                slider[i].SetMouseClicked(true);

            }
            else if ((e->type == SDL_MOUSEBUTTONUP)&& (e->button.button == SDL_BUTTON_LEFT))
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
                slider[i].SetSliderPosX(hoverX);

               if (slider[i].GetSliderPosX() > 780)
                {

                    slider[i].SetSliderPosX(780);
                }

                else if (slider[i].GetSliderPosX() <500)
                {

                    slider[i].SetSliderPosX(500);
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
    delete settingPos;
    delete settingSliderPos1;
    delete settingSliderPos;
}
