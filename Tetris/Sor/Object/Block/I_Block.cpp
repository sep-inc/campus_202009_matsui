#include "I_Block.h"

//!形配列(0度)
const __int8 Tetris_I_Block::m_block_0[BLOCK_HEIGHT][BLOCK_WIDTH]=
{
	0,0,0,0,0,
	0,0,0,0,0,
	0,1,1,1,1,
	0,0,0,0,0,
	0,0,0,0,0
};

//!形配列(90度)
const __int8 Tetris_I_Block::m_block_90[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,0,0,0
};

//!形配列(180度)
const __int8 Tetris_I_Block::m_block_180[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,0,0,0,
	1,1,1,1,0,
	0,0,0,0,0,
	0,0,0,0,0
};

//!形配列(270度)
const __int8 Tetris_I_Block::m_block_270[BLOCK_HEIGHT][BLOCK_WIDTH] =
{
	0,0,0,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0,
	0,0,1,0,0
};

Tetris_I_Block::Tetris_I_Block(Tetris_Stage* stage_):
	Tetris_BlockBase(stage_)
{}

//!形更新(回転)関数
void Tetris_I_Block::SetBlockAngle(__int8 angle_)
{
	//!現在角度を回転方向分加算する
	m_angle_type += angle_;

	//!0度以下の場合
	if (m_angle_type < BLOCK_ANGLE_TYPE::ZERO)
	{
		//!270度にする
		m_angle_type = BLOCK_ANGLE_TYPE::THREE;
	}
	//!270度以上の場合
	else if (m_angle_type > BLOCK_ANGLE_TYPE::THREE)
	{
		//!0度にする
		m_angle_type = BLOCK_ANGLE_TYPE::ZERO;
	}

	switch (m_angle_type)
	{
	case BLOCK_ANGLE_TYPE::ZERO:
		m_block = m_block_0;
		break;
	case BLOCK_ANGLE_TYPE::ONE:
		m_block = m_block_90;
		break;
	case BLOCK_ANGLE_TYPE::TWO:
		m_block = m_block_180;
		break;
	case BLOCK_ANGLE_TYPE::THREE:
		m_block = m_block_270;
		break;
	default:
		break;
	}
	
}