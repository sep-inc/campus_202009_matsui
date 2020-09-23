#include "Inputter.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

/* 入力待ち関数まとめ */
void Inputter::InputNumber()
{
    printf("移す場所を選んでください\n");
    printf("1or2or3\n");
    m_start_number = ReInputNumber();

    printf("送る場所を選んでください\n");
    printf("1or2or3\n");

    m_end_number = ReInputNumber();
}

/* 入力待ち関数 */
int Inputter::ReInputNumber()
{
    char input_number = 0;
    char input_number2 = 0;

    input_number = _getch();

    while (input_number != '1' && input_number != '2' && input_number != '3')
    {
        printf("もう一度選んでください\n");
        printf("1or2or3\n");
        input_number = _getch();
    }

    if (input_number == '1') { return 1; }
    else if (input_number == '2') { return 2; }
    else if (input_number == '3') { return 3; }

}
