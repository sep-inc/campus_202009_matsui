#ifndef INPUTTER_H_
#define INPUTTER_H_
#include "../Utility/Vec2.h"
/**
*@clss   入力クラス
*@brief  入力情報を保存
*/

#define ESC 27    //!Esc番号
#define ENTER 13  //!Enter番号

class Inputter
{
public:
    Inputter() {}
    ~Inputter() {}

    /**
    * @brief  ジャンプキー入力待ち関数
    * @detail ジャンプキーが押されたらtrueを返す
    */
    Vec2 InpuMoveKey();

    /**
     * @brief  ジャンプキー入力待ち関数
     * @detail ジャンプキーが押されたらtrueを返す
     */
    void InpuRoteKey();

    /**
     * @brief  ゲーム開始入力待ち関数
     * @detail 指定キーが押されたらゲームを始める
     */
    bool InputStartKey();

    /**
     * @brief  ctrl+c入力関数
     * @detail ctrl+cが押されたときにゲームを終了する
     */
    void InputForcedKey();

    /**
     * @brief  コンティニュー関数
     * @return ゲーム終了時続けるかどうかを判定
     */
    bool InputContinue();

    const bool GetESCKey() { return m_esc; }
    const bool GetRigthRoteKey() { return m_right_rote; }
    const bool GetLeftRoteKey() { return m_left_rote; }


private:
    bool m_esc;  //!ESC時終了フラグ

    bool m_right_rote;
    bool m_left_rote;

};

#endif