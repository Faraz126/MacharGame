#include "Manual.h"

Manual::Manual(Screens* prevScreen , bool back): Menu(prevScreen, back)
{
    screenNumber =1;

    manualPos = new SDL_Rect;
    option1Pos = new SDL_Rect;
    option2Pos = new SDL_Rect;
    option3Pos = new SDL_Rect;
    bullet1 = new SDL_Rect;
    bullet2 = new SDL_Rect;
    bullet3 = new SDL_Rect;

    manualPos->x = 100;
    manualPos->y = 100;
    manualPos->w = 900;
    manualPos->h = 500;

    word = new Word[7];
    checkbox = new CheckBox[3];
    checkbox[0].SetPosition(manualPos->x+700,manualPos->y+215);
    checkbox[1].SetPosition(manualPos->x+700,manualPos->y+315);
    checkbox[2].SetPosition(manualPos->x+700,manualPos->y+415);

    question1 = "What are the";
    question2 = "observable symptoms ?";
    option1 = "Shivering";
    option2 = "Rashes";
    option3 = "Fever";

    word[0].SetText(question1);
    word[0].SetPosition(manualPos->x+300,manualPos->y+100);
    word[0].ReduceSize(0.9);

    word[1].SetText(question2);
    word[1].SetPosition(manualPos->x+300,manualPos->y+150);
    word[1].ReduceSize(0.9);

    word[2].SetText(option1);
    word[2].SetPosition(manualPos->x+350,manualPos->y+225);

    word[3].SetText(option2);
    word[3].SetPosition(manualPos->x+350,manualPos->y+325);

    word[4].SetText(option3);
    word[4].SetPosition(manualPos->x+350,manualPos->y+425);

    word[2].ReduceSize(0.6);
    word[3].ReduceSize(0.6);
    word[4].ReduceSize(0.6);

    word[5].SetText("Wrong Answer");
    word[5].SetPosition(manualPos->x+350, manualPos->y+525);
    wordAnswerShow = false;


    buttonText[0]="Give";

    Menu::SetText(buttonText);
    buttonShow = false;

    optionsToShow[0] = optionsToShow[1] = optionsToShow[2] = true;

    option1Pos->x = manualPos->x+300;
    option1Pos->y = manualPos->y+200;
    option1Pos->w = manualPos->w -400;
    option1Pos->h = manualPos ->h -425;

    option2Pos->x = manualPos->x+300;
    option2Pos->y = manualPos->y+300;
    option2Pos->w = manualPos->w -400;
    option2Pos->h = manualPos ->h -425;

    option3Pos->x = manualPos->x+300;
    option3Pos->y = manualPos->y+400;
    option3Pos->w = manualPos->w -400;
    option3Pos->h = manualPos ->h -425;

    bullet1->x = manualPos->x+320;
    bullet1->y = manualPos->y+225;
    bullet1->w = 15;
    bullet1->h = 15;

    bullet2->x = manualPos->x+320;
    bullet2->y = manualPos->y+325;
    bullet2->w = 15;
    bullet2->h = 15;

    bullet3->x = manualPos->x+320;
    bullet3->y = manualPos->y+425;
    bullet3->w = 15;
    bullet3->h = 15;

    correctOption = 1;

    screenChange = false;
    screen3WordShow =false;
    btn = new Button;

        btn->setPosition(400,400);
        btn->SetWidth(571*0.8,102*0.8);
        btn->setText("Give Medication");




}
void Manual::Show(SDL_Renderer* gRenderer)
{


    SDL_SetRenderDrawColor(gRenderer,0,0,0,0);
    SDL_RenderDrawRect(gRenderer,manualPos);
    SDL_RenderFillRect(gRenderer,manualPos);
    word[0].Show(gRenderer);
    word[1].Show(gRenderer);

    SDL_SetRenderDrawColor(gRenderer,250,250,250,0);
    SDL_RenderDrawLine(gRenderer,manualPos->x+250,manualPos->y+60,manualPos->x+250,manualPos->y+450);


    if (optionsToShow[0])
    {
        SDL_RenderDrawRect(gRenderer,option1Pos);
        SDL_RenderDrawRect(gRenderer,bullet1);
        SDL_RenderFillRect(gRenderer,bullet1);
        word[2].Show(gRenderer);
        checkbox[0].Show(gRenderer);

    }

    if (optionsToShow[1])
    {
        SDL_RenderDrawRect(gRenderer,option2Pos);
        SDL_RenderDrawRect(gRenderer,bullet2);
        SDL_RenderFillRect(gRenderer,bullet2);
        word[3].Show(gRenderer);
        checkbox[1].Show(gRenderer);
    }

    if (optionsToShow[2])
    {
        SDL_RenderDrawRect(gRenderer,option3Pos);
        SDL_RenderDrawRect(gRenderer,bullet3);
        SDL_RenderFillRect(gRenderer,bullet3);
        word[4].Show(gRenderer);
        checkbox[2].Show(gRenderer);
    }

    if(wordAnswerShow)
    {
        word[5].Show(gRenderer);
    }

    if(screen3WordShow)
        word[6].Show(gRenderer);

    if(buttonShow)
        btn->Show(gRenderer);




//    SDL_RenderDrawRect(gRenderer,questionPos);
//    SDL_SetRenderDrawColor(gRenderer,250,250,250,0);

}

