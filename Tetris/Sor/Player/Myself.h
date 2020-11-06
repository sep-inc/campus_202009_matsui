#ifndef TETRIS_MYSELF_H_
#define TETRIS_MYSELF_H_
#include "../Utility/Vec2.h"
#include "../Definition.h"
#include "PlayerBase.h"
/**
*@clss   描画クラス
*@brief  各オブジェクトの情報をもとに描画する
*/

class Tetris_Myself :public Tetris_Player_Base
{
public:
    Tetris_Myself(Tetris_BlockController* block_);
    ~Tetris_Myself() {}

    /**
　   * @brief  更新関数
     * @detail 各更新処理をまとめた関数
　   */
    virtual void Update()override;

    /**
　   * @brief  移動関数
     * @detail 現在落下しているブロックの移動を行う
　   */
    virtual void  MoveBlock()override;

    /**
　   * @brief  回転関数
     * @detail 現在落下しているブロックの回転を行う
　   */
    virtual void  RoteBlock()override;


};

#endif