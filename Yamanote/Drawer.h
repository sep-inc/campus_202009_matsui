#ifndef DRAWER_H_
#define DRAWER_H_
#include <string>

class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Draw();		            //�\������
	void SetRightTotalValue(__int8 right_time_, __int8 left_time_);
	void SetFirstTime(__int8 first_time_);

	void NoneName(bool m_no_name_); // ���O���Ԉ���Ă��邩�ǂ����̃t���OSetter

private:
	__int8 m_right_total_value;  //�E��]�\���p���v�l
	__int8 m_left_total_value;   //����]�\���p���v�l

	__int8 m_first_time;   //����]�\���p���v�l


	bool m_no_name;
};
#endif