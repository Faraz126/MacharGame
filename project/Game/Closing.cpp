#include "Closing.h"

Closing::Closing()
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


    word = new Word[8];

    word[0].SetText("DEVELOPERS");
    word[0].SetPosition(closingPos->x +(closingPos->w-(25*10))/2 -75,closingWordPos->y+15);

    word[1].SetText("FARAZ AHMED KHAN");
    word[1].SetPosition(closingPos->x +(closingPos->w-(25*16))/2 -75,closingWordPos->y+65);
    word[1].ReduceSize(0.8);

    word[2].SetText("HAREEM FEROZ AHMED ");
    word[2].SetPosition(closingPos->x +(closingPos->w-(25*18))/2 -75,closingWordPos->y+115);
    word[2].ReduceSize(0.8);

    word[3].SetText("TAHA MURTAZA ALI");
    word[3].SetPosition(closingPos->x +(closingPos->w-(25*16))/2 -75,closingWordPos->y+165);
    word[3].ReduceSize(0.8);

    word[4].SetText("HUDA FEROZ AHMED");
    word[4].SetPosition(closingPos->x +(closingPos->w-(25*16))/2 -75,closingWordPos->y+215);
    word[4].ReduceSize(0.8);

    word[5].SetText("SPECIAL THANKS TO");
    word[5].SetPosition(closingPos->x +(closingPos->w-(25*17))/2 -75,closingWordPos->y+315);

    word[6].SetText("DR UMAIR AZFAR");
    word[6].SetPosition(closingPos->x +(closingPos->w-(25*14))/2 -75,closingWordPos->y+365);
    word[6].ReduceSize(0.8);

    word[7].SetText("DR HUMAIRA QURESHI");
    word[7].SetPosition(closingPos->x +(closingPos->w-(25*18))/2 -75,closingWordPos->y+415);
    word[7].ReduceSize(0.8);



}

void Closing::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 0, 0, 0, 0);
    SDL_RenderFillRect(gRenderer,closingPos);

    for(int i=0; i<8; i++)
    {
         word[i].AddPosition((int)counter);
         word[i].Show(gRenderer);
    }
    counter += 0.0008;
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

