#pragma once

class Human
{
private:
    bool infected;
protected:

public:
    Human();
    ~Human();
    void Walk();
    void Sit();
    void LyingDown();
    void setPosition();
    void MosquitoBite();
    void BackToNormal();

};
