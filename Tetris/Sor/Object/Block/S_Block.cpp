#include "S_Block.h"

//!形配列(0度)
const __int8 Tetris_S_Block::m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,1,0,
	0,1,1,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};

//!形配列(90度)
const __int8 Tetris_S_Block::m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,1,1,0,
	0,0,0,1,0,
	0,0,0,0,0
};

//!形配列(180度)
const __int8 Tetris_S_Block::m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,0,0,0,
	0,0,1,1,0,
	0,1,1,0,0,
	0,0,0,0,0
};

//!形配列(270度)
const __int8 Tetris_S_Block::m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,1,0,0,0,
	0,1,1,0,0,
	0,0,1,0,0,
	0,0,0,0,0
};

Tetris_S_Block::Tetris_S_Block(Tetris_Stage* stage_) :
	Tetris_BlockBase(stage_)
{
}

//!使用ブロック更新関数
void Tetris_S_Block::SetBlock()
{
	m_block = m_block_0;
}
