#pragma once


class Button
{
    Button ( LTexture * Texture , string str , int x, int y);
    void render ( SDL_Renderer * gRenderer );
    void setPosition ( int x, int y);
    void setText ( string str );
    void Click();
    Word * word ;
    void Hover();
    void Draw(SDL_Renderer*);
    void Click(SDL_Rect*);

    private:
    int x, y;
    int endx,endy;
    SDL_Rect BtnRect [3];
    LTexture * btnTexture ;
};


