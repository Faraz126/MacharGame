#include <SDL.h>
#include <SDL_image.h>
#include <random>
#include "Lids.h"
#include "Mosquito.h"
#include "BreedingGround.h"

class Container : public BreedingGround
{
    public:
        Container(int, int, int, int, bool = false);
        ~Container();
        virtual void Show(SDL_Renderer*) = 0;
        bool GetCovered();
        virtual Mosquito* Breed(int);
        virtual void SetCovered(bool);

    private:
        bool isCovered;
        //Lids* GenerateLid();
        Lids* lid;
};
