#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>


bool Inputter::InputJumpKey()
{
    printf("Rキーでジャンプ\n");

    char input_; //!入力保存用

    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!R or rキーなら
        if (input_ == 'r' || input_ == 'R')
        {
            return true;
        }
        else if (input_ == ESC)
        {
            exit(0);
        }
    }

    InputEnd();

    return false;

}

//!終了待ち関数 
void Inputter::InputEnd()
{
    //!ctrl+cが押されたとき
    signal(SIGINT, SIG_DFL); //!終了
}

//!コンティニュー関数
bool Inputter::InputContinue()
{
    char input_; //!入力保存用

    printf("まだ続けますか?\n");
    printf("続けるならEnter\n");

    input_ = _getch(); //!入力

    //!Enterキーなら
    if (input_ == ENTER)
    {
        system("cls");
        return true;
    }

    return false;
}





