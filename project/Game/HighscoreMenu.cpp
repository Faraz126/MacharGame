#include "HighscoreMenu.h"

Highscore::Highscore()
{
    highscorePos = new SDL_Rect;
    highscorePos->x = 110;
    highscorePos->y = 390;
    highscorePos->w = 800;
    highscorePos->h = 390;

    highscoreCancelPos.x = 860;
    highscoreCancelPos.y = 400;
    highscoreCancelPos.w = 35;
    highscoreCancelPos.h = 35;

    cancelBtn = new CancelButton(highscoreCancelPos);

}

void Highscore::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 2,85,89,0 );
    SDL_RenderDrawRect(gRenderer,highscorePos);
    SDL_RenderFillRect(gRenderer,highscorePos);
    cancelBtn->Show(gRenderer);

}

void Highscore::Update(int a)
{

}

void Highscore::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    ClickAndHover(e);       //for cancel


    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP )
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if (cancelBtn->WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = node.prev_screen;
                node.prev_screen = this;
                node.prev_backable = false;  //highscore screen will close and main menu  screen will open
            }
        }
    }
}
void Highscore::ClickAndHover(SDL_Event* e)
{
    int hoverX = e->button.x;
    int hoverY = e->button.y;

    //for cancel button states
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
}

Highscore::~Highscore()
{
    delete highscorePos;
    delete cancelBtn;
}


