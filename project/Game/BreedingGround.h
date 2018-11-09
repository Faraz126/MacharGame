#pragma once

class BreedingGround
{
private:

protected:
    SDL_Img* breedingground;
    Point* point;

public:
    BreedingGround();
    virtual void Show(SDL_Render*);
    void breed(int);
    ~BreedingGround();
};
