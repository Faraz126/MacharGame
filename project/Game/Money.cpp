#include "Money.h"

Money::Money()
{
    paisa = 0;
    word = new Word[1];
    moneyPos = new SDL_Rect;
    moneyPos->x = 300;
    moneyPos->y = 6;
    moneyPos->w = 240*0.3;
    moneyPos->h = 118 *0.3;
}

void Money::Show(SDL_Renderer* gRenderer)
{
    std::string strPaisa = std::to_string(paisa);
    word[0].SetText(strPaisa);
    word[0].SetPosition(380,7);
    for(int i=0; i<1; i++)
        word[i].Show(gRenderer);  //rendering money by converting int to string
    texture = Texture::GetInstance(gRenderer);
    texture->Render(116, gRenderer, moneyPos);

}

void Money::SetPaisa(int p)
{
    paisa = p;
}
int Money::GetPaisa()
{
    return paisa;
}

Money Money::operator+(const Money& a)
{
    Money Money;
    Money.paisa = Money.paisa + a.paisa;
    return Money;
}
Money Money::operator-(const Money& a)
{
    Money Money;
    Money.paisa = Money.paisa - a.paisa;
    return Money;
}
Money Money::operator*(const Money& a)
{
    Money Money;
    Money.paisa = Money.paisa * a.paisa;
    return Money;
}

void Money::operator++(int paisa)
{
    this->paisa++;
}

bool Money::operator<(const Money& a)
{
    Money Money;
    if (Money.paisa < a.paisa)
        return true;
    return false;
}
bool Money::operator>(const Money& a)
{
    Money Money;
    if (Money.paisa > a.paisa)
        return true;
    return false;
}
bool Money::operator==(const Money& a)
{
    Money Money;
    if (Money.paisa == a.paisa)
        return true;
    return false;
}
int Money::operator+(int a)
{
    return paisa+a;
}
int Money::operator-(int a)
{
    return paisa-a;
}
int Money::operator*(int a)
{
    return paisa*a;
}


bool Money::operator<(int a)
{
    if (paisa < a)
        return true;
    return false;
}
bool Money::operator>(int a)
{
    if (paisa > a)
        return true;
    return false;
}
bool Money::operator==(int a)
{
    if (paisa == a)
        return true;
    return false;
}


Money::~Money()
{
    delete[]word;
}

