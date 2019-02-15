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
    word = new Word[6];
    scorePos = new SDL_Rect;
    scorePos->x = 10;
    scorePos->y = 4;
    scorePos->w = static_cast<int>(147*0.2);
    scorePos->h = static_cast<int>(222*0.2);
    word[0].SetText("SCORE");
    word[0].SetPosition(40,6);
    word[0].ReduceSize(0.8);
    word[2].SetText("ALL OKAY");
    word[2].ReduceSize(0.8);
    word[2].SetPosition(730,10);
    word[3].SetText("PEOPLE ARE ILL");
    word[3].SetPosition(670,10);
    word[3].ReduceSize(0.8);
    word[4].SetText("PEOPLE ARE DYING");
    word[4].SetPosition(630,10);
    word[4].ReduceSize(0.8);




    status = GREEN;
}

void Score::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(114, gRenderer, scorePos);
    std::string strSrc = std::to_string(scr);
    std::string ppl = std::to_string(people);

    word[1].SetText(strSrc);  //score by converting int to string
    word[1].SetPosition(150,4);
    word[5].SetText(ppl);  //score by converting int to string
    word[5].SetPosition(600,10);
    for(int i=0; i<2; i++)
        word[i].Show(gRenderer);

}

void Score::ShowStatus(SDL_Renderer* gRenderer)
{
    SDL_Rect outline = {960,10,30,30};
    if (status == GREEN)
    {
       SDL_SetRenderDrawColor( gRenderer, 0, 255, 0,0);
       word[2].Show(gRenderer);
    }
    else if (status == RED)
    {
        SDL_SetRenderDrawColor( gRenderer, 255, 0, 0,0);
        word[4].Show(gRenderer);
        word[5].Show(gRenderer);
    }
    else if (status == ORANGE)
    {
        SDL_SetRenderDrawColor( gRenderer, 255, 169, 0,0);
        word[3].Show(gRenderer);
        word[5].Show(gRenderer);
    }

    SDL_RenderFillRect(gRenderer,&outline);
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
