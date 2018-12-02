#include "Plant.h"

Plant::Plant(int x, int y): Container(x,y, PLANT_WIDTH, PLANT_HEIGHT)
{
    spriteNum = rand()%4 + 27; //to choose if plant is watered or not
/*

<<<<<<< HEAD
    water = 0;
    SetCovered((bool)(rand()%2));
    percentage = 5;
=======
    //lid = 0;
>>>>>>> daba5613d1af045bdabb1b8193ff17be11eceb82
*/
    SetCovered(false);
    lid = new Soil(pos.x, pos.y + 300);

    //SetCovered((bool)(rand()%2));
        //plant image proportion with which image will be rendered

}

void Plant::SetCovered(bool status)
{
    if (status)
    {
        //delete water;
        if (lid != 0)
        {
            lid->SetPosition(pos.x-6,pos.y-14);
            //lid = 0;
        }
        if (spriteNum >31)
        {
            spriteNum -= 4;
        }
    }
    else
    {
        spriteNum += 4;
    }

    Container::SetCovered(status);
}

void Plant::HandleEvents(SDL_Event* e, Screens_Node& node)
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

void Plant::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
    lid->Show(renderer);
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
