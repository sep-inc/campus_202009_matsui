#ifndef TETRIS_Z_BLOCK_H_
#define TETRIS_Z_BLOCK_H_
#include "BlockBase.h"
/**
*@clss   Z型Blockクラス
*@brief  Z型のブロックの情報を持つ
*/

class Tetris_Z_Block :public Tetris_BlockBase
{
public:
    Tetris_Z_Block(Tetris_Stage* stage_);
    ~Tetris_Z_Block() {}

    /**
　   * @brief  使用ブロック更新関数
     * @detail 次使うブロックの形をブロック配列ポインタに代入する
　   */
    virtual void SetBlock();

private:
    static const __int8 m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(0度)
    static const __int8 m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(90度)
    static const __int8 m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(180度)
    static const __int8 m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(270度)
};

#endif