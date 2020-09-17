#include "Inputter.h"
#include <conio.h>

/* 入力待ち関数 */
void Inputter::InputStation()
{
	printf("始まりの駅名を入力してください。\n");
    scanf_s("%s", &m_start_station_name, 64);

    printf("終わりの駅名を入力してください。\n");
    scanf_s("%s", &m_end_station_name, 64);
}

/* 終了待ち関数 */
bool Inputter::InputEnd()
{
    int end;  //終了キー番号保存

    printf("終了する場合Escを、続ける場合他のキーを押してください\n");

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
