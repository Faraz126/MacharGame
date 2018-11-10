#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Texture
{

private:
    SDL_Texture* texture;
    SDL_Rect clipFromTexture;
    static Texture* instance; //pointer to hold the instance.
    bool LoadMedia(SDL_Renderer* gRenderer); //Loads the texture file, i.e the sprite sheet
    void SetRect(int); //to decide the position of serial no object on sprite sheet
    void SetRect(char); // to decide the position of character on sprite sheet

public :
    Texture (SDL_Renderer*);
    static Texture* GetInstance(SDL_Renderer*); // Initializes variables
    void Free ();
    ~Texture (); // Deallocates memory
    void Render ( int serial, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the sprite at given serial no, where clip is located.
    void Render ( char character, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the given character, where the clip is located.
    void ChangeOpactiy(int val);



};
