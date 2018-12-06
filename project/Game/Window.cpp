#include "Window.h"
#include <random>


Window::Window(int x, int y): Entrance(x,y, 200,110)
{
    spriteNum = 13;
    timeCovered = 0;
    endTime = currentTime + 10000;
    state = CLOSED;
    rect = 0;
}

void Window::ShowOutside(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &outdoorPos);
}

void Window::Update(int)
{
    timeCovered++;
    if (timeCovered > endTime)
    {
        state = OPEN;
    }
    else if(timeCovered > endTime/2)
    {
        state = HALF_OPEN;
    }
}

void Window::Show(SDL_Renderer* renderer)
{
    if (rect == 0)
    {
        rect = &pos;
    }
    if (state == HALF_OPEN)
    {
       Texture::GetInstance()->Render(124, renderer, rect);
    }
    else if (state == OPEN)
    {
        Texture::GetInstance()->Render(125, renderer, rect);
    }
    else
    {
        Texture::GetInstance()->Render(spriteNum + state, renderer, rect);
    }

}

void Window::ChangeState()
{
    state = CLOSED;
    timeCovered = 0;
    endTime = timeCovered + 10000;
}

bool Window::IsOpen()
{
    if (state == CLOSED)
    {
        return false;
    }
    else if (state == HALF_OPEN)
    {
        return (rand()%5) == 0;
    }
    return true;
}

Window::~Window()
{

}

