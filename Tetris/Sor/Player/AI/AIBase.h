#ifndef TETRIS_AIBASE_H_
#define TETRIS_AIBASE_H_
#include "../../Utility/Vec2.h"
#include "../../Definition.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_AIBase
{
public:
    Tetris_AIBase() {}
    ~Tetris_AIBase() {}

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    virtual void Update() = 0;

    /**
　   * @brief  初期化関数
     * @detail コンティニュー後値が残っていると困るメンバ変数の初期化
　   */
    virtual void Reset() = 0;

    virtual void SearchFixedPos() {}

    bool GetDecisionFlg() { return m_pos_decision; }

protected:
    bool m_pos_decision;

};

#endif