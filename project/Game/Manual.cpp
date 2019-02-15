#include "Manual.h"
#include "Hospital.h"

Manual::Manual(Screens* prevScreen , bool back): Menu(prevScreen, back)
{

}

Manual::Manual(int x, int y, Hospital* hsp): Menu(hsp, true, true, true)

{
    this->hsp = hsp;
    screenNumber =1;

    manualPos = new SDL_Rect;
    option1Pos = new SDL_Rect;
    option2Pos = new SDL_Rect;
    option3Pos = new SDL_Rect;

    manualPos->x = x-20;
    manualPos->y = y-20;
    manualPos->w = 771 * 1.1;
    manualPos->h = 359 *0.95;

    word = new Word[7];
    checkbox = new CheckBox[3];  //checkboxes position
    checkbox[0].SetPosition(manualPos->x+700,manualPos->y+90);
    checkbox[1].SetPosition(manualPos->x+700,manualPos->y+170);
    checkbox[2].SetPosition(manualPos->x+700,manualPos->y+250);

    question1 = "What are the";
    question2 = "observable symptoms ?";
    option1 = "Shivering";
    option2 = "Rashes";
    option3 = "Fever";


    word[0].SetText(question1); //setting questions and options for initial screen

    word[0].SetPosition(manualPos->x+330,manualPos->y+15);
    word[0].ReduceSize(0.7);

    word[1].SetText(question2);
    word[1].SetPosition(manualPos->x+330,manualPos->y+40);
    word[1].ReduceSize(0.7);

    word[2].SetText(option1);
    word[2].SetPosition(manualPos->x+400,manualPos->y+100);

    word[3].SetText(option2);
    word[3].SetPosition(manualPos->x+400,manualPos->y+180);

    word[4].SetText(option3);
    word[4].SetPosition(manualPos->x+400,manualPos->y+260);

    word[2].ReduceSize(0.5);
    word[3].ReduceSize(0.5);
    word[4].ReduceSize(0.5);

    word[5].SetText("Wrong Answer");
    word[5].SetPosition(manualPos->x+400, manualPos->y+310);
    word[5].ReduceSize(0.5);
    wordAnswerShow = false;

    buttonShow = false;

    optionsToShow[0] = optionsToShow[1] = optionsToShow[2] = true;

    option1Pos->x = manualPos->x+350;
    option1Pos->y = manualPos->y+140;
    option1Pos->w = manualPos->w -450;
    option1Pos->h = manualPos ->h -445;

    option2Pos->x = manualPos->x+350;
    option2Pos->y = manualPos->y+220;
    option2Pos->w = manualPos->w -450;
    option2Pos->h = manualPos ->h -445;

    option3Pos->x = manualPos->x+350;
    option3Pos->y = manualPos->y+300;
    option3Pos->w = manualPos->w -450;
    option3Pos->h = manualPos ->h -445;


    if(hsp->CheckHumanDisease()==DISEASE_MALARIA) //Malaria
    {
        correctOption = 0;
    }
    if(hsp->CheckHumanDisease()==CHICKENGUNYA) //Chikungunya
    {
        correctOption = 1;
    }
    if(hsp->CheckHumanDisease()==DENGUE) //Dengue
    {
        correctOption = 2;
    }

    screenChange = false;
    screen3WordShow =false;


    btn = new Button;  //give medication button in screen3
    btn->setPosition(570,350);
    btn->SetWidth(571*0.7,102*0.7);
    btn->setText("Give Medication");

}
void Manual::Show(SDL_Renderer* gRenderer)
{
    Screens::Show(gRenderer);
    texture = Texture::GetInstance(gRenderer);
    Texture::GetInstance()->Render(129, gRenderer, manualPos);
    word[0].Show(gRenderer);
    word[1].Show(gRenderer);
//displaying all options


    if (optionsToShow[0])
    {
        word[2].Show(gRenderer);
        checkbox[0].Show(gRenderer);

    }

    if (optionsToShow[1])
    {
        word[3].Show(gRenderer);
        checkbox[1].Show(gRenderer);
    }

    if (optionsToShow[2])
    {
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

    if (hsp->GetPopped()!=NULL)
    {
        hsp->GetPopped()->UpdatePos(350, 140);
        hsp->GetPopped()->Show(gRenderer);
    }
}

void Manual::Update(int a)
{

}
void Manual::IntializeScreen2()
{
    wordAnswerShow = false;  //screen 2 questions and options based on screen one
    question1= "What are the other symptoms";
    question2="which are not visible?";
    option1 = "bloody stools";
    option3 = "Joint Pain";
    option2 = "Severe abdominal pain";
    word[0].SetText(question1);
    word[0].SetPosition(manualPos->x+330,manualPos->y+15);
    word[0].ReduceSize(0.5);

    word[1].SetText(question2);
    word[1].SetPosition(manualPos->x+330,manualPos->y+40);
    word[1].ReduceSize(0.5);

    word[2].SetText(option1);
    word[2].SetPosition(manualPos->x+400,manualPos->y+100);

    word[3].SetText(option2);
    word[3].SetPosition(manualPos->x+400,manualPos->y+180);

    word[4].SetText(option3);
    word[4].SetPosition(manualPos->x+400,manualPos->y+260);

    word[2].ReduceSize(0.5);
    word[3].ReduceSize(0.5);
    word[4].ReduceSize(0.5);
    for (int i=0; i<3; i++)
    {
        optionsToShow[i]=true;
        checkbox[i].status= false;
    }

    if(correctOption==0)  //correct option will change as options will
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
    wordAnswerShow = false; //statement for screen3
    for (int i=0; i<3; i++)
    {
        optionsToShow[i]=false;
    }
    std::string str1 = "After";
    std::string str2;
    if(correctOption ==0)
    {
        str2 = " Malaria Parasite test";
    }
    else if(correctOption==2)
    {
        str2 = " Antibodies test";
    }
    else if(correctOption==1)
    {
        str2 = " dengue PCR";
    }
    word[0].SetText(str1 + str2);
    word[0].SetPosition(manualPos->x+330,manualPos->y+30);
    word[0].ReduceSize(0.6);

    word[1].SetText("It was confirmed that the ");
    word[1].SetPosition(manualPos->x+330,manualPos->y+80);
    word[1].ReduceSize(0.6);

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
    else if(correctOption==1)
    {
        str4 = " dengue";
    }
    screen3WordShow =true;
    word[6].SetText(str3+str4);
    word[6].SetPosition(manualPos->x+330,manualPos->y+120);
    word[6].ReduceSize(0.7);

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
                                optionsToShow[i] = false; //if wrong answer option will be removed and a wrong answer message will be displayed
                                wordAnswerShow = true;
                            }
                            if(i == correctOption)
                            {
                                screenNumber++;  //if correct answer screen change
                                screenChange = true;

                            }

                        }
                        break;
                    }

                case 2:
                {
                    if (screenChange)
                    {
                        IntializeScreen2(); //screen2
                        screenChange = false;
                    }
                    if(checkbox[i].status)
                    {
                        if(i != correctOption)
                        {
                            optionsToShow[i] = false;  //if wrong answer option will be removed and a wrong answer message will be displayed
                            wordAnswerShow = true;
                        }
                        if(i == correctOption)
                        {
                            screenNumber++; //if correct option new screen
                            screenChange = false;
                            SDL_Delay(10);
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
                        Texture::GetInstance()->SetChunk(MONEY);
                        hsp->LeaveHuman(); //if give medication button will be clicked human will hospital screen and human will leave hospital
                        /*

                        node.cur_screen = node.prev_screen;
                        node.prev_screen = this;
                        node.prev_updatable = false;
                        node.prev_backable = true;
                        */

                        Screens::SetCurrent(hsp);
                        screenNumber++;
                    }
                    break;

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
