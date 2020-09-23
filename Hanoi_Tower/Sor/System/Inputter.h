#ifndef INPUTTER_H_
#define INPUTTER_H_

class Inputter
{
public:
    Inputter() {}
    ~Inputter() {}

    void InputNumber();   //入力した値をメンバ変数に保存する
    int ReInputNumber();   //入力した値をメンバ変数に保存する


    int GetStartNumber() { return m_start_number; }   //移動元の番号を返す
    int GetEndNumber() { return m_end_number; }       //移動先の番号を返す

private:
    int m_start_number;    //元の場所
    int m_end_number;      //移す場所

};

#endif