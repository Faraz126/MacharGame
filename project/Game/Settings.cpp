#include "Settings.h"

Setting::Setting():Menu(2,175,630,true)  //calling menus constructor that is constructing 2 buttons horizontally
{
    settingPos = new SDL_Rect;
    settingPos->x= 110;
    settingPos->y= 380;
    settingPos->w= 800;
    settingPos->h= 350;  //settings

    settingscancelPos.x = 850;
    settingscancelPos.y = 400;
    settingscancelPos.w = 35;
    settingscancelPos.h = 35;    //for cancel button


    buttonText[0]= "SAVE";
    buttonText[1] = "RESET";
    cancelBtn = new CancelButton(settingscancelPos);  //making a cancel button
    slider = new Slider();

    Menu::SetText(buttonText);
    word = new Word[3];  // 3 because 3 words, settings, volume and brightness

    word[0].SetText("SETTINGS");
    word[0].SetPosition(settingPos->x+290,settingPos->y+15);

    word[1].SetText("VOLUME");
    word[1].SetPosition(settingPos->x+10,settingPos->y+75);

    word[2].SetText("BRIGHTNESS");
    word[2].SetPosition(settingPos->x+10,settingPos->y+150);




}

void Setting::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);   //settings ka rectangle wala box
    SDL_RenderFillRect(gRenderer,settingPos);
    Menu::Show(gRenderer);
    for(int i=0; i<3; i++)      //rendering all words i.e settings,volume,brightness
    {
         word[i].Show(gRenderer);
    }

    cancelBtn->Show(gRenderer);
    slider->Show(gRenderer);


}

void Setting::Update(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::Hover(e);  //for button
    Menu::Click(e);   //for button
    Click(e);       //for cancel and slider
    Hover(e);

    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if (cancelBtn->WithinCancelRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new MainMenu;
                node.prev_screen = this;
                node.prev_backable = false;  //cancel screen will close and main menu  screen will open
            }
        }
    }
}

void Setting::Click(SDL_Event* e)
{
    int hoverX = e->button.x;  //for cancel button click
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEMOTION)
    {
        if(e->button.button == SDL_BUTTON_LEFT)
        {
                SetMouseClicked(true);
                if( cancelBtn->WithinCancelRegion(hoverX,hoverY)==true)
                {
                    cancelBtn->Click();
                }
                if (slider->WithinSliderRegion(hoverX,hoverY)==true)
                {
                    slider->Click();
                    if (!slider->GetMouseClicked())
                    {
                        slider->SetMouseClicked(true);
                    }
                }
                if (cancelBtn->WithinCancelRegion(hoverX,hoverY)==false)
                {
                    cancelBtn->diffStateBtn=4;
                }
                if (slider->WithinSliderRegion(hoverX,hoverY)==false)
                {
                    slider->diffStateBtn=0;
                }
                if (slider->GetMouseClicked())
                {
                    slider->sliderPos.x = hoverX;
                }

        }

    }

    if (e->type == SDL_MOUSEBUTTONUP)
    {
        SetMouseClicked(false);
        slider->SetMouseClicked(false);
    }



}

void Setting::Hover(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;
    if(e->type == SDL_MOUSEMOTION)
    {
        if( cancelBtn->WithinCancelRegion(hoverX,hoverY)==true)
        {
            cancelBtn->Hover();
        }

        else if( slider->WithinSliderRegion(hoverX,hoverY)==true)
        {
            slider->Hover();
            if (slider->GetMouseClicked()==true)
            {
                std::cout<<"please";
                sliderPos.x +=2;

            }

        }
        else if (slider->WithinSliderRegion(hoverX,hoverY)==false)
        {
            slider->diffStateBtn=0;
        }

        else if (cancelBtn->WithinCancelRegion(hoverX,hoverY)==false)
        {
            cancelBtn->diffStateBtn=4;
        }








    }

}
