#pragma once
#include <SDL.h>
#include <SDL_image.h>

class Texture
{

private:
    SDL_Texture * texture; // The actual hardware texture
    static Texture* instance;

public :
    Texture ();
    static Texture* GetInstance(); // Initializes variables
    void free ();
    ~Texture (); // Deallocates memory
    void render ( int serial, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the sprite at given serial no, where clip is located.
    void render ( char character, SDL_Renderer * gRenderer , SDL_Rect * clip = NULL ); // Renders the given character, where the clip is located.
    bool loadMedia(SDL_Renderer* gRenderer); //Loads the texture file, i.e the sprite sheet
    void ChangeOpactiy(int val);



};
