#include "Inputter.h"

void Inputter::InputStation()
{
	printf("始まりの駅名を入力してください。\n");
    scanf_s("%s", &m_start_station_name, 64);

    printf("終わりの駅名を入力してください。\n");
    scanf_s("%s", &m_end_station_name, 64);
}
