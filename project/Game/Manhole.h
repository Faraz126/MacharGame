#pragma once

class Manhole : public Container
{
private:

protected:

public:
    Manhole();
    Mosquito* breedType(int);
    void Show(SDL_Renderer*);
    ~Manhole();
};


