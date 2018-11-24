#include "Texture.h"



Texture* Texture::instance = 0;


Texture::Texture(SDL_Renderer* renderer)
{
    this->texture = 0;
    clipFromTexture = SDL_Rect();
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

void Texture::RenderBack(int serial, SDL_Renderer* renderer, SDL_Rect* clip1, SDL_Rect* clip2)
{
    SetRect(serial);
    SDL_RenderCopyEx(renderer, this->texture, clip1, clip2,0.0,0,SDL_FLIP_NONE);
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
        clipFromTexture.x = 2248;
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
    case 24:
        clipFromTexture.x = 2426;
        clipFromTexture.y = 1091;
        clipFromTexture.w = 225;
        clipFromTexture.h = 92;
        break;
    case 25:
        clipFromTexture.x = 2415;
        clipFromTexture.y = 1212;
        clipFromTexture.w = 262;
        clipFromTexture.h = 104;
        break;
    case 26:
        clipFromTexture.x = 2696;
        clipFromTexture.y = 1130;
        clipFromTexture.w = 91;
        clipFromTexture.h = 145;
        break;
    case 27:
        clipFromTexture.x = 1844;
        clipFromTexture.y = 1340;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 28:
        clipFromTexture.x = 1946;
        clipFromTexture.y = 1340;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 29:
        clipFromTexture.x = 2048;
        clipFromTexture.y = 1340;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 30:
        clipFromTexture.x = 2150;
        clipFromTexture.y = 1340;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 31:
        clipFromTexture.x = 1844;
        clipFromTexture.y = 1582;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 32:
        clipFromTexture.x = 1946;
        clipFromTexture.y = 1582;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 33:
        clipFromTexture.x = 2048;
        clipFromTexture.y = 1582;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 34:
        clipFromTexture.x = 2150;
        clipFromTexture.y = 1582;
        clipFromTexture.w = 102;
        clipFromTexture.h = 192;
        break;
    case 35:
        clipFromTexture.x = 0;
        clipFromTexture.y = 1805;
        clipFromTexture.w = 1024*2.5;
        clipFromTexture.h = 786;
        break;
    case 36:
        clipFromTexture.x = 1025;
        clipFromTexture.y = 1805;
        clipFromTexture.w = 1024;
        clipFromTexture.h = 786;
        break;
    case 37:
        clipFromTexture.x = 1536;
        clipFromTexture.y = 1805;
        clipFromTexture.w = 1024;
        clipFromTexture.h = 786;
        break;
    case 38:
        clipFromTexture.x = 2283;
        clipFromTexture.y = 1577;
        clipFromTexture.w = 49;
        clipFromTexture.h = 31;
        break;
    case 39:
        clipFromTexture.x = 2283;
        clipFromTexture.y = 1657;
        clipFromTexture.w = 49;
        clipFromTexture.h = 31;
        break;
    case 40:
        clipFromTexture.x = 2283;
        clipFromTexture.y = 1737;
        clipFromTexture.w = 49;
        clipFromTexture.h = 31;
        break;
    case 41:
        clipFromTexture.x = 2368;
        clipFromTexture.y = 1636;
        clipFromTexture.w = 121;
        clipFromTexture.h = 117;
        break;
    case 42:
        clipFromTexture.x = 2368;
        clipFromTexture.y = 1364;
        clipFromTexture.w = 124;
        clipFromTexture.h = 40;
        break;
    case 43:
        clipFromTexture.x = 61;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 44:
        clipFromTexture.x = 502;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 45:
        clipFromTexture.x = 943;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 46:
        clipFromTexture.x = 1384;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 47:
        clipFromTexture.x = 1825;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 48:
        clipFromTexture.x = 61;
        clipFromTexture.y = 3052;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 49:
        clipFromTexture.x = 502;
        clipFromTexture.y = 3052;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 50:
        clipFromTexture.x = 943;
        clipFromTexture.y = 3052;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 51:
        clipFromTexture.x = 1384;
        clipFromTexture.y = 3052;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 52:
        clipFromTexture.x = 1825;
        clipFromTexture.y = 3052;
        clipFromTexture.w = 441;
        clipFromTexture.h = 346;
        break;
    case 53:
        clipFromTexture.x = 2282;
        clipFromTexture.y = 1351;
        clipFromTexture.w = 41;
        clipFromTexture.h = 44;
        break;
    case 54:
        clipFromTexture.x = 2344;
        clipFromTexture.y = 1351;
        clipFromTexture.w = 41;
        clipFromTexture.h = 44;
        break;
    case 55:
        clipFromTexture.x = 2286;
        clipFromTexture.y = 1454;
        clipFromTexture.w = 30;
        clipFromTexture.h = 37;
        break;
    case 56:
        clipFromTexture.x = 2350;
        clipFromTexture.y = 1454;
        clipFromTexture.w = 19;
        clipFromTexture.h = 37;
        break;
    case 57:
        clipFromTexture.x = 2399;
        clipFromTexture.y = 1453;
        clipFromTexture.w = 38;
        clipFromTexture.h = 38;
        break;
    case 58:
        clipFromTexture.x = 2458;
        clipFromTexture.y = 1429;
        clipFromTexture.w = 67;
        clipFromTexture.h = 67;
        break;
    case 59:
        clipFromTexture.x = 107;
        clipFromTexture.y = 3479;
        clipFromTexture.w = 743;
        clipFromTexture.h = 334;
        break;
    case 60:
        clipFromTexture.x = 103;
        clipFromTexture.y = 3890;
        clipFromTexture.w = 397;
        clipFromTexture.h = 52;
        break;
    case 61:
        clipFromTexture.x = 527;
        clipFromTexture.y = 3894;
        clipFromTexture.w = 47;
        clipFromTexture.h = 44;
        break;
    case 62:
        clipFromTexture.x = 903;
        clipFromTexture.y = 3479;
        clipFromTexture.w = 354;
        clipFromTexture.h = 92;
        break;
    case 63:
        clipFromTexture.x = 2571;
        clipFromTexture.y = 1343;
        clipFromTexture.w = 223;
        clipFromTexture.h = 45;
        break;
    case 64:
        clipFromTexture.x = 2573;
        clipFromTexture.y = 1444;
        clipFromTexture.w = 221;
        clipFromTexture.h = 120;
        break;
    case 65:
        clipFromTexture.x = 2583;
        clipFromTexture.y = 1592;
        clipFromTexture.w = 202;
        clipFromTexture.h = 221;
        break;
    case 66:
        clipFromTexture.x = 2308;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 235;
        clipFromTexture.h = 215;
        break;
    case 67:
        clipFromTexture.x = 2549;
        clipFromTexture.y = 2672;
        clipFromTexture.w = 235;
        clipFromTexture.h = 215;
        break;
    case 68:
        clipFromTexture.x = 2308;
        clipFromTexture.y = 3019;
        clipFromTexture.w = 235;
        clipFromTexture.h = 215;
        break;
    case 69:
        clipFromTexture.x = 2549;
        clipFromTexture.y = 3019;
        clipFromTexture.w = 235;
        clipFromTexture.h = 215;
        break;
    case 70:
        clipFromTexture.x = 882;
        clipFromTexture.y = 3673;
        clipFromTexture.w = 662;
        clipFromTexture.h = 102;
        break;
    case 71:
        clipFromTexture.x = 1590;
        clipFromTexture.y = 3479;
        clipFromTexture.w = 509;
        clipFromTexture.h = 136;
        break;
    case 72:
        clipFromTexture.x = 1595;
        clipFromTexture.y = 3658;
        clipFromTexture.w = 506;
        clipFromTexture.h = 135;
        break;
    case 73:
        clipFromTexture.x = 2210;
        clipFromTexture.y = 3414;
        clipFromTexture.w = 514;
        clipFromTexture.h = 194;
        break;
    case 74:
        clipFromTexture.x = 95;
        clipFromTexture.y = 4022;
        clipFromTexture.w = 197;
        clipFromTexture.h = 570;
        break;
    case 75:
        clipFromTexture.x = 2643;
        clipFromTexture.y = 1887;
        clipFromTexture.w = 89;
        clipFromTexture.h = 188;
        break;
    case 76:
        clipFromTexture.x = 2643;
        clipFromTexture.y = 2135;
        clipFromTexture.w = 89;
        clipFromTexture.h = 191;
        break;
    case 77:
        clipFromTexture.x = 2631;
        clipFromTexture.y = 2401;
        clipFromTexture.w = 90;
        clipFromTexture.h = 156;
        break;
    case 78:
        clipFromTexture.x = 614;
        clipFromTexture.y = 3881;
        clipFromTexture.w = 1024;
        clipFromTexture.h = 786;
        break;
    case 79:
        clipFromTexture.x = 340;
        clipFromTexture.y = 4021;
        clipFromTexture.w = 197;
        clipFromTexture.h = 575;
        break;
    case 80:
        clipFromTexture.x = 95;
        clipFromTexture.y = 4691;
        clipFromTexture.w = 197;
        clipFromTexture.h = 575;
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
        ascii = 27;
        clipFromTexture.x = 625 + (ascii)*73;
        clipFromTexture.y = col*73;
        clipFromTexture.w = 73;
        clipFromTexture.h = 73;
    }
    if ((ascii >= 65 && ascii <= 90)|| (ascii >= 97 && ascii <= 122))
    {
        if (ascii >= 97 && ascii <= 122) //for small letters
        {
            col = 1;
            ascii -= 97;
            clipFromTexture.h = 101;
        }
        else if (ascii >= 65 && ascii <= 90) //for capital letters
        {
            ascii -= 65;
            clipFromTexture.h = 73;
        }
        clipFromTexture.x = 625 + (ascii)*73;
        clipFromTexture.y = col*73;
        clipFromTexture.w = 73;
    }

    else if (ascii >= 48 && ascii <= 57)
    {
        ascii -= 48;
        clipFromTexture.x = 625 + (ascii)*73;
        clipFromTexture.y = 184;
        clipFromTexture.h = 73;
        clipFromTexture.w = 73;
    }

    else if (ascii == 63)
    {
        clipFromTexture.x = 1356;
        clipFromTexture.y = 184;
        clipFromTexture.h = 73;
        clipFromTexture.w = 73;
    }


}




