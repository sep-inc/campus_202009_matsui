#ifndef INPUTTER_H_
#define INPUTTER_H_

/**
*@clss   ���̓N���X 
*@brief  ���͏���ۑ�
*/
class Inputter
{
public:
    Inputter():m_input_font(0), m_input_number(0){}
    ~Inputter() {}

    /**
     * @brief  ���͑҂��֐��܂Ƃ�
     * @detail �I�񂾕����Ɛ�����l�ɑ������
     */
    void InputNumber();   


    
    /**
     * @brief  �I�𕶎��Q�Ɗ֐�
     * @return ���͂���������ς���
     */
    __int8 GetSelectFont() { return m_input_font; }
    
    /**
     * @brief  �I�𐔎��Q�Ɗ֐�
     * @return ���͂���������ς���
     */
    __int8 GetSelectNumber() { return m_input_number; }

private:
    __int8 m_input_font;    //!���͕����ϐ�
    __int8 m_input_number;  //!���͐����ϐ�

};

#endif