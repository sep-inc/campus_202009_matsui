#include "Inputter.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <signal.h>
#include <Windows.h>
#include <conio.h>

//!数字入力関数
void Inputter::InputNumber()
{
    char input_number = 0;  //!数字保存用

    printf("1,2,3,4,5を選んでください\n\n");

    while (true)
    {
        if (_kbhit()) //!入力待ちスルー
        {
            input_number = _getch(); //!入力
            break;
        }

        InputEnd(); //!強制終了処理
    }
   
    //!指定文字以外入力した場合
    while (input_number != '0' && input_number != '1' && input_number != '2' &&
        input_number != '3' && input_number != '4' && input_number != 'r' && input_number != ESC)
    {
        printf("もう一度選んでください。\n");
        input_number = _getch();   //!再入力
    }

    //!代入
    m_input_number = atoi(&input_number);

    //!キャンセルボタンを選択したとき
    if (input_number == 'r')
    {
        m_input_number = -1;
        m_cancel = true;
    }
    else
    {
        m_cancel = false;
    }
    //!終了キー
    if (input_number == ESC)
    {
        exit(0);
    }
}

//!文字入力関数
void Inputter::InputFont()
{
    char input_font = 0;    //!文字保存用

    printf("A,B,C,Dを選んでください\n");

    while (true)
    {
        //!入力待ちスルー
        if (_kbhit())
        {
            input_font = _getch();  //!入力
            break;
        }

        InputEnd(); //!強制終了処理
    }
  

    //!指定文字以外入力した場合Myself
    while (true)
    {
        //!文字を数字に変換
        if (input_font == 'a' || input_font == 'A')
        {
            m_input_font = 0;
            break;
        }
        else  if (input_font == 'b' || input_font == 'B')
        {
            m_input_font = 1;
            break;
        }
        else  if (input_font == 'c' || input_font == 'C')
        {
            m_input_font = 2;
            break;

        }
        else  if (input_font == 'd' || input_font == 'D')
        {
            m_input_font = 3;
            break;

        }
        else if (input_font == ESC)
        {
            exit(0);
        }

        //!キャンセルボタンを選択したとき
        if (input_font == 'r')
        {
            m_input_font = -1;
            m_cancel = true;
            break;
        }
        //!終了キー
        else
        {
            m_cancel = false;
            break;
        }

        printf("もう一度選んでください。\n");
        input_font = _getch();  //!再入力
    }
}

//!矢印キー入力
void Inputter::InputArrowKey()
{ 
    char key = 0; //!入力値保存
    m_mount = Vec2(0, 0); //!移動量保存
    m_decision = false;  //!決定フラグ
    m_cancel = false;    //!キャンセルフラグ

    if (_kbhit())
    {
        key = _getch();  //!入力待ち
    }


    //!矢印キーが押された場合
    if (key == 0xFFFFFFE0)
    {
        key = _getch();

        if (key == 0x48) { m_mount.y = -1; }       //!↑
        else if (key == 0x50) { m_mount.y = 1; }   //!↓
        else if (key == 0x4B) { m_mount.x = -1; }  //!←
        else if (key == 0x4D) { m_mount.x = 1; }   //!→
    }
    //!Spaceキーが押された場合
    else if (key == ' ')
    {
        m_decision = true;   //!決定フラグtrue
        m_mount = Vec2(0, 0);  //!移動量を0にする
    }
    //!キャンセルボタンが押された場合
    else if (key == 'r')
    {
        m_cancel = true;
    }
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
        return true;
    }

    return false;
}





