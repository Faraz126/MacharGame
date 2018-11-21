#include "Window.h"
#include <random>


Window::Window(int x, int y): Entrance(x,y, 200,110)
{
    spriteNum = 13;
    timeCovered = currentTime = SDL_GetTicks();
    state = CLOSED;

}

void Window::ShowOutside(SDL_Renderer* renderer, const SDL_Rect& rect ,float widthRatio)
{
    SDL_Rect temp;
    temp.x = rect.x + (((1024-(float)pos.x)/1024)*(float)rect.w) -35;
    temp.y = 325;
    temp.w = pos.w/widthRatio;
    temp.h = pos.h/widthRatio;
    Show(renderer, &temp);
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

void Window::Show(SDL_Renderer* renderer, SDL_Rect* rect)
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

