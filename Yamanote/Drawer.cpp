#include "Drawer.h"

/* 表示関数 */
void Drawer::Draw()
{
	printf("右回り%d分です。\n", m_right_total_value);
	printf("左回り%d分です。\n", m_left_total_value);

}

void Drawer::SetRightTotalValue(__int8 right_time_, __int8 left_time_)
{
	m_right_total_value = right_time_;
	m_left_total_value = left_time_;

}
