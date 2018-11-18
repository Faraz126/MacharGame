#include "Window.h"

Window::Window(int x, int y): Entrance( x,y)
{
    spriteNum = 13;
    pos.w = 200;
    pos.h = 110;
}

void Window::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &pos);
}
