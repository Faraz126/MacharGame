#include "word.h"
class Word
{
public :
    Word::Word ( string str , LTexture * gSpriteSheetTexture , int x, int y)
    {
        this -> TxtTexture = gSpriteSheetTexture ;
        setText ( str );
        setPosition (x,y);
    }
    void Word::render ( SDL_Renderer * gRenderer )
    {
        for ( int i = 0; i < this -> renderWord . length (); i ++)
        {
            characters [i]. render ( gRenderer );
        }
    }
    void Word::setText ( string str )
    {
        this -> renderWord = str ;
        if ( characters != NULL )
        {
            delete [] characters ;
        }
        characters = new Character [ str . length ()];
        for ( int i = 0; i < this -> renderWord . length (); i ++)
        {
            characters [i]. setTexture (this -> TxtTexture , str [i ]);
        }
    }
    void Word::setPosition ( int x, int y)
    {
        this ->x = x;
        this ->y = y;
        for ( int i = 0; i < this -> renderWord . length (); i ++)
        {
        characters [i]. setPosition (x+(i*44) ,y);
        }
    }
    int Word::getTextLength ()
    {
        return this -> renderWord . length ();
    }

private :
    int x,y;
    string renderWord ;
    LTexture * TxtTexture ;
    Character * characters ;
};
