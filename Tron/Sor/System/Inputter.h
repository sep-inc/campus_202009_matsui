#ifndef INPUTTER_H_
#define INPUTTER_H_
#include "../Utility/Vec.h"
#define ESC 27    //!Esc番号
#define ENTER 13  //!Enter番号
#define SPACE 32  //!Enter番号


/**
*@clss   入力クラス
*@brief  入力情報を保存
*/
class Inputter
{
public:
    Inputter() {}
    ~Inputter() {}

    /**
     * @brief  ジャンプキー入力待ち関数
     * @detail ジャンプキーが押されたらtrueを返す
     */
    Vec InpuMoveKey();

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

private:
    bool m_esc;  //!ESC時終了フラグ
};

#endif