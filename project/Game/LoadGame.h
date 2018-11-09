#pragma once

class LoadGame
{
private:
    char* name;
    char* date;
    char* fileName;
protected:

public:
    LoadGame();
    void Load();
    ~LoadGame();
};
