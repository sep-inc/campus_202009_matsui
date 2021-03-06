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
    Inputter(){}
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
    * @brief  ジャンプキー入力待ち関数
    * @detail ジャンプキーが押されたらtrueを返す
    */
    bool InputJumpKey();

    /**
     * @brief  ゲーム開始入力待ち関数
     * @detail 指定キーが押されたらゲームを始める
     */
    bool InputStartKey();

    /**
    * @brief  入力待ち関数まとめ
    * @detail 選んだ文字と数字を値に代入する
    */
    void InputNumber();

    void InputNumber2();   //入力した値をメンバ変数に保存する
    int ReInputNumber();   //入力した値をメンバ変数に保存する

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

    /**
    * @brief  キャンセルフラグ参照関数
    * @return キャンセルボタンが押されたかどうかを返す
    */
    const bool GetSelectCancel() { return m_cancel; }

    const int GetStartNumber() { return m_start_number; }   //移動元の番号を返す
    const int GetEndNumber() { return m_end_number; }       //移動先の番号を返す

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
     * @brief 解放処理関数
     */
    void Delete();

private:
    static Inputter* p_instance;

    bool m_decide;  //!決定キーフラグ
    bool m_cancel;   //!キャンセル時用
    bool m_esc;     //!ESC時終了フラグ

    //!数字キー用
    int m_start_number;    
    int m_end_number;      

    __int8 m_input_font;    //!入力文字変数
    __int8 m_input_number;  //!入力数字変数
};

#endif