#pragma once

class Entrance
{
private:
    bool State;
    SDL_Img* entrance;
protected:

public:
    Entrance();
    virtual void Show();
    bool GetState();
    void SetState();
    void MosquitoEnter();
    ~Entrance();
};


