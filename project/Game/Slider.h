#pragma once

class Slider
{
private:
    SDL_rect* slider;
    int value;
protected:

public:
    Slider();
    int GetValue();
    void SetValue(int);
    void Show(SDL_renderer*);
    ~Slider();
};

