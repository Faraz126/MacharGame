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
#include "GLOBALS.h"
#include"Hospital.h"
#include "Plant.h"
#include <fstream>
#include <sstream>
#include "SplashScreen.h"
#include <SDL_mixer.h>



using namespace std;

const int SCREEN_WIDTH = 1024;
const int SCREEN_HEIGHT = 786;

//Starts up SDL and creates window
//bool init();

//Loads media


void close();

//Loads individual image as texture
SDL_Renderer* gRenderer;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;
Mix_Music *gMusic = NULL;


bool init()
{
	//Initialization mouseClicked
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO | SDL_INIT_AUDIO ) < 0 )
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
		gWindow = SDL_CreateWindow( "Rook Thaam", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
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

                if( Mix_OpenAudio( 44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0 )
                {
                    printf( "SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError() );
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

    gMusic = Mix_LoadMUS( "m.wav" );
    if( gMusic == NULL )
    {
        printf( "Failed to load beat music! SDL_mixer Error: %s\n", Mix_GetError() );
        success = false;
    }

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

//        cout << loadMedia();
        Texture::GetInstance(gRenderer); //Loads the sprite sheet into texture.

        SDL_Event e;

        Screens_Node screen;

        /*
        SplashScreen splash;
        splash.Show(gRenderer);
        */

        //screen.cur_screen = new MainMenu; //starting with main menu
        Screens::Initiate();
        int frame = 0;


        while (!GAME_QUIT)
        {

            //screen.cur_screen->Update(frame);
            ifstream myfile;
            myfile.open("setting.txt");
            float output;
            if (myfile.is_open())
            {
                while (!myfile.eof())
                {
                    myfile >> output;
                    SDL_SetWindowBrightness(gWindow,output);
                }
            }
            myfile.close();

            Screens::GetCurrent()->Update(frame);
            while (SDL_PollEvent(&e))
            {
                if( e.type == SDL_QUIT ) GAME_QUIT = true;
                //screen.cur_screen->HandleEvents(&e,screen);
                Screens::GetCurrent()->HandleEvents(&e, screen);
            }
            /*
            if( Mix_PlayingMusic() == 0 )
            {
            //Play the music
                Mix_PlayMusic( gMusic, -1 );
            }
            //If music is being played
            else
            {

                //If the music is paused
                if( Mix_PausedMusic() == 1 )
                {
                //Resume the music
                    //Mix_ResumeMusic();
                }
                //If the music is playing
                else
                {
                //Pause the music
                    //Mix_PauseMusic();
                }
            }

            */

            SDL_SetRenderDrawColor( gRenderer, 0xFF, 0xFF, 0xFF, 0xFF );
            SDL_RenderClear( gRenderer );

            Screens::GetCurrent()->Show(gRenderer);

            //screen.cur_screen->Update(&e,screen);
            ///screen.cur_screen->Show(gRenderer); //drawing the current screen on the SDL window
            SDL_RenderPresent( gRenderer );
            Texture::GetInstance()->SoundRender(3);
            frame++;
        }
        delete Texture::GetInstance(gRenderer);
	}
	close();

	return 0;
}
