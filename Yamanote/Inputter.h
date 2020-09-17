#ifndef INPUTTER_H_
#define INPUTTER_H_
#include <string>
#include <stdio.h>

#define ESC 27  //Esc”Ô†

class Inputter
{
public:
	Inputter() {}
	~Inputter() {}
	void InputStation();   //‰w–¼“ü—ÍŠÖ”
	bool InputEnd();       //I—¹ƒL[“ü—ÍŠÖ”


	const char* GetStartStationName() { return m_start_station_name; }   //Å‰‚Ì‰w–¼‚ğ•Ô‚·
	const char* GetEndStationName() { return m_end_station_name; }       //ÅŒã‚Ì‰w–¼‚ğ•Ô‚·

private:
	/* Getter—p */
	char m_start_station_name[20];  //Å‰‚Ì‰w–¼
	char m_end_station_name[20];    //ÅŒã‚Ì‰w–¼
};
#endif