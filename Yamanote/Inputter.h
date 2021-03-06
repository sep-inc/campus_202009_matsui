#ifndef INPUTTER_H_
#define INPUTTER_H_
#include <string>
#include <stdio.h>

#define ESC 27  //Esc番号

class Inputter
{
public:
	Inputter() {}
	~Inputter() {}
	void InputStation();   //駅名入力関数
	bool InputEnd();       //終了キー入力関数


	const char* GetStartStationName() { return m_start_station_name; }   //最初の駅名を返す
	const char* GetEndStationName() { return m_end_station_name; }       //最後の駅名を返す

private:
	/* Getter用 */
	char m_start_station_name[20];  //最初の駅名
	char m_end_station_name[20];    //最後の駅名
};
#endif