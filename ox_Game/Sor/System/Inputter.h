#ifndef INPUTTER_H_
#define INPUTTER_H_

/**
*@clss   入力クラス 
*@brief  入力情報を保存
*/
class Inputter
{
public:
    Inputter():m_input_font(0), m_input_number(0){}
    ~Inputter() {}

    /**
     * @brief  入力待ち関数まとめ
     * @detail 選んだ文字と数字を値に代入する
     */
    void InputNumber();   


    
    /**
     * @brief  選択文字参照関数
     * @return 入力した文字を変えす
     */
    __int8 GetSelectFont() { return m_input_font; }
    
    /**
     * @brief  選択数字参照関数
     * @return 入力した数字を変えす
     */
    __int8 GetSelectNumber() { return m_input_number; }

private:
    __int8 m_input_font;    //!入力文字変数
    __int8 m_input_number;  //!入力数字変数

};

#endif