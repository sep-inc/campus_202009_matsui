#include "Inputter.h"

void Inputter::InputStation()
{
	printf("�n�܂�̉w������͂��Ă��������B\n");
    scanf_s("%s", &m_start_station_name, 64);

    printf("�I���̉w������͂��Ă��������B\n");
    scanf_s("%s", &m_end_station_name, 64);
}
