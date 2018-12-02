#pragma once
#include "SDL.h"
#include <stdio.h>
#include "SDL_image.h"
#include "Menu.h"
#include "CheckBox.h"
#include "Button.h"
#include "Hospital.h"
#include "Human.h"

class Manual: public Menu
{
    Word*word;
    Hospital* hsp;
    Texture* texture;
    CheckBox* checkbox;
    std::string buttonText[1];
    int correctOption;
    int screenNumber;

    SDL_Rect* manualPos;
    SDL_Rect* option1Pos;
    SDL_Rect* option2Pos;
    SDL_Rect* option3Pos;
    SDL_Rect* bullet1;
    SDL_Rect* bullet2;
    SDL_Rect* bullet3;

    std::string question1;
    std::string question2;
    std:: string option1;
    std:: string option2;
    std:: string option3;


    bool optionsToShow[3];
    bool wordAnswerShow;
    bool answers[3];
    bool checkboxAnswers[3];
    bool screenChange;
    bool screen3WordShow;
    bool buttonShow;

 public:
     Manual(int,int,Hospital*);
     void Show(SDL_Renderer*);
     void HandleEvents(SDL_Event*, Screens_Node&);
     void Update(int);
     void IntializeScreen2();
     void IntializeScreen3();
     ~Manual();
};
