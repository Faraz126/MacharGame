#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include <string>
#include <sstream>
#include <fstream>
class Outdoor;

class PauseMenu;



class SaveMenu :public Menu
{
    private:
    SDL_Rect* savePos;
    SDL_Rect* textBox;
    Texture* texture;
    Word* word;
    std::string buttonText[2];
    PauseMenu* pauseMenu;
    Outdoor* outdoorPtr;
    std::string inputText;

protected:

public:
    SaveMenu(Outdoor*);
    void Click(SDL_Event*);
    void Hover (SDL_Event*);
    void Show(SDL_Renderer*);
    void Update(int);
    void HandleEvents(SDL_Event*, Screens_Node&);
    void SaveGame();
    ~SaveMenu();
};

