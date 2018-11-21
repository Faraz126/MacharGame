#include "Closing.h"

Closing::Closing()
{
    closingPos = new SDL_Rect;
    closingPos->x= 0;
    closingPos->y= 0;
    closingPos->w= 1240;
    closingPos->h= 786;


}

void Closing::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
    SDL_RenderFillRect(gRenderer,closingPos);
    closMove->Show(gRenderer);


}
void Closing::Update(SDL_Event*, Screens_Node&)
{

}

Closing::~Closing()
{
    delete closingPos;
    delete [] word;
}

