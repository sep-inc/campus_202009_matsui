#ifndef INPUTTER_H_
#define INPUTTER_H_
#include <string>

class Inputter
{
public:
	Inputter() {}
	~Inputter() {}
	void InputStation();   //�w�����͊֐�

	const char* GetStartStationName() { return m_start_station_name; }   //�ŏ��̉w����Ԃ�
	const char* GetEndStationName() { return m_end_station_name; }       //�Ō�̉w����Ԃ�

private:
	/* Getter�p */
	char m_start_station_name[20];  //�ŏ��̉w��
	char m_end_station_name[20];    //�Ō�̉w��
};
#endif