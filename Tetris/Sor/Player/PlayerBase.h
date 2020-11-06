#ifndef TETRIS_PLAYERBASE_H_
#define TETRIS_PLAYERBASE_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "../Object/Block/BlockController.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Player_Base
{
public:
    Tetris_Player_Base(Tetris_BlockController* block_);
    ~Tetris_Player_Base() {}

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    virtual void Update() = 0;

    /**
　   * @brief  移動関数
     * @detail 現在落下しているブロックの移動を行う
　   */
    virtual void MoveBlock() {}

    /**
　   * @brief  回転関数
     * @detail 現在落下しているブロックの回転を行う
　   */
    virtual void RoteBlock() {}


protected:
    Tetris_BlockController* m_block;   //!ブロックアドレス

    Vec2 m_direction;   //!方向ベクトル
};

#endif