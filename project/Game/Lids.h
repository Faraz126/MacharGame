#pragma once

class Lids
{
private:

protected:
    SDL_img* lid;

public:
    Lids();
    void Drag(SDL_event);
    void Drop(SDL_event);
    void Show(SDL_renderer*);
    void Uncover();
    ~Lids();
};

