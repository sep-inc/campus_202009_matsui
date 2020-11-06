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
　   * @brief  使用ブロック更新関数
     * @detail 次使うブロックの形をブロック配列ポインタに代入する
　   */
     virtual void SetBlock();

private:
    static const __int8 m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH]; //!形配列(回転ないし)
};

#endif