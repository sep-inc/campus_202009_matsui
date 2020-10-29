#include "Inputter.h"
#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include <signal.h>

Inputter* Inputter::p_instance = 0;  //!実体

//!コンストラクタ
Inputter::Inputter() :
    m_decide(false), m_esc(false)
{}

//!インスタンス化関数
Inputter* Inputter::Instance()
{
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





