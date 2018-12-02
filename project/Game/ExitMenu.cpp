#include "ExitMenu.h"

ExitMenu::ExitMenu(Screens* prevScreen, bool back, bool show, bool update, int factor):Menu(2,175,520,true, prevScreen, back, show, update, factor)  //calling menus constructor that is constructing 2 buttons horizontally
{
    exitPos = new SDL_Rect;
    exitPos->x= 135;
    exitPos->y= 380;
    exitPos->w= 760;
    exitPos->h= 250;  //settings

    buttonText[0]= "YES";
    buttonText[1] = "NO";
    cancelBtn = new CancelButton(exitCancelPos);  //making a cancel button

    Menu::SetText(buttonText);
    word = new Word[1];

    word[0].SetText("DO YOU REALLY WANT TO QUIT ?");
    word[0].SetPosition(exitPos->x+40,exitPos->y+15);


}

void ExitMenu::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(59,gRenderer,exitPos);
    Menu::Show(gRenderer);
    for(int i=0; i<1; i++)
    {
         word[i].Show(gRenderer);
    }

}

void ExitMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::HoverClick(e);   //for button

    if(e->type == SDL_MOUSEBUTTONDOWN)
    {
        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            SetMouseClicked(true);

            if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                /*
                node.cur_screen = new Closing;
                node.cur_screen = new Closing; //will call closing

                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
                */

                curScreen = new Closing(this, false);
            }

            else if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                /*
                node.cur_screen = node.prev_screen;
                node.cur_screen = node.prev_screen; //back to main menu/pre screen
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
                SDL_Delay(1);
                */
                curScreen = prevScreen;
                delete this;
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
    if( prevScreen != curScreen)
    {
        delete prevScreen;
    }

}
