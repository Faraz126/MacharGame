#include "SaveScreen.h"
#include "PauseMenu.h"
#include "Outdoor.h"
SaveMenu::SaveMenu(Outdoor* outPtr):Menu(2,175,520,true)  //calling menus constructor that is constructing 2 buttons horizontally
{
    SDL_StartTextInput();

    savePos = new SDL_Rect;
    savePos->x= 135;
    savePos->y= 220;
    savePos->w= 760;
    savePos->h= 380;

    textBox = new SDL_Rect;
    textBox->x = savePos->x+170;
    textBox->y = savePos->y+100;
    textBox->w = 400;
    textBox->h = 80;

    buttonText[0]= "SAVE";
    buttonText[1] = "BACK";

    Menu::SetText(buttonText);
    word = new Word[2];

    word[0].SetText("Type the file name");
    word[0].SetPosition(savePos->x+100,savePos->y+15);
    word[0].ReduceSize(1.2);

    inputText = " ";
    word[1].SetText(inputText);
    word[1].SetPosition(savePos->x+200,savePos->y+125);

    outdoorPtr = outPtr;
    pauseMenu = new PauseMenu(outdoorPtr);

}

void SaveMenu::Show(SDL_Renderer* gRenderer)
{
    texture = Texture::GetInstance(gRenderer);
    texture->Render(59,gRenderer,savePos);
    Menu::Show(gRenderer);
    SDL_RenderDrawRect(gRenderer,textBox);
    SDL_SetRenderDrawColor(gRenderer,250,250,250,0);
    SDL_RenderFillRect(gRenderer,textBox);
    word[1].SetText(inputText);
    word[1].SetPosition(savePos->x+200,savePos->y+125);
    for(int i=0; i<2; i++)
    {
         word[i].Show(gRenderer);
    }

    SDL_SetRenderDrawColor(gRenderer,0,0,0,0);
    SDL_RenderDrawLine(gRenderer,(savePos->x)+200 + (20*inputText.length()),savePos->y+155,(savePos->x)+220 + (20*inputText.length()),savePos->y+155);   //the line will move forward with more text

}

void SaveMenu::HandleEvents(SDL_Event* e, Screens_Node& node)
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
//                node.cur_screen = new Closing;
//                node.prev_screen = this;
//                node.prev_backable = false;
//                node.prev_updatable = false;
            }

            if (btn[1].WithinRegion(mouseX,mouseY)==true)
            {
                node.cur_screen = node.prev_screen;
                node.prev_screen = this;
                node.prev_backable = false;
                node.prev_updatable = false;
                SDL_StopTextInput();
            }
        }
    }
    if( e->type == SDL_KEYDOWN )
    {
        //Handle backspace
        if( e->key.keysym.sym == SDLK_BACKSPACE && inputText.length() > 0 )
        {
        //lop off character
            inputText.pop_back();
        }
    //Handle copy
        else if( e->key.keysym.sym == SDLK_c && SDL_GetModState() & KMOD_CTRL )
        {
            SDL_SetClipboardText( inputText.c_str() );
        }
    //Handle paste
        else if( e->key.keysym.sym == SDLK_v && SDL_GetModState() & KMOD_CTRL )
        {
            inputText = SDL_GetClipboardText();
//                renderText = true;
        }
    }
    //Special text input event
    else if( e->type == SDL_TEXTINPUT )
    {
        //Not copy or pasting
        if( !( ( e->text.text[ 0 ] == 'c' || e->text.text[ 0 ] == 'C' ) && ( e->text.text[ 0 ] == 'v' || e->text.text[ 0 ] == 'V' ) && SDL_GetModState() & KMOD_CTRL ) )
        {
            //Append character
            if (inputText.length()<10)
                inputText += e->text.text;
        }
    }

}




void SaveMenu::Update(int frame)
{

}

void SaveMenu::SaveGame()
{
    ofstream file;
    file.open(inputText);
    outdoorPtr->Save(file);
    file.close();

}

SaveMenu::~SaveMenu()
{
    delete savePos;
    delete [] word;
    delete pauseMenu;
}





