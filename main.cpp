#include "TXLib.h"

struct Button
{
    int x;
    int y;
    int w;
    int h;
    const char* text;

    void draw()
    {
        txSetColor (TX_WHITE, 3);
        txSetFillColor (TX_YELLOW);
        Win32::RoundRect (txDC(), x, y, x+w, y+h, 30, 30);
        txSelectFont("Times New Roman", 30);
        txSetColor (TX_RED);
        txDrawText(x, y, x+w, y+h, text);
    }

    bool click()
    {
        return(txMouseX()>x && txMouseX()<x+w &&
                txMouseY()>y && txMouseY()<y+h &&
                txMouseButtons() == 1);
    }
};

int main()
{
txCreateWindow (800, 600);
txTextCursor (false);

string PAGE = "menu";

Button btn0 = {100, 100, 200, 40, "�����"};
Button btn1 = {100, 150, 200, 40, "������� ����"};
Button btn2 = {100, 200, 200, 40, "�����"};
Button btn3 = {50, 50, 200, 40, "�����"};


    while(!btn2.click())
    {
        txClear();
        txBegin();

        if(PAGE == "menu")
        {
            btn0.draw();
            btn1.draw();
            btn2.draw();

            if(btn0.click())
            {
                PAGE = "game";
            }

            txSetFillColor (TX_BLACK);
        }

        if(PAGE == "game")
        {

            btn3.draw();
            if(btn3.click())
            {
                PAGE = "menu";
            }

            txSetFillColor (TX_WHITE);
            txSetColor (TX_BLACK);
            txRectangle (100, 200, 400, 500);

        }

        txEnd();
        txSleep(50);
    }

txDisableAutoPause();
return 0;
}



