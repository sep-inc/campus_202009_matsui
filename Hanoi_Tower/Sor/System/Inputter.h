#ifndef INPUTTER_H_
#define INPUTTER_H_

class Inputter
{
public:
    Inputter() {}
    ~Inputter() {}

    void InputNumber();   //“ü—Í‚µ‚½’l‚ğƒƒ“ƒo•Ï”‚É•Û‘¶‚·‚é

    int GetStartNumber() { return m_start_number; }   //ˆÚ“®Œ³‚Ì”Ô†‚ğ•Ô‚·
    int GetEndNumber() { return m_end_number; }       //ˆÚ“®æ‚Ì”Ô†‚ğ•Ô‚·

private:
    int m_start_number;    //Œ³‚ÌêŠ
    int m_end_number;      //ˆÚ‚·êŠ

};

#endif