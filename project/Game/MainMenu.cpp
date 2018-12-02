#include "MainMenu.h"
#include "HighscoreMenu.h"

MainMenu::MainMenu():Menu(3,354,506,false)
{
    pos0.x= 0;
    pos0.y = 0;
    pos0.w = 1024;
    pos0.h = 786;   // for background

    pos1.x = 284;
    pos1.y = 15;
    pos1.w = 435;
    pos1.h = 330; //for mosquito

    pos2.x = 950;
    pos2.y = 10;
    pos2.w = 35;
    pos2.h = 35;    //for cancel button

    mosquitoIterator=43;
    buttonText[0]= "NEW GAME";
    buttonText[1] = "LOAD GAME";
    buttonText[2] = "SETTINGS";

    cancelBtn = new CancelButton(pos2);

    Menu::SetText(buttonText);

    highscorePos0 = new SDL_Rect;
    highscorePos0->x = 30;
    highscorePos0->y = 20;
    highscorePos0->w = 30;
    highscorePos0->h = 30;

}

void MainMenu::HoverClick(SDL_Event* e)
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

void MainMenu::Show(SDL_Renderer* gRenderer)
{
    mosquitoIterator +=0.02;
     if (mosquitoIterator>=52)
        mosquitoIterator=43;
    texture = Texture::GetInstance(gRenderer);
    texture->Render(3,gRenderer,&pos0);
    texture->Render(int(mosquitoIterator),gRenderer,&pos1);
    cancelBtn->Show(gRenderer);
    Menu::Show(gRenderer);
    SDL_SetRenderDrawColor( gRenderer, 2,85,89,0 );
    SDL_RenderDrawRect(gRenderer,highscorePos0);
    SDL_RenderFillRect(gRenderer,highscorePos0);
}


void MainMenu::Update(int frame)
{

}

void MainMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
{
    int mouseX = e->button.x;
    int mouseY = e->button.y;
    Menu::HoverClick(e);
    HoverClick(e);
    if(e->type == SDL_MOUSEBUTTONDOWN || e->type == SDL_MOUSEBUTTONUP)
    {

        if(e->button.button ==  SDL_BUTTON_LEFT)
        {
            if( ( mouseX >highscorePos0->x ) && ( mouseX < (highscorePos0->x+highscorePos0->w) ) && ( mouseY > highscorePos0->y ) && (mouseY< (highscorePos0->y+highscorePos0->h) ) )
            {
                node.cur_screen = new Highscore; //highscore menu
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
            }



            SetMouseClicked(true);
            if (btn[0].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new Outdoor;
                node.prev_screen = this;
                node.prev_backable = false;  //outdoor screen will open

            }


            if (btn[2].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = new Setting;  //setting screen will open
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
            }

            if( cancelBtn->WithinRegion(mouseX, mouseY))
            {
                node.cur_screen = new ExitMenu; //Exit screen will open
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;

            }

        }

    }
}


MainMenu::~MainMenu()
{
    delete cancelBtn;
    delete highscorePos0;
}
