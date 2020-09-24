#include "Inputter.h"
#include <stdio.h>
#include <conio.h>

//!入力待ち関数まとめ
void Inputter::InputNumber()
{
    char input_font = 0;    //!文字保存用
    char input_number = 0;  //!数字保存用


    printf("A,B,Cを選んでください\n");
    input_font = _getch();

    printf("1,2,3,を選んでください\n");
    input_number = _getch();

    //!文字を数字に変換
    if (input_font == 'A')
    {
        m_input_font = 0;
    }
    else  if (input_font == 'B')
    {
        m_input_font = 1;
    }
    else  if (input_font == 'C')
    {
        m_input_font = 2;
    }
   
    //!文字を数字に変換
    switch (input_number)
    {
    case '1':
        m_input_number = 0;
        break;
    case '2':
        m_input_number = 1;
        break;
    case '3':
        m_input_number = 2;
        break;
    default:
        break;
    }

}

/* 終了待ち関数 */
bool Inputter::InputEnd()
{
    int end;  //終了キー番号保存

    end = _getch();  //入力

    /* Escならばtrue */
    if (end == ESC)
    {
        return true;
    }
    else
    {
        return false;
    }
}