void Manual::Update(int a)
{

}
void Manual::IntializeScreen2()
{
    wordAnswerShow = false;
    question1= "What are the other symptoms";
    question2="which are not visible?";
    option1 = "bloody stools";
    option3 = "Joint Pain";
    option2 = "Severe abdominal pain";
    word[0].SetText(question1);
    word[0].SetPosition(manualPos->x+300,manualPos->y+100);
    word[0].ReduceSize(0.9);

    word[1].SetText(question2);
    word[1].SetPosition(manualPos->x+300,manualPos->y+150);
    word[1].ReduceSize(0.9);

    word[2].SetText(option1);
    word[2].SetPosition(manualPos->x+350,manualPos->y+225);

    word[3].SetText(option2);
    word[3].SetPosition(manualPos->x+350,manualPos->y+325);

    word[4].SetText(option3);
    word[4].SetPosition(manualPos->x+350,manualPos->y+425);

    word[2].ReduceSize(0.6);
    word[3].ReduceSize(0.6);
    word[4].ReduceSize(0.6);
    for (int i=0; i<3; i++)
    {
        optionsToShow[i]=true;
        checkbox[i].status= false;
    }

    if(correctOption==0)
    {
        correctOption =0;
    }

    else if (correctOption ==1)
    {
        correctOption =2;
    }

    else if (correctOption ==2)
    {
        correctOption = 1;
    }
}
void Manual::IntializeScreen3()
{
    wordAnswerShow = false;
    for (int i=0; i<3; i++)
    {
        optionsToShow[i]=false;
    }
    std::string str1 = "After";
    std::string str2;
    if(correctOption ==0)
    {
        str2 = " malaria parasite test";
    }
    else if(correctOption==2)
    {
        str2 = " chickengyuenya test";
    }
    else if(correctOption==3)
    {
        str2 = " dengue test";
    }
    word[0].SetText(str1 + str2);
    word[0].SetPosition(manualPos->x+300,manualPos->y+100);
    word[0].ReduceSize(0.8);

    word[1].SetText("It was confirmed that the ");
    word[1].SetPosition(manualPos->x+300,manualPos->y+150);
    word[1].ReduceSize(0.8);

    std::string str3 = "person had";
    std::string str4;
    if(correctOption ==0)
    {
        str4 = " malaria";
    }
    else if(correctOption==2)
    {
        str4 = " chikungunya";
    }
    else if(correctOption==3)
    {
        str4 = " dengue test";
    }
    screen3WordShow =true;
    word[6].SetText(str3+str4);
    word[6].SetPosition(manualPos->x+300,manualPos->y+200);
    word[6].ReduceSize(0.8);

    buttonShow = true;

}
void Manual::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;

    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);

            for (int i=0; i<3; i++)
            {
                checkbox[i].HandleEvents(e,node);

                switch(screenNumber)
                {
                case 1:
                    {
                        if(checkbox[i].status)
                        {
                            if(i != correctOption)
                            {
                                optionsToShow[i] = false;
                                wordAnswerShow = true;
                            }
                            if(i == correctOption)
                            {
                                screenNumber++;
                                screenChange = true;

                            }

                        }
                        break;
                    }

                case 2:
                {
                    if (screenChange)
                    {
                        IntializeScreen2();
                        screenChange = false;

                    }
                    if(checkbox[i].status)
                    {
                        if(i != correctOption)
                        {
                            optionsToShow[i] = false;
                            wordAnswerShow = true;
                        }
                        if(i == correctOption)
                        {
                            screenNumber++;
                            screenChange = false;

                        }

                    }
                    break;


                }
                case 3:
                {
                    IntializeScreen3();
                    if(btn->WithinRegion(mouseX,mouseY))
                    {
                        btn->Click();
                    }

                }


                }
            }
        }
    }
}

Manual::~Manual()
{
    delete manualPos;
    delete option1Pos;
    delete option2Pos;
    delete option3Pos;
    delete bullet1;
    delete bullet2;
    delete bullet3;
    delete [] word;
    delete [] checkbox;
    delete btn;
}

