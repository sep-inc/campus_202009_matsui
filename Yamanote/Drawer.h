#ifndef DRAWER_H_
#define DRAWER_H_
#include <string>

class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Draw();		   //�\������
	void SetRightTotalValue(__int8 right_time_, __int8 left_time_);

private:
	__int8 m_right_total_value;  //�E��]�\���p���v�l
	__int8 m_left_total_value;   //����]�\���p���v�l
};
#endif