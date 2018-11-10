class Button
{

public :
Button::Button( LTexture * Texture , string str , int x, int y)
{
    this -> word = new Word (str , Texture , x, y);
    this -> btnTexture = Texture ;

    BtnRect[0].x = 0;
    BtnRect[0].y = 445;
    BtnRect[0].w = 44;
    BtnRect[0].h = 55;

    BtnRect[1].x = 44;
    BtnRect[1].y = 445;
    BtnRect[1].w = 50;
    BtnRect[1].h = 55;

    BtnRect[2].x = 117;
    BtnRect[2].y = 445;
    BtnRect[2].w = 44;
    BtnRect[2].h = 55;

    setPosition (x, y);
}

void Button::render ( SDL_Renderer * gRenderer )
{
    btnTexture -> render (this->x,this->y , gRenderer , & BtnRect [0]);
    int x = this->x + 44;

    endx = x;
    int len = word->getTextLength();
    if (len > 3)
    {
        len -= 2;
    }
    else
    {
        len = 2;
    }

    endy = this->y + 48;
    for ( int i = 0; i < len; i ++)
    {

        btnTexture -> render (x,this->y, gRenderer , & BtnRect [1]);
        x += 50;
        endx += 50;
    }
    btnTexture -> render (x, this->y , gRenderer , & BtnRect [2]);
    endx += 48;
    word -> render ( gRenderer );

}

void Button::setPosition ( int x, int y)
{
    this ->x = x;
    this ->y = y;
    this ->word -> setPosition (this->x+5,this->y+5);
}
void Button::setText ( string str )
{
    word -> setText ( str );
    setPosition (x, y);
}
void Button::Click()
{

}
Word * word ;

};

