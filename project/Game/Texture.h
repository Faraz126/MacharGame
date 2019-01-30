#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <iostream>

class Texture //agar nahi hoti toh store karte k har object kahan par hai
{

private:
    SDL_Texture* texture;
    SDL_Rect clipFromTexture;
    Mix_Music *gMusic;
    Mix_Chunk *gScratch;

    static Texture* instance; //pointer to hold the instance.
    bool LoadMedia(SDL_Renderer* gRenderer); //Loads the texture file, i.e the sprite sheet
    void SetRect(int); //to decide the position of serial no object on sprite sheet
    void SetRect(char); // to decide the position of character on sprite sheet
    void SetSound(int);

public :
    Texture (SDL_Renderer*);
    static Texture* GetInstance(SDL_Renderer*); // Initializes variables
    static Texture* GetInstance();
    void Free ();
    ~Texture (); // Deallocates memory
    void Render ( int serial, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the sprite at given serial no, where clip is located.
    void Render ( char character, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the given character, where the clip is located.
    void RenderBack(int serial, SDL_Renderer* renderer, SDL_Rect* clip1, SDL_Rect* clip2, bool flipped = false);
    void ChangeOpactiy(int val);
    void RenderFlipped(int , SDL_Renderer*, SDL_Rect*);
    void SoundRender (int);
    void SoundRenderChunk (int);



};
