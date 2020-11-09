#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>

//!移動キー入力関数
Vec2 Inputter::InpuMoveKey()
{
    char key;      //!入力保存用
    Vec2 direction; //!方向ベクトル保存用

    if (_kbhit())
    {
        key = _getch();  //!入力待ち

         //!十字キーが押された場合
        if (key == 0xFFFFFFE0)
        {
            key = _getch();

            if (key == 0x50) { direction.y = 1; }   //!↓
            else if (key == 0x4B) { direction.x = -1; }  //!←
            else if (key == 0x4D) { direction.x = 1; }   //!→
        }
        //!右回転キーが押された場合
        if (key == 'R' || key == 'r')
        {
            m_right_rote = true;
        }
        //!左回転キーが押された場合
        else if (key == 'L' || key == 'l')
        {
            m_left_rote = true;
        }
        //!ESCキーが押された場合
        else if (key == ESC)
        {
            //!終了フラグtrue
            m_esc = true;
            system("cls");
            direction = Vec2(0, 0);
        }
    }
    else
    {
        m_right_rote = false;
        m_left_rote = false;;
    }

    InputForcedKey();  //!ctrl+cが押されたとき

    return direction;
}

//!回転キー入力関数
void Inputter::InpuRoteKey()
{
    char key;      //!入力保存用

    if (_kbhit())
    {
        key = _getch();  //!入力待ち

        //!右回転キーが押された場合
        if (key == 'R' || key == 'r')
        {
            m_right_rote = true;
        }
        //!左回転キーが押された場合
        else if (key == 'L' || key == 'l')
        {
            m_left_rote = true;
        }
        //!ESCキーが押された場合
        else if (key == ESC)
        {
            //!終了フラグtrue
            m_esc = true;
            system("cls");
        }
    }
    else
    {
        m_right_rote = false;
        m_left_rote = false;;
    }

    InputForcedKey();  //!ctrl+cが押されたとき
}

//!ゲーム開始入力待ち関数
bool Inputter::InputStartKey()
{
  
    char input_; //!入力保存用

    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!Enterキーなら
        if (input_ == ENTER)
        {
            system("cls");
            m_start = true;
            return true;
        }
        //!ESCキーなら
        else if (input_ == ESC)
        {
            system("cls");
            m_esc = true;
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
    printf("終わるならESC、またはctrl+c\n");

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





