#include "TrashCanLid.h"

TrashCanLid:: TrashCanLid(int x, int y): Lids(x,y, TRASHCANLID_WIDTH, TRASHCANLID_HEIGHT)
{
    spriteNum = 63;
}

TrashCanLid:: ~TrashCanLid()
{

}

void TrashCanLid::Show(SDL_Renderer* renderer)
{
    Texture::GetInstance()->Render(spriteNum,renderer, &pos);
}
