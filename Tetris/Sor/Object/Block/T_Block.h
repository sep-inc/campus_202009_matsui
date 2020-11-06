#ifndef TETRIS_T_BLOCK_H_
#define TETRIS_T_BLOCK_H_
#include "BlockBase.h"

/**
*@clss   T型Blockクラス
*@brief  T型のブロックの情報を持つ
*/

class Tetris_T_Block :public Tetris_BlockBase
{
public:
    Tetris_T_Block(Tetris_Stage* stage_);
    ~Tetris_T_Block() {}

    /**
　   * @brief  形更新(回転)関数関数
     * @param (angle_) 回転方向(1か-1か)
     * @detail 現在移動しているブロックの形を回転させる
　   */
    virtual void SetBlockAngle(__int8 angle_)override;

private:
    static const __int8 m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(0度)
    static const __int8 m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(90度)
    static const __int8 m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(180度)
    static const __int8 m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(270度)
};

#endif