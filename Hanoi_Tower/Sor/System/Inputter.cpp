#include "Inputter.h"
#include <stdio.h>
#include <string.h>

/* ���͑҂��֐� */
void Inputter::InputNumber()
{
    printf("�ڂ��ꏊ��I��ł�������\n");
    printf("1or2or3\n");
    scanf_s("%d", &m_start_number);

    /* �ړ��ԍ��ȏ�A�ȉ��̎�������x���͂����� */
    while (m_start_number < 1 || m_start_number > 3)
    {
        scanf_s("%d", &m_start_number);
    }
   

    printf("����ꏊ��I��ł�������\n");
    scanf_s("%d", &m_end_number);
}
