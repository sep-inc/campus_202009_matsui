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

    //!入力判定(入力があったら通る)
    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!R or rキーなら
        if (input_ == 'r' || input_ == 'R')
        {
            return true;
        }
        //!ESCが押された場合
        else if (input_ == ESC)
        {
            m_esc = true;  //!ESCフラグをtrue
        }
    }

    InputForcedKey();  //!強制終了判定

    return false;

}

//!ゲーム開始入力待ち関数
bool Inputter::InputStartKey()
{
    printf("Enterでゲームスタート\n");
    printf("操作方法：Rキーでジャンプ\n");
    printf("終了条件：壁にぶつかるか、300マス先のゴールにたどり着くか。\n");


    char input_; //!入力保存用

    //!コンティニュー関数と似ているが、押すキーが違った場合if文が変わってくるため分ける
    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!Enterキーなら
        if (input_ == ENTER)
        {
            system("cls");
            return true;
        }
        else if (input_ == ESC)
        {
            m_esc = true;
            system("cls");
            return true;
        }
    }

    //!強制終了
    InputForcedKey();

    return false;
}

//!終了待ち関数 
void Inputter::InputForcedKey()
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
    printf("終わるならESC、もしくはctr+c\n");


    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!Enterキーなら
        if (input_ == ENTER)
        {
            system("cls");
            return true;
        }
        else if (input_ == ESC)
        {
            m_esc = true;
            system("cls");
            return false;
        }
    }

    //!強制終了
    InputForcedKey();

    return false;
}





