#include "Alert.h"
#include "EndMenu.h"

Alert::Alert()
{
    timerSprite = 27;
    newScreenIter = 0;
    alertPos = new SDL_Rect;
    alertPos->x = 500;
    alertPos->y = 4;
    alertPos->w = 30;
    alertPos->h = 30;

    timerPos = new SDL_Rect;
    timerPos->x = 540;
    timerPos->y = 4;
    timerPos->w = 60;
    timerPos->h = 60;

    word = new Word[1];
    word[0].SetText("H U M A N   D I E D");
    word[0].ReduceSize(3);
    word[0].SetPosition(250,600);
}
void Alert::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(38, gRenderer, alertPos);
    texture->Render(int(timerSprite), gRenderer, timerPos);
    if(int(timerSprite)==34)
    {
        word[0].Show(gRenderer);

    }
    newScreenIter++;

}

void Alert::Update(double a)
{
    this->timerSprite = a;

    if (timerSprite>26 && timerSprite<34)
        timerSprite += 0.001;



}
double Alert::GetTimerSprite()
{
    return timerSprite;
}
void Alert::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    SDL_Delay(4000);
    node.cur_screen = new EndMenu;
    node.prev_screen = node.cur_screen;
    node.prev_backable = false;
    node.prev_updatable = false;



}

Alert::~Alert()
{
    delete alertPos;
    delete timerPos;
    delete[] word;
}
