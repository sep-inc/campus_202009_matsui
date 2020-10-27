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
    Inputter();
    ~Inputter() {}

    /**
     * @brief  インスタンス化関数
     */
    static Inputter* Instance();

    /**
     * @brief  メンバ変数リセット関数
     * @detail 毎ゲーム開始時、選択シーン移行時に値を初期化する
     */
    void Reset();

    /**
     * @brief  ジャンプキー入力待ち関数
     * @detail ジャンプキーが押されたらtrueを返す
     */
    Vec2 InpuMoveKey();

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

    /**
     * @brief  ESCキー(終了キー)フラグGetter関数
     * @return ESCキー(終了キー)が押されたかどうかを返す
     */
    const bool GetESCKey() { return m_esc; }

    /**
     * @brief  決定キーフラグGetter関数
     * @return 決定キーが押されたかどうかを返す
     */
    const bool GetDecideKey() { return m_decide; }

private:
    static Inputter* p_instance;

    bool m_decide;  //!決定キーフラグ
    bool m_esc;     //!ESC時終了フラグ
};

#endif