﻿#ifndef INPUTTER_H_
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
    * @brief  移動キー入力関数
    * @detail ジャンプキーが押されたらtrueを返す
    */
    Vec2 InpuMoveKey();

    /**
     * @brief  回転キー入力関数
     * @detail 回転キー押された場合押された回転方向のフラグをtrueにする
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
    const bool GetStartKey() { return m_start; }

    const bool GetRigthRoteKey() { return m_right_rote; }
    const bool GetLeftRoteKey() { return m_left_rote; }


private:
    bool m_esc;  //!ESC時終了フラグ
    bool m_start;

    bool m_right_rote;
    bool m_left_rote;

};

#endif