#ifndef TETRIS_O_BLOCK_H_
#define TETRIS_O_BLOCK_H_
#include "BlockBase.h"

/**
*@clss   O型Blockクラス
*@brief  O型のブロックの情報を持つ
*/

class Tetris_O_Block :public Tetris_BlockBase
{
public:
    Tetris_O_Block(Tetris_Stage* stage_);
    ~Tetris_O_Block() {}

    /**
　   * @brief  形更新(回転)関数関数
     * @param (angle_) 回転方向(1か-1か)
     * @detail 現在移動しているブロックの形を回転させる
　   */
    virtual void SetBlockAngle(__int8 angle_)override;

    static Tetris_BlockBase* InstanceO_Block(Tetris_Stage* stage_);

private:
    static const __int8 m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(回転ないし)
};

#endif