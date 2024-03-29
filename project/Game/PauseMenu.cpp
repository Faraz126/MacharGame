#include "PauseMenu.h"

PauseMenu::PauseMenu(Outdoor* outPtr, Screens* scr, bool back):Menu(2,80,230,false, scr, back)
{
    pausePos = new SDL_Rect;
    pausePos->x= 0;
    pausePos->y= 0;
    pausePos->w= 1024;
    pausePos->h= 786;

    pauseCancelPos.x = 950;
    pauseCancelPos.y = 10;
    pauseCancelPos.w = 35;
    pauseCancelPos.h = 35;

    buttonText[0]= "RESUME";
//    buttonText[1] = "SAVE";
//    buttonText[2]= "LOAD";
    buttonText[1] = "MAIN MENU";

    cancelBtn = new CancelButton(pauseCancelPos);  //making a cancel button

    Menu::SetText(buttonText);
    word = new Word[1];

    word[0].SetText("P A U S E D");
    word[0].SetPosition(pausePos->x+80,pausePos->y+100);
    word[0].ReduceSize(1.5);

    outdoor = outPtr;

}

void PauseMenu::HoverClick(SDL_Event* e)
{
    int hoverX = e->button.x;  //for cancel button click
    int hoverY = e->button.y;

    if( cancelBtn->WithinRegion(hoverX,hoverY)==true)
    {
        cancelBtn->Hover();
    }
    else
    {
        cancelBtn->diffStateBtn=53;
    }

}

void PauseMenu::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(78,gRenderer,pausePos);
    cancelBtn->Show(gRenderer);
    Menu::Show(gRenderer);
    for(int i=0; i<1; i++)
        word[i].Show(gRenderer);
}


void PauseMenu::Update(int frame)
{

}

void PauseMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::HoverClick(e);
    HoverClick(e);
    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {

        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);
            if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                /*
                node.cur_screen = node.prev_screen;
                */
                curScreen = prevScreen;
                delete this;

            }
//            else if (btn[1].WithinRegion(mouseX,mouseY)==true)
//            {
//                /*
//                node.cur_screen = new SaveMenu(outdoor);
//                node.prev_screen = this;
//                node.prev_updatable = false;
//                node.prev_backable = true;
//                */
//
//                curScreen = new SaveMenu(outdoor, this, true);
//
//            }

            else if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                /*
                node.cur_screen = new MainMenu;
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
                */

                curScreen = new MainMenu(this, false);



            }

            else if( cancelBtn->WithinRegion(mouseX, mouseY))
            {
                /*
                node.cur_screen = new ExitMenu;
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
                */
                curScreen = new ExitMenu(this, true);



            }

        }

    }
}

PauseMenu::~PauseMenu()
{

    delete pausePos;
    delete cancelBtn;
    delete [] word;
    if (curScreen != prevScreen)
    {
        outdoor->Delete();
    }
}
