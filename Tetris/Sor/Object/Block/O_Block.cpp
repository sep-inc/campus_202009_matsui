#include "O_Block.h"

//!形配列(回転無し)
const __int8 Tetris_O_Block::m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,1,1,0,0,
	0,1,1,0,0,
	0,0,0,0,0,
	0,0,0,0,0
};

Tetris_O_Block::Tetris_O_Block(Tetris_Stage* stage_) :
	Tetris_BlockBase(stage_)
{
}

//!形更新(回転)関数
void Tetris_O_Block::SetBlockAngle(__int8 angle_)
{
	m_block = m_block_0;
}


Tetris_BlockBase* Tetris_O_Block::InstanceO_Block(Tetris_Stage* stage_)
{
	return static_cast<Tetris_BlockBase*>(new Tetris_O_Block(stage_));
}