#include "Inputter.h"
#include <stdio.h>
#include <string.h>
#include <conio.h>

/* ���͑҂��֐��܂Ƃ� */
void Inputter::InputNumber()
{
    printf("�ڂ��ꏊ��I��ł�������\n");
    printf("1or2or3\n");
    m_start_number = ReInputNumber();

    printf("����ꏊ��I��ł�������\n");
    printf("1or2or3\n");

    m_end_number = ReInputNumber();
}

/* ���͑҂��֐� */
int Inputter::ReInputNumber()
{
    char input_number = 0;
    char input_number2 = 0;

    input_number = _getch();

    while (input_number != '1' && input_number != '2' && input_number != '3')
    {
        printf("������x�I��ł�������\n");
        printf("1or2or3\n");
        input_number = _getch();
    }

    if (input_number == '1') { return 1; }
    else if (input_number == '2') { return 2; }
    else if (input_number == '3') { return 3; }

}
