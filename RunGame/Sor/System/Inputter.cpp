#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>

//!ジャンプキー入力待ち関数
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
            m_end = true;
        }
    }

    InputEnd();

    return false;

}

//!ゲーム開始入力待ち関数
bool Inputter::InputStart()
{
    printf("Enterでゲームスタート\n");
    printf("操作方法：Rキーでジャンプ\n");
    printf("終了条件：壁にぶつかるか、300マス先のゴールにたどり着くか。\n");


    char input_; //!入力保存用

    while (true)
    {
        if (_kbhit())
        {
            input_ = _getch(); //!入力

            //!Enterキーなら
            if (input_ == ENTER)
            {
                system("cls");
                return true;
            }
        }

        //!強制終了
        InputEnd();
    }

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





