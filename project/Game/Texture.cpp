#include "Texture.h"



Texture* Texture::instance = 0;


Texture::Texture(SDL_Renderer* renderer)
{
    this->texture = 0;
    LoadMedia(renderer);
}

Texture* Texture::GetInstance(SDL_Renderer* renderer) //static method.
{
    if (Texture::instance == 0)
    {
        Texture::instance = new Texture(renderer);
    }
    return instance;
}

Texture* Texture::GetInstance()
{
    if (instance != nullptr)
    {
        return instance;
    }
    return nullptr;
}

void Texture::Free()
{
    if (this->texture != 0)
    {
        SDL_DestroyTexture(this->texture);
        this->texture = 0;
    }
}

Texture::~Texture()
{
    Free();
}

bool Texture::LoadMedia(SDL_Renderer* renderer)
{
    SDL_Texture * newTexture = NULL ;
    // Load image at specified path
    SDL_Surface * loadedSurface = IMG_Load ( "spriteSheet.png");

    if ( loadedSurface != NULL )
    {
        // Create texture from surface pixels
        newTexture = SDL_CreateTextureFromSurface (renderer, loadedSurface );
        // Get rid of old loaded surface
        texture = newTexture;
    }

    SDL_FreeSurface( loadedSurface );
    return texture != NULL;
}

void Texture::Render ( int serial, SDL_Renderer * gRenderer , SDL_Rect * clip) //Highlight
{
    /*
    serial no = No. of object to be drawn on sprite sheet
    gRenderer = screen to render to
    clip = the position to draw into
    */
    SetRect(serial); //region de rahe hain
    SDL_RenderCopy(gRenderer, this->texture,&clipFromTexture, clip);

}

void Texture::Render(char character, SDL_Renderer* gRenderer, SDL_Rect * clip) //Highlight
{
    /*
    character = character to be drawn on sprite sheet
    gRenderer = screen to render to
    clip = the position to draw into
    */
    SetRect(character);
    SDL_RenderCopy(gRenderer, this->texture, &clipFromTexture, clip);
}

void Texture::SetRect(int n)
{
    /*
    hardcoded position of objects on sprite sheet
    */
    switch (n)
    {
    case 0:
        clipFromTexture.x = 0;
        clipFromTexture.y = 0;
        clipFromTexture.h = 102;
        clipFromTexture.w = 571;
        break;
    case 1:
        clipFromTexture.x = 0;
        clipFromTexture.y = 155;
        clipFromTexture.h = 102;
        clipFromTexture.w = 571;
        break;
    case 2:
        clipFromTexture.x = 0;
        clipFromTexture.y = 310;
        clipFromTexture.h = 102;
        clipFromTexture.w = 571;
        break;
    case 3:
        clipFromTexture.x = 0;
        clipFromTexture.y = 505;
        clipFromTexture.h = 786;
        clipFromTexture.w = 1024;
        break;
    case 4:
        clipFromTexture.x = 608;
        clipFromTexture.y = 111;
        clipFromTexture.h = 340;
        clipFromTexture.w = 435;
        break;
    case 5:
        clipFromTexture.x = 1043;
        clipFromTexture.y = 111;
        clipFromTexture.h = 340;
        clipFromTexture.w = 435;
        break;
    case 6:
        clipFromTexture.x = 1478;
        clipFromTexture.y = 111;
        clipFromTexture.h = 340;
        clipFromTexture.w = 435;
        break;
    case 7:
        clipFromTexture.x = 1913;
        clipFromTexture.y = 111;
        clipFromTexture.h = 340;
        clipFromTexture.w = 435;
        break;
    case 8:
        clipFromTexture.x = 2348;
        clipFromTexture.y = 111;
        clipFromTexture.h = 340;
        clipFromTexture.w = 435;
        break;
    case 9:
        clipFromTexture.x = 1024;
        clipFromTexture.y = 505;
        clipFromTexture.w = 1025;
        clipFromTexture.h = 786;
        break;
    case 10:
        clipFromTexture.x = 2049;
        clipFromTexture.y = 504;
        clipFromTexture.w = 229;
        clipFromTexture.h = 298;
        break;
    case 11:
        clipFromTexture.x = 2278;
        clipFromTexture.y = 504;
        clipFromTexture.w = 229;
        clipFromTexture.h = 298;
        break;
    case 12:
        clipFromTexture.x = 2507;
        clipFromTexture.y = 504;
        clipFromTexture.w = 229;
        clipFromTexture.h = 298;
        break;
    case 13:
        clipFromTexture.x = 2048;
        clipFromTexture.y = 1181;
        clipFromTexture.w = 200;
        clipFromTexture.h = 110;
        break;
    case 14:
        clipFromTexture.x = 2247;
        clipFromTexture.y = 1117;
        clipFromTexture.w = 153;
        clipFromTexture.h = 174;
        break;

    case 15:
        clipFromTexture.x = 49;
        clipFromTexture.y = 1316;
        clipFromTexture.w = 178;
        clipFromTexture.h = 412;
        break;
    case 16:
        clipFromTexture.x = 281;
        clipFromTexture.y = 1318;
        clipFromTexture.w = 114;
        clipFromTexture.h = 410;
        break;
    case 17:
        clipFromTexture.x = 486;
        clipFromTexture.y = 1316;
        clipFromTexture.w = 104;
        clipFromTexture.h = 410;
        break;
    case 18:
        clipFromTexture.x = 666;
        clipFromTexture.y = 1315;
        clipFromTexture.w = 143;
        clipFromTexture.h = 413;
        break;
    case 19:
        clipFromTexture.x = 848;
        clipFromTexture.y = 1316;
        clipFromTexture.w = 178;
        clipFromTexture.h = 412;
        break;
    case 20:
        clipFromTexture.x = 1080;
        clipFromTexture.y = 1318;
        clipFromTexture.w = 114;
        clipFromTexture.h = 410;
        break;
    case 21:
        clipFromTexture.x = 1285;
        clipFromTexture.y = 1316;
        clipFromTexture.w = 104;
        clipFromTexture.h = 410;
        break;
    case 22:
        clipFromTexture.x = 1466;
        clipFromTexture.y = 1315;
        clipFromTexture.w = 142;
        clipFromTexture.h = 413;
        break;
    case 23:
        clipFromTexture.x = 1695;
        clipFromTexture.y = 1307;
        clipFromTexture.w = 83;
        clipFromTexture.h = 417;
        break;
    }


}

void Texture::SetRect(char c)
{
    /*
    derive the position of character on screen depending on the ascii of character
    */
    int ascii = c;
    int col = 0;
    if (ascii == 32) //for space
    {

    }
    else if (ascii >= 97) //for small letters
    {
        col = 1;
        ascii -= 97;

    }
    else if (ascii >= 65 && ascii <= 90) //for capital letters
    {
        ascii -= 65;
    }
    clipFromTexture.x = 625 + (ascii)*73;
    clipFromTexture.y = col*73;
    clipFromTexture.w = 73;
    clipFromTexture.h = 73;
}




