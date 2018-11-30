#include "SplashScreen.h"

SplashScreen::SplashScreen()
{
    pos = new SDL_Rect;
    pos->x = 0;
    pos->y = 0;
    pos->w = 1240;
    pos->h = 786;
}

void SplashScreen::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    double iterFadeIn = 0;
    while(iterFadeIn<255)
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        texture->ChangeOpactiy((int)iterFadeIn);
        texture->Render(113,gRenderer,pos);
        iterFadeIn += 0.1;
        SDL_RenderPresent( gRenderer );
    }
     while(iterFadeIn<5000 && iterFadeIn>0)
    {
        SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
        SDL_RenderClear( gRenderer );
        texture->ChangeOpactiy((int)iterFadeIn);
        texture->Render(113,gRenderer,pos);
        iterFadeIn -= 0.1;
        SDL_RenderPresent( gRenderer );
    }
    texture->ChangeOpactiy(255);



}

SplashScreen::~SplashScreen()
{
    delete pos;
}
