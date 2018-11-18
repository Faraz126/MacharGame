#pragma once

class Human;

class Mosquito
{
private:


protected:

public:
    Mosquito(){};
    //void fly(Screens*);
    virtual void bite(Human*);
    //void follow(Window*);       //to go in the window
    void follow(Human*);        //to go to human
    ~Mosquito();
};
