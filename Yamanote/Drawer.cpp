#include "Drawer.h"

/* �\���֐� */
void Drawer::Draw()
{
	printf("�E���%d���ł��B\n", m_right_total_value);
	printf("�����%d���ł��B\n", m_left_total_value);

}

void Drawer::SetRightTotalValue(__int8 right_time_, __int8 left_time_)
{
	m_right_total_value = right_time_;
	m_left_total_value = left_time_;

}
