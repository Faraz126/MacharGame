#include "Settings.h"

Setting::Setting():Menu(2,175,600,true)
{
    settingPos = new SDL_Rect;
    settingPos->x= 110;
    settingPos->y= 380;
    settingPos->w= 800;
    settingPos->h= 350;  //settings

    buttonText[0]= "SAVE";
    buttonText[1] = "RESET";


    cancelBtn = new CancelButton();

    Menu::SetText(buttonText);
    word = new Word[3];

    word[0].SetText("SETTINGS");
    word[0].SetPosition(settingPos->x+290,settingPos->y+15);

    word[1].SetText("VOLUME");
    word[1].SetPosition(settingPos->x+10,settingPos->y+65);

    word[2].SetText("BRIGHTNESS");
    word[2].SetPosition(settingPos->x+10,settingPos->y+135);


}

void Setting::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
    SDL_RenderFillRect(gRenderer,settingPos);
    Menu::Show(gRenderer);
    word->Show(gRenderer);
    word[1].Show(gRenderer);
    word[2].Show(gRenderer);
}

void Setting::Update(SDL_Event* e, Screens_Node& node)
{

}

