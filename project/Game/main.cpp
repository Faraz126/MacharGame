
#include <stdio.h>
#include <string>
#include "string.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>
#include "Screens.h"
#include "MainMenu.h"
#include "Screens_Node.h"
#include "Texture.h"
#include "House.h"
#include "time.h"
#include <random>

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
                    printf( "SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError() );
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
        Texture::GetInstance(gRenderer);
        SDL_Event e;
        Screens_Node screen;

        screen.cur_screen = new House; //starting with main menu



        while (!quit)
        {
            while (SDL_PollEvent(&e))
            {
                if( e.type == SDL_QUIT ) quit = true;
                if (e.type == SDL_MOUSEMOTION || e.type == SDL_MOUSEBUTTONDOWN)
                {
                    screen.cur_screen->MouseEvent(&e);
                }
             }
            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );
            screen.cur_screen->Show(gRenderer); //drawing the current screen on the SDL window
            SDL_RenderPresent( gRenderer );



        }



	}

    //std::cout << "@@@hello";
	//Free resources and close SDL
	close();

	return 0;
}
