#include "Score.h"

Score* Score::instance = 0;

Score* Score::GetInstance()
{
    if (instance == 0)
    {
        instance = new Score();
    }
    return instance;
}


Score::Score()
{
    scr = 0;
    word = new Word[2];
    scorePos = new SDL_Rect;
    scorePos->x = 10;
    scorePos->y = 4;
    scorePos->w = 147*0.2;
    scorePos->h = 222*0.2;
}

void Score::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(114, gRenderer, scorePos);
    std::string strSrc = std::to_string(scr);
    word[0].SetText("SCORE");
    word[0].SetPosition(45,7);
    word[0].ReduceSize(0.8);
    word[1].SetText(strSrc);  //score by converting int to string
    word[1].SetPosition(150,4);
    for(int i=0; i<2; i++)
        word[i].Show(gRenderer);
}

Score Score::operator+(const Score& a)
{
    Score score;
    score.scr = scr + a.scr;
    return score;
}
Score Score::operator-(const Score& a)
{
    Score score;
    score.scr = scr - a.scr;
    return score;
}
Score Score::operator*(const Score& a)
{
    Score score;
    score.scr = scr * a.scr;
    return score;
}

void Score::operator++(int scr)
{
    this->scr++;
}

void Score::operator--(int scr)
{
    this->scr--;
}

bool Score::operator<(const Score& a)
{
    Score score;
    if (scr < a.scr)
        return true;
    return false;
}
bool Score::operator>(const Score& a)
{
    Score score;
    if (scr > a.scr)
        return true;
    return false;
}
bool Score::operator==(const Score& a)
{
    Score score;
    if (scr == a.scr)
        return true;
    return false;
}


int Score::operator+(int a)
{
    return scr+a;
}
int Score::operator-(int a)
{
    return scr-a;
}
int Score::operator*(int a)
{
    return scr*a;
}


bool Score::operator<(int a)
{
    if (scr < a)
        return true;
    return false;
}
bool Score::operator>(int a)
{
    if (scr > a)
        return true;
    return false;
}
bool Score::operator==(int a)
{
    if (scr == a)
        return true;
    return false;
}

Score::~Score()
{
    delete[]word;
    delete scorePos;
}

int Score :: GetScore()
{
    return scr;
}
