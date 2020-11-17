#include "L_Block.h"

//!形配列(0度)
const __int8 Tetris_L_Block::m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,0,1,0,
	0,1,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0
};

//!形配列(90度)
const __int8 Tetris_L_Block::m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,1,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,0,0,0
};

//!形配列(180度)
const __int8 Tetris_L_Block::m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,0,0,0,
	0,1,1,1,0,
	0,1,0,0,0,
	0,0,0,0,0
};

//!形配列(270度)
const __int8 Tetris_L_Block::m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,1,1,0,
	0,0,0,0,0
};

Tetris_L_Block::Tetris_L_Block(Tetris_Stage* stage_) :
	Tetris_BlockBase(stage_)
{
}

//!形更新(回転)関数
void Tetris_L_Block::SetBlockAngle(__int8 angle_)
{
	m_angle_type += angle_;

	if (m_angle_type < 0)
	{
		m_angle_type = 3;
	}
	else if (m_angle_type > 3)
	{
		m_angle_type = 0;
	}

	switch (m_angle_type)
	{
	case 0:
		m_block = m_block_0;
		break;
	case 1:
		m_block = m_block_90;
		break;
	case 2:
		m_block = m_block_180;
		break;
	case 3:
		m_block = m_block_270;
		break;
	default:
		break;
	}
}

Tetris_BlockBase* Tetris_L_Block::InstanceL_Block(Tetris_Stage* stage_)
{
	return static_cast<Tetris_BlockBase*>(new Tetris_L_Block(stage_));
}
