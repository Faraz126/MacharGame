#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"
#include "MainMenu.h"
#include "Texture.h"
#include "House.h"
#include "time.h"
#include <random>
#include"Outdoor.h"


using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 786;

//Starts up SDL and creates window
//bool init();

//Loads media


void close();

//Loads individual image as texture

//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

bool init()
{
	//Initialization mouseClicked
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if( !SDL_SetHint( SDL_HINT_RENDER_SCALE_QUALITY, "1" ) )
		{
			printf( "Warning: Linear texture filtering not enabled!" );
		}

		//Create window
		gWindow = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
        if( gWindow == NULL )
        {
            printf( "Window could not be created! SDL Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Create renderer for window
            gRenderer = SDL_CreateRenderer( gWindow, -1, SDL_RENDERER_ACCELERATED );
            if( gRenderer == NULL )
            {
                printf( "Renderer could not be created! SDL Error: %s\n", SDL_GetError() );
                success = false;
            }
            else
            {
                //Initialize renderer color
                SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );

                //Initialize PNG loading
                int imgFlags = IMG_INIT_PNG;
                if( !( IMG_Init( imgFlags ) & imgFlags ) )
                {
                    printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
                    success = false;
                }
            }
        }

    }
	return success;
}

bool loadMedia()
{
	//Loading success mouseClicked
	bool success = true;

	//Nothing to load
	return success;
}

void close()
{
	//Destroy window
	SDL_DestroyRenderer( gRenderer );
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}


int main( int argc, char* args[] )
{
	//Start up SDL and create window

    srand(time(nullptr));

	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
        bool quit = false;

        Texture::GetInstance(gRenderer); //Loads the sprite sheet into texture.


        SDL_Event e;
        Texture::GetInstance(gRenderer);
        Screens_Node screen;


        screen.cur_screen = new MainMenu; //starting with main menu
        int frame = 0;


        while (!quit)
        {
            screen.cur_screen->Update(frame);
            while (SDL_PollEvent(&e))
            {
                if( e.type == SDL_QUIT ) quit = true;
                screen.cur_screen->HandleEvents(&e,screen);
            }

            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            if (screen.prev_screen != 0 && !screen.prev_backable)
            {
                delete screen.prev_screen;
                screen.prev_screen = 0;
            }
            else if (screen.prev_backable != 0 && screen.prev_screen != 0)

            {
                screen.prev_screen->Show(gRenderer);
                if (screen.prev_updatable)
                {
                    screen.prev_screen->Update(frame);
                }
            }
            //screen.cur_screen->Update(&e,screen);
            screen.cur_screen->Show(gRenderer); //drawing the current screen on the SDL window
            SDL_RenderPresent( gRenderer );
            frame++;
        }
	}

	close();

	return 0;
}
