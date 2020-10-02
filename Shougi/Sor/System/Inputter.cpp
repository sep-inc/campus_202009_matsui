#include "Inputter.h"
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//!入力待ち関数まとめ
void Inputter::InputNumber()
{
    char input_font = 0;    //!文字保存用
    char input_number = 0;  //!数字保存用


    printf("A,B,C,Dを選んでください\n");
    input_font = _getch();

    while (input_font != 'a' && input_font != 'b' && input_font != 'c' && input_font != 'd')
    {
        printf("もう一度選んでください。\n");
        input_font = _getch();
    }

    printf("1,2,3,4,5を選んでください\n\n");
    input_number = _getch();

    while (input_number != '0' && input_number != '1' && input_number != '2' && input_number != '3'&& input_number != '4')
    {
        printf("もう一度選んでください。\n");
        input_number = _getch();
    }

   

    //!文字を数字に変換
    if (input_font == 'a')
    {
        m_input_font = 0;
    }
    else  if (input_font == 'b')
    {
        m_input_font = 1;
    }
    else  if (input_font == 'c')
    {
        m_input_font = 2;
    }
    else  if (input_font == 'd')
    {
        m_input_font = 3;
    }


    m_input_number = atoi(&input_number);
}

//!終了待ち関数 
bool Inputter::InputEnd()
{
    int end;  //!終了キー番号保存

    end = _getch();  //!入力

    //!Escならばtrue
    if (end == ESC)
    {
        return true;
    }
    else
    {
        return false;
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



