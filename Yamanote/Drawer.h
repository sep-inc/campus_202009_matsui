#ifndef DRAWER_H_
#define DRAWER_H_
#include <string>

class Drawer
{
public:
	Drawer() {}
	~Drawer() {}

	void Draw();		            //表示処理
	void SetRightTotalValue(__int8 right_time_, __int8 left_time_);
	void SetFirstTime(__int8 first_time_);

	void NoneName(bool m_no_name_); // 名前が間違っているかどうかのフラグSetter

private:
	__int8 m_right_total_value;  //右回転表示用合計値
	__int8 m_left_total_value;   //左回転表示用合計値

	__int8 m_first_time;   //左回転表示用合計値


	bool m_no_name;
};
#endif