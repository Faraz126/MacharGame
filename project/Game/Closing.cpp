#include "Closing.h"

Closing::Closing(Screens* prevScreen, bool back, bool show, bool update, int factor): Menu(prevScreen, back, show, update, factor)
{
    closingPos = new SDL_Rect;
    closingPos->x= 0;
    closingPos->y= 0;
    closingPos->w= 1240;
    closingPos->h= 786;

    closingWordPos = new SDL_Rect;
    closingWordPos->x= 0;
    closingWordPos->y= 0;
    closingWordPos->w= 1240;
    closingWordPos->h= 786;

    space = 50;

    word = new Word[15];  //setting word text and position

    word[0].SetText("DEVELOPERS");
    word[0].SetPosition(closingPos->x +(closingPos->w-(25*10))/2 -75,closingWordPos->y+15);

    word[1].SetText("Faraz Ahmed Khan");
    word[1].ReduceSize(0.8);
    word[1].SetPosition(closingPos->x +(closingPos->w-(25*16))/2 -75,closingWordPos->y+(space));

    word[2].SetText("Hareem Feroz Ahmed");
    word[2].ReduceSize(0.8);
    word[2].SetPosition(closingPos->x +(closingPos->w-(25*18))/2 -75,closingWordPos->y+2*space);

    word[3].SetText("Huda Feroz Ahmed");
    word[3].ReduceSize(0.8);
    word[3].SetPosition(closingPos->x +(closingPos->w-(25*16))/2 -75,closingWordPos->y+3*space);

    word[4].SetText("SUPERVISOR");
    word[4].SetPosition(closingPos->x +(closingPos->w-(25*10))/2 -75,closingWordPos->y+4*space);

    word[5].SetText("Dr Umair Azfar");
    word[6].ReduceSize(0.8);
    word[5].SetPosition(closingPos->x +(closingPos->w-(25*14))/2 -75,closingWordPos->y+5*space);

    word[6].SetText("Dr Humaira Qureshi");
    word[6].ReduceSize(0.8);
    word[6].SetPosition(closingPos->x +(closingPos->w-(25*18))/2 -75,closingWordPos->y+6*space);

    word[7].SetText("GRAPHICS TAKEN FROM");
    word[7].SetPosition(closingPos->x +(closingPos->w-(25*19))/2 -75,closingWordPos->y+7*space);

    word[8].SetText("freepik");
    word[8].ReduceSize(0.8);
    word[8].SetPosition(closingPos->x +(closingPos->w-(25*7))/2 -75,closingWordPos->y+8*space);

    word[9].SetText("flatcoin");
    word[9].ReduceSize(0.8);
    word[9].SetPosition(closingPos->x +(closingPos->w-(25*8))/2 -75,closingWordPos->y+9*space);

    word[10].SetText("vecteezy");
    word[10].ReduceSize(0.8);
    word[10].SetPosition(closingPos->x +(closingPos->w-(25*8))/2 -75,closingWordPos->y+10*space);

    word[11].SetText("SOUNDS TAKEN FROM");
    word[11].SetPosition(closingPos->x +(closingPos->w-(25*17))/2 -75,closingWordPos->y+11*space);

    word[12].SetText("soundbible");
    word[12].ReduceSize(0.8);
    word[12].SetPosition(closingPos->x +(closingPos->w-(25*10))/2 -75,closingWordPos->y+12*space);

    word[13].SetText("RESEARCH HELP FROM");
    word[13].SetPosition(closingPos->x +(closingPos->w-(25*18))/2 -75,closingWordPos->y+13*space);

    word[14].SetText("Dr Mirza Fayyaz");
    word[14].ReduceSize(0.8);
    word[14].SetPosition(closingPos->x +(closingPos->w-(25*15))/2 -75,closingWordPos->y+14*space);






}

void Closing::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
    SDL_RenderFillRect(gRenderer,closingPos);

    for(int i=0; i<15; i++)
    {
         word[i].AddPosition((int)counter);  //to slide the text
         word[i].Show(gRenderer);
    }
    counter += 0.0008;  //to delay  the quit
    if(counter>1.75)

        SDL_Quit();


}


void Closing::Update(int frame)
{

}

void Closing::HandleEvents(SDL_Event* e, Screens_Node& node)
{

}

Closing::~Closing()
{
    delete closingPos;
    delete [] word;
}

