#include "ExitMenu.h"

ExitMenu::ExitMenu():Menu(2,175,520,true)  //calling menus constructor that is constructing 2 buttons horizontally
{
    exitPos = new SDL_Rect;
    exitPos->x= 150;
    exitPos->y= 380;
    exitPos->w= 720;
    exitPos->h= 250;  //settings

    buttonText[0]= "YES";
    buttonText[1] = "NO";
    cancelBtn = new CancelButton(exitCancelPos);  //making a cancel button

    Menu::SetText(buttonText);
    word = new Word[1];

    word[0].SetText("DO YOU REALLY WANT TO QUIT");
    word[0].SetPosition(exitPos->x+35,exitPos->y+15);

}

void ExitMenu::Show(SDL_Renderer* gRenderer)
{
    SDL_SetRenderDrawColor( gRenderer, 255, 255, 255, 0);   //Exit ka rectangle wala box
    SDL_RenderFillRect(gRenderer,exitPos);
    Menu::Show(gRenderer);
    for(int i=0; i<1; i++)      //rendering all words i.e settings,volume,brightness
    {
         word[i].Show(gRenderer);
    }

}

void ExitMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    //Menu::Hover(e);  //for button
    Menu::HoverClick(e);   //for button

    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);

            if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new Closing;
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
            }

            if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = node.prev_screen;
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
            }
        }
    }
}




void ExitMenu::Update(int frame)
{

}

ExitMenu::~ExitMenu()
{
    delete exitPos;
    delete cancelBtn;
    delete [] word;
}
