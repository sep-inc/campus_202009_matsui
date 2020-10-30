#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>

Inputter* Inputter::p_instance = 0;

//!インスタンス化関数
Inputter* Inputter::Instance()
{
   /* static Inputter inputter;

    return &inputter;*/

    if (p_instance == 0)
    {
        p_instance = new Inputter; //!インスタンス化
    }

    return p_instance;

}

//!メンバ変数リセット関数
void Inputter::Reset()
{
    m_esc = false;      //!決定キーフラグ
    m_decide = false;   //!ESC時終了フラグ

     //!数字キー用
    m_start_number = 0;
    m_end_number = 0;

    m_input_font = 0;    //!入力文字変数
    m_input_number = 0;  //!入力数字変数
}

//!十字キー入力待ち関数
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
            direction = Vec2(0, 0);
        }
        //!Enterキーなら
        if (key == ENTER)
        {
            m_decide = true;
        }
        //!キャンセルボタンが押された場合
        else if (key == 'r')
        {
            m_cancel = true;
        }
    }
    else
    {
        m_esc = false;
        m_decide = false;
        m_cancel = false;
    }

    InputForcedKey();  //!ctrl+cが押されたとき

    return direction;
}

bool Inputter::InputJumpKey()
{

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

void Inputter::InputNumber()
{
    char input_font = 0;    //!文字保存用
    char input_number = 0;  //!数字保存用

    printf("A,B,Cを選んでください\n");
    input_font = _getch();


    while (input_font != 'A' && input_font != 'B' && input_font != 'C' && input_font != ESC)
    {
        printf("もう一度A,B,Cを選んでください。\n");
        input_font = _getch();
    }

    printf("1,2,3を選んでください\n\n");
    input_number = _getch();

    while (input_number != '1' && input_number != '2' && input_number != '3' && input_number != ESC)
    {
        printf("もう一度1,2,3を選んでください。\n");
        input_number = _getch();
    }

    //!文字を数字に変換
    if (input_font == 'A') { m_input_font = 0; }
    else  if (input_font == 'B') { m_input_font = 1; }
    else  if (input_font == 'C') { m_input_font = 2; }
    else if (input_font == ESC)
    {
        m_esc = true;
        m_input_font = 0;
    }

    //!文字を数字に変換
    if (input_number == '1') { m_input_number = 0; }
    else  if (input_number == '2') { m_input_number = 1; }
    else  if (input_number == '3') { m_input_number = 2; }
    else if (input_number == ESC)
    {
        m_esc = true;
        m_input_number = 0;
    }
}

void Inputter::InputNumber2()
{
    printf("移す場所を選んでください\n");
    printf("1or2or3\n");
    m_start_number = ReInputNumber();

    printf("送る場所を選んでください\n");
    printf("1or2or3\n");

    m_end_number = ReInputNumber();
}

int Inputter::ReInputNumber()
{
    char input_number = 0;

    input_number = _getch();

    while (input_number != '1' && input_number != '2' && input_number != '3'&& input_number != ESC)
    {
        printf("もう一度選んでください\n");
        printf("1or2or3\n");
        input_number = _getch();
    }

    if (input_number == '1') { return 1; }
    else if (input_number == '2') { return 2; }
    else if (input_number == '3') { return 3; }
    //!ESCキーなら
    else if (input_number == ESC)
    {
        system("cls");
        m_esc = true;
    }

    return 0;
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

//!解放処理関数
void Inputter::Delete()
{
    delete p_instance;
    p_instance = nullptr;

}






