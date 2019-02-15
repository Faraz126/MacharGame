#include "Instructions.h"

Instructions::Instructions(Screens* screen, bool back): Screens(screen, back)
{
    sprites = new SDL_Rect[8];

    for (int i = 0; i < 8; i++)
    {
        sprites[i].x = 4150;
        sprites[i].y = 114 + (i*(947-114));
        sprites[i].w = 900;
        sprites[i].h = 699;
    }

    activeScreen = 0;
    left = {275,645,72,72};
    right = {665,645,72,72};

    pos.x = 50;
    pos.y = 50;
    pos.w = 1024-100;
    pos.h = 786 - 100;

    pos1.x = 0;
    pos1.y = 0;
    pos1.w = 1024;
    pos1.h = 786;


    //part of sprite clipped from spritesheet
    pos2.x = 0;
    pos2.y = 1805;
    pos2.w = 1024;
    pos2.h = 786;
}

void Instructions::Show(SDL_Renderer* gRenderer)
{
    Texture::GetInstance()->RenderBack(35, gRenderer, &pos2, &pos1);
    Texture::GetInstance()->RenderBack(1,gRenderer, &sprites[activeScreen], &pos);
    //SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);
    //SDL_SetRenderDrawColor( gRenderer, 2,85,89,0 );
    //SDL_RenderDrawRect(gRenderer,&left);
    //SDL_RenderDrawRect(gRenderer,&right);
}

void Instructions::HandleEvents(SDL_Event* e, Screens_Node&)
{
    if (e->type == SDL_MOUSEBUTTONDOWN)
    {
        int x = e->button.x;
        int y = e->button.y;

        if (Clickable::WithinRegion(left, x,y))
        {
            activeScreen--;
            if (activeScreen < 0)
            {
                activeScreen = 0;
            }
        }
        if (Clickable::WithinRegion(right, x,y))
        {
            activeScreen++;
            if (activeScreen > 7)
            {
                curScreen = new Outdoor(this, false);
            }

        }
    }
    if(e->key.keysym.sym == SDLK_ESCAPE && e->type == SDL_KEYUP)  //will open pause menu
    {
        curScreen = new Outdoor(this,false);




    }

}

void Instructions::Update(int)
{

}

Instructions::~Instructions()
{
    //dtor
}
