#include "Window.h"
#include <random>


Window::Window(int x, int y): Entrance(x,y, 200,110)
{
    spriteNum = 13;
    timeCovered = currentTime = SDL_GetTicks();
    state = CLOSED;
    rect = 0;
}

void Window::ShowOutside(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum, renderer, &OutdoorPos);
}

void Window::Update(int)
{
    currentTime = SDL_GetTicks();
    if (currentTime > (timeCovered + (10*1000)))
    {
        state = OPEN;
    }
    else if(currentTime > (timeCovered + (5*1000)))
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
        SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
        SDL_RenderFillRect(renderer, rect);
    }
    else if (state == OPEN)
    {
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, rect);
    }
    else
    {
        Texture::GetInstance()->Render(spriteNum + state, renderer, rect);
    }

}

void Window::ChangeState()
{
    state = CLOSED;
    timeCovered = SDL_GetTicks();
}

bool Window::IsOpen()
{
    if (state == CLOSED)
    {
        return false;
    }
    else if (state == HALF_OPEN)
    {
        return (rand()%3) == 0;
    }
    return true;
}

Window::~Window()
{

}

