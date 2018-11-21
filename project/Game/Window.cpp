#include "Window.h"
#include <random>


Window::Window(int x, int y): Entrance(x,y)
{
    spriteNum = 13;
    pos.w = 200;
    pos.h = 110;
    timeCovered = currentTime = SDL_GetTicks();
    state = CLOSED;

}

void Window::Update(SDL_Event* e, Screens_Node& node)
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
    if (state == HALF_OPEN)
    {
        SDL_SetRenderDrawColor( renderer, 170, 170, 170, 0);
        SDL_RenderFillRect(renderer, &pos);
    }
    else if (state == OPEN)
    {
        SDL_SetRenderDrawColor( renderer, 0, 0, 0, 0);
        SDL_RenderFillRect(renderer, &pos);
    }
    else
    {
        Texture::GetInstance()->Render(spriteNum + state, renderer, &pos);
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

