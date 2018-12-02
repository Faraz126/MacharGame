#include "SplashScreen.h"

SplashScreen::SplashScreen()
{

    pos.x = 0;
    pos.y = 0;
    pos.w = 1024;
    pos.h = 786;

    pos2.x = 1564;
    pos2.y = 6375;
    pos2.w= 1024;
    pos2.h = 786;
}

void SplashScreen::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    SDL_Event e;
    double iterFadeIn = 0;
    while(iterFadeIn<255)
    {
        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Quit();
            }
        }

        SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0 );
        SDL_RenderClear( gRenderer );
        texture->ChangeOpactiy((int)iterFadeIn);
        texture->RenderBack(1, gRenderer,&pos2, &pos);
        iterFadeIn += 0.1;
        SDL_RenderPresent( gRenderer );
    }
     while(iterFadeIn<5000 && iterFadeIn>0)
    {

        while(SDL_PollEvent(&e))
        {
            if (e.type == SDL_QUIT)
            {
                SDL_Quit();
            }
        }


        SDL_RenderClear( gRenderer );
        texture->ChangeOpactiy((int)iterFadeIn);
        texture->RenderBack(1, gRenderer,&pos2, &pos);
        iterFadeIn -= 0.1;
        SDL_RenderPresent( gRenderer );
    }
    texture->ChangeOpactiy(255);



}

SplashScreen::~SplashScreen()
{

}
