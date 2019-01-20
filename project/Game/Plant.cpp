#include "Plant.h"

Plant::Plant(int x, int y): Container(x,y, PLANT_WIDTH, PLANT_HEIGHT)
{
    spriteNum = (rand()%8) + 27; //to choose if plant is watered or not
    if(spriteNum>=31)
    {
        lid = new Soil(pos.x, pos.y + 150);
        lid->ReduceSize(0.5);
    }
    else
    {
        lid = 0;
    }
    //SetCovered(false);
}

void Plant::SetCovered(bool status)
{
    if (status)
    {
        lid->SetPosition(pos.x-6,pos.y-14);
        if (spriteNum==34)
        {
            spriteNum = 29;
        }
        if (spriteNum==33)
        {
            spriteNum = 30;
        }
        if (spriteNum==33)
        {
            spriteNum = 30;
        }
        if (spriteNum==32)
        {
            spriteNum = 28;
        }
        if (spriteNum==31)
        {
            spriteNum = 27;
        }
    }

    Container::SetCovered(status);
}

void Plant::HandleEvents(SDL_Event* e, Screens_Node& node)
{

    if (lid != 0 && !GetCovered())
    {
        if (!GetCovered())
        {
            lid->HandleEvents(e,node);
        }
        if (lid->Collides(pos))
        {
            SetCovered(true);
        }
    }
}

void Plant::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);

    if (lid != 0)
    {
        if (!GetCovered())
        {
            lid->Show(renderer);
        }
    }
}

Mosquito* Plant::Breed()
{
    return factory->GetMosquito(0);

}
void Plant::Write(std::fstream& file)
{
    file<< pos.x << '\n';
    file<< pos.y << '\n';
    file<< pos.w << '\n';
    file <<pos.h << '\n';
    file << GetCovered() << '\n';
    if (GetCovered())
        lid->Write(file);

}

void Plant::Read(std::fstream& file)
{
    std::string myString;
    getline(file, myString);
    pos.x = std::stoi(myString);
    getline(file, myString);
    pos.y = std::stoi(myString);
    getline(file, myString);
    pos.w = std::stoi(myString);
    getline(file, myString);
    pos.h = std::stoi(myString);
    getline(file,myString);
    bool cover = stoi(myString);
    if (cover)
    {
        lid = new Soil();
        lid->Read(file);
    }

}

void Plant::Update(int)
{
    if (!GetCovered())
    {
        if ((rand()%10000) < percentage)
        {
            AddMosquito(Breed());
        }
    }
}

Plant::~Plant()
{
    //dtor
}
