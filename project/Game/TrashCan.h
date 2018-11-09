#pragma once

class TrashCan : public Container
{
private:

protected:

public:
    TrashCan();
    Mosquito* breedType(int);
    void Show(SDl_Render*);
    ~TrashCan();
};

