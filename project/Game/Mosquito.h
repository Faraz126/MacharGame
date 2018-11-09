#pragma once

class Mosquito
{
private:
    SDL_img* mosquito;

protected:

public:
    Mosquito();
    void fly(Screen*);
    virtual void bite(Human*);
    void follow(Window*);       //to go in the window
    void follow(Human*);        //to go to human
    ~Mosquito();
};
