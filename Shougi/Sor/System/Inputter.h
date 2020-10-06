#ifndef INPUTTER_H_
#define INPUTTER_H_
#define ESC 27    //!Esc番号
#define ENTER 13  //!Enter番号

/**
*@clss   入力クラス
*@brief  入力情報を保存
*/
class Inputter
{
public:
    Inputter() :m_input_font(0), m_input_number(0), m_cancel(false){}
    ~Inputter() {}

    /**
     * @brief  数字入力待ち関数
     * @detail 選んだ数字を値に代入する
     */
    void InputNumber();

    /**
     * @brief  文字入力待ち関数
     * @detail 選んだ文字を値に代入する
     */
    void InputFont();

    /**
     * @brief  ctrl+c入力関数
     * @detail ctrl+cが押されたときにゲームを終了する
     */
    void InputEnd();       

    /**
     * @brief  選択文字参照関数
     * @return 入力した文字を変えす
     */
    const __int8 GetSelectFont() { return m_input_font; }

    /**
     * @brief  選択数字参照関数
     * @return 入力した数字を変えす
     */
    const __int8 GetSelectNumber() { return m_input_number; }

    /**
     * @brief  キャンセルフラグ参照関数
     * @return キャンセルボタンが押されたかどうかを返す
     */
    const bool GetSelectCancel() { return m_cancel; }


    /**
     * @brief  コンティニュー関数
     * @return ゲーム終了時続けるかどうかを判定
     */
    bool InputContinue();       

private:
    __int8 m_input_font;    //!入力文字変数
    __int8 m_input_number;  //!入力数字変数

    bool m_cancel;   //!キャンセル時用
    bool m_end;   //!キャンセル時用

};

#endif