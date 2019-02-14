#include "EndMenu.h"


EndMenu::EndMenu(Screens* prevScreen, bool back, bool show, bool update, int factor):Menu(2,80,250,false, prevScreen, back, show, update, factor)
{
    pos0 = new SDL_Rect;
    pos0->x= 0;
    pos0->y = 0;
    pos0->w = 1024;
    pos0->h = 786;   // for background

    pos2.x = 950;
    pos2.y = 10;
    pos2.w = 35;
    pos2.h = 35;    //for cancel button


    buttonText[0]= "RESTART";
    buttonText[1] = "MAIN MENU";
    //buttonText[2] = "LOAD GAME";

    cancelBtn = new CancelButton(pos2);

    Menu::SetText(buttonText);



    word = new Word[1];
    word[0].SetText("H U M A N   D I E D");
    word[0].ReduceSize(3);
    word[0].SetPosition(250,600);
    show = true;
    wordRect = new SDL_Rect;
    wordRect->x = 0;
    wordRect->y = 570;
    wordRect->w = 1024;
    wordRect->h  = 200;


    int randStr3 = rand()% 7;
    str1 = "The Human Died As You Were Not Able To ";
    str2 = "Stop The Mosquito Breeding From ";
    if (randStr3==0)
    {
        str3 = "Tub";
    }
    else if (randStr3==1)
    {
        str3 = "Bucket";
    }
    else if (randStr3==2)
    {
        str3 = "Dirty Water";
    }
    else if (randStr3==3)
    {
        str3 = "Clean Water ";
    }
    else if (randStr3==4)
    {
        str3 = "Trash";
    }
    else if (randStr3==5)
    {
        str3 = "Trash Can";
    }
    else if (randStr3==6)
    {
        str3 = "Manhole";
    }

    word = new Word[2];
    word[0].SetText(str1);
    word[0].SetPosition(100,600);
    word[0].ReduceSize(0.8);
    word[1].SetText(str2+str3);
    word[1].SetPosition(100,650);
    word[1].ReduceSize(0.8);

    screenEnd = false;
    time = 0;

}

void EndMenu::HoverClick(SDL_Event* e)
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

void EndMenu::Show(SDL_Renderer* gRenderer)
{

    Screens::Show(gRenderer);
    if (!screenEnd)
    {
        SDL_SetRenderDrawColor( gRenderer, 2,85,89,0 );
        SDL_RenderDrawRect(gRenderer,wordRect);
        SDL_RenderFillRect(gRenderer,wordRect);
        for(int i =0; i<2 ; i++)
        {
            word[i].Show(gRenderer);
        }
    }
    else
    {
        texture = Texture::GetInstance(gRenderer);
        texture->Render(78,gRenderer,pos0);
        cancelBtn->Show(gRenderer);
        Menu::Show(gRenderer);
    }

    if (time++ > 500)
    {
        screenEnd = true;
    }





}


void EndMenu::Update(int frame)
{

}

void EndMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
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
                node.cur_screen = new Outdoor;
                node.prev_screen = this;
                node.prev_backable = false;  //outdoor screen will open
                */
                curScreen = new Outdoor(this, false);
            }

            else if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {

                /*
                node.cur_screen = new MainMenu;

                node.cur_screen = new MainMenu;  //main menu will open
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
                */
                curScreen = new MainMenu(this, true);
            }

            else if( cancelBtn->WithinRegion(mouseX, mouseY))
            {

                /*
                node.cur_screen = new ExitMenu;
                node.cur_screen = new ExitMenu;  //exit menu will open
                node.prev_screen = this;
                node.prev_backable = true;
                node.prev_updatable = false;
                */

                curScreen = new ExitMenu(this, false);

            }

        }

    }
}




EndMenu::~EndMenu()
{
    delete cancelBtn;
    delete pos0;

    if (prevScreen != 0)
    {
        delete prevScreen;
    }
}

