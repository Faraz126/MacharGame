#include "Settings.h"

Setting::Setting():Menu(2,175,630,true)  //calling menus constructor that is constructing 2 buttons horizontally
{
    settingPos = new SDL_Rect;
    settingPos->x= 110;
    settingPos->y= 380;
    settingPos->w= 800;
    settingPos->h= 350;  //settings

    SettingscancelPos.x = 880;
    SettingscancelPos.y = 400;
    SettingscancelPos.w = 35;
    SettingscancelPos.h = 35;    //for cancel button


    buttonText[0]= "SAVE";
    buttonText[1] = "RESET";
    cancelBtn = new CancelButton();  //making a cancel button

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
    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
    SDL_RenderFillRect(gRenderer,settingPos);
    Menu::Show(gRenderer);
    for(int i=0; i<3; i++)
    {
         word[i].Show(gRenderer);
    }
    cancelBtn->Render(gRenderer);


}

void Setting::Update(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::Hover(e);
    Menu::Click(e);
}

