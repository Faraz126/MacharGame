#include "Alert.h"
#include "EndMenu.h"

Alert::Alert()
{
    timerSprite = 0;
    alert = new SDL_Rect[9];

    alert[0].x = 2651;
    alert[0].y = 6375;
    alert[0].w = 83;
    alert[0].h = 93;

    alert[1].x = 2651+83;
    alert[1].y = 6375;
    alert[1].w = 83;
    alert[1].h = 93;

    alert[2].x = 2651 + 83 + 83;
    alert[2].y = 6375;
    alert[2].w = 83;
    alert[2].h = 93;

    alert[3].x = 2651;
    alert[3].y = 6375+93;
    alert[3].w = 83;
    alert[3].h = 93;

    alert[4].x = 2651 + 83;
    alert[4].y = 6375+93;
    alert[4].w = 83;
    alert[4].h = 93;

    alert[5].x = 2651+ 83 +83;
    alert[5].y = 6375+93;
    alert[5].w = 83;
    alert[5].h = 93;

    alert[6].x = 2651;
    alert[6].y = 6375+93+93;
    alert[6].w = 83;
    alert[6].h = 93;

    alert[7].x = 2651 + 83;
    alert[7].y = 6375+93+93;
    alert[7].w = 83;
    alert[7].h = 93;

    alert[8].x = 2651+ 83 +83;
    alert[8].y = 6375+93+93;
    alert[8].w = 83;
    alert[8].h = 93;

    //humanPtr = ptr;

    timerPos = new SDL_Rect;
    timerPos->x = 540;
    timerPos->y = 4;
    timerPos->w = 60;
    timerPos->h = 60;

    word = new Word[1];
    word[0].SetText("H U M A N   D I E D");
    word[0].ReduceSize(3);
    word[0].SetPosition(250,600);
    show = true;
}

void Alert::Show(SDL_Renderer* gRenderer, int timerSprite)
{
    texture = Texture::GetInstance(gRenderer);
    if (show)
    {
        texture->RenderBack(38, gRenderer, &alert[timerSprite], timerPos);
    }



}
/*
void Alert::Update(int frame)
{
    if (humanPtr->GetInfected() && humanPtr->GetTimeToDie > 0)
    {
        show = true;
        timerSprite = humanPtr->GetTimeToDie();

    }

}
*/
double Alert::GetTimerSprite()
{
    return timerSprite;
}
void Alert::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    SDL_Delay(4000);
    /*
    node.cur_screen = new EndMenu;
    node.prev_screen = node.cur_screen;
    node.prev_backable = false;
    node.prev_updatable = false;
    */


    //Screens::GetCurrent() = new EndMenu(this, back);



}

Alert::~Alert()
{
//    delete alertPos;
    delete timerPos;
    delete[] word;
}
