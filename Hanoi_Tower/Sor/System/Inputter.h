#ifndef INPUTTER_H_
#define INPUTTER_H_

class Inputter
{
public:
    Inputter() {}
    ~Inputter() {}

    void InputNumber();   //���͂����l�������o�ϐ��ɕۑ�����

    int GetStartNumber() { return m_start_number; }   //�ړ����̔ԍ���Ԃ�
    int GetEndNumber() { return m_end_number; }       //�ړ���̔ԍ���Ԃ�

private:
    int m_start_number;    //���̏ꏊ
    int m_end_number;      //�ڂ��ꏊ

};

#endif