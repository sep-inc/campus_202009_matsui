#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>

//!ジャンプキー入力待ち関数
Vec Inputter::InpuMoveKey()
{
    printf("十字キーで移動\n");

    char key;      //!入力保存用
    Vec direction; //!方向ベクトル保存用

    if (_kbhit())
    {
        key = _getch();  //!入力待ち

         //!矢印キーが押された場合
        if (key == 0xFFFFFFE0)
        {
            key = _getch();

            if (key == 0x48) { direction.y = -1; }       //!↑
            else if (key == 0x50) { direction.y = 1; }   //!↓
            else if (key == 0x4B) { direction.x = -1; }  //!←
            else if (key == 0x4D) { direction.x = 1; }   //!→
        }
        //!ESCキーが押された場合
        else if (key == ESC)
        {
            //!終了フラグtrue
            m_esc = true;
            system("cls");
            direction = Vec(0, 0);
        }
    }

    InputForcedKey();  //!ctrl+cが押されたとき

    return direction;
}

//!ゲーム開始入力待ち関数
bool Inputter::InputStartKey()
{
    printf("Enterでゲームスタート\n");
    printf("あなたは「■」を操作してください。\n");
    printf("操作方法：十字キーで移動\n");
    printf("終了条件：移動先で何かにぶつかると負け。\n");

    char input_; //!入力保存用
    
    if (_kbhit())
    {
        input_ = _getch(); //!入力

        //!Enterキーなら
        if (input_ == ENTER)
        {
            system("cls");
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





