#include "Inputter.h"
#include <stdio.h>
#include <string.h>

/* 入力待ち関数 */
void Inputter::InputNumber()
{
    printf("移す場所を選んでください\n");
    printf("1or2or3\n");
    scanf_s("%d", &m_start_number);

    /* 移動番号以上、以下の時もう一度入力し直す */
    while (m_start_number < 1 || m_start_number > 3)
    {
        scanf_s("%d", &m_start_number);
    }
   

    printf("送る場所を選んでください\n");
    scanf_s("%d", &m_end_number);
}
