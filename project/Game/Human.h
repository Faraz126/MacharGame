#pragma once

class Human
{
private:
    bool infected;
    SDL_Img* human;
    Color* skin;
protected:

public:
    Human();
    ~Human();
    void Walk();
    void Sit();
    void LyingDown();
    Point getPosition();
    void setPosition();
    void MosquitoBite();
    void BackToNormal();

};
