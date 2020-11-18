#include "T_Block.h"

//!形配列(0度)
const __int8 Tetris_T_Block::m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,1,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0
};

//!形配列(90度)
const __int8 Tetris_T_Block::m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,1,1,0,0,
	0,0,1,0,0,
	0,0,0,0,0
};

//!形配列(180度)
const __int8 Tetris_T_Block::m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,0,0,0,
	0,1,1,1,0,
	0,0,1,0,0,
	0,0,0,0,0
};

//!形配列(270度)
const __int8 Tetris_T_Block::m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,1,1,0,
	0,0,1,0,0,
	0,0,0,0,0
};

Tetris_T_Block::Tetris_T_Block(Tetris_Stage* stage_) :
	Tetris_BlockBase(stage_)
{
}

//!形更新(回転)関数
void Tetris_T_Block::SetBlockAngle(__int8 angle_)
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
	case BLOCK_ANGLE_TYPE::ZERO:
		m_block = m_block_0;
		m_block_min_array = Vec2(1, 1);
		m_block_max_array = Vec2(3, 2);
		break;
	case BLOCK_ANGLE_TYPE::ONE:
		m_block = m_block_90;
		m_block_min_array = Vec2(1, 1);
		m_block_max_array = Vec2(2, 3);
		break;
	case BLOCK_ANGLE_TYPE::TWO:
		m_block = m_block_180;
		m_block_min_array = Vec2(1, 2);
		m_block_max_array = Vec2(3, 3);
		break;
	case BLOCK_ANGLE_TYPE::THREE:
		m_block = m_block_270;
		m_block_min_array = Vec2(2, 1);
		m_block_max_array = Vec2(3, 3);
		break;
	default:
		break;
	}
}

Tetris_BlockBase* Tetris_T_Block::InstanceT_Block(Tetris_Stage* stage_)
{
	return static_cast<Tetris_BlockBase*>(new Tetris_T_Block(stage_));
}