#include "Inputter.h"
#include <stdio.h>
#include <conio.h>

//!���͑҂��֐��܂Ƃ�
void Inputter::InputNumber()
{
    char input_font = 0;    //!�����ۑ��p
    char input_number = 0;  //!�����ۑ��p


    printf("A,B,C��I��ł�������\n");
    input_font = _getch();

    printf("1,2,3,��I��ł�������\n");
    input_number = _getch();

    //!�����𐔎��ɕϊ�
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
   
    //!�����𐔎��ɕϊ�
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


