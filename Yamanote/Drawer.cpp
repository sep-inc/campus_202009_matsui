#include "Drawer.h"

/* 表示関数 */
void Drawer::Draw()
{
	/* 駅名が間違っている場合 */
	if (m_no_name == true)
	{
		printf("駅名が間違っています。\n");
	}
	else
	{
		printf("右回り%d分です。\n", m_right_total_value);
		printf("左回り%d分です。\n", m_left_total_value);

		printf("中央線を含め最短ルートで移動した場合%d分掛かります。\n", m_first_time);
	}

	
}

/* 表示値をset */
void Drawer::SetRightTotalValue(__int8 right_time_, __int8 left_time_)
{
	m_right_total_value = right_time_;
	m_left_total_value = left_time_;

}

void Drawer::SetFirstTime(__int8 first_time_)
{
	m_first_time = first_time_;
}

/* 名前が間違っているかどうかのフラグSetter */
void Drawer::NoneName(bool m_no_name_)
{
	m_no_name = m_no_name_;
}
