#include "Inputter.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <signal.h>
#include <Windows.h>

//!数字入力関数
void Inputter::InputNumber()
{
    char input_number = 0;  //!数字保存用

    printf("1,2,3,4,5を選んでください\n\n");
    input_number = _getch(); //!入力

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
    input_font = _getch();  //!入力

    //!指定文字以外入力した場合Myself
    while (true)
    {
        //!文字を数字に変換
        if (input_font == 'a')
        {
            m_input_font = 0;
            break;
        }
        else  if (input_font == 'b')
        {
            m_input_font = 1;
            break;
        }
        else  if (input_font == 'c')
        {
            m_input_font = 2;
            break;

        }
        else  if (input_font == 'd')
        {
            m_input_font = 3;
            break;

        }
        else if (input_font = ESC)
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


//!終了待ち関数 
void Inputter::InputEnd()
{
    //!ctrl+cが押されたとき
    if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    {
        exit(1); //!終了
    }
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





