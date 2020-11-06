#include "BlockBase.h"
#include "../../Entity.h"

//!コンストラクタ
Tetris_BlockBase::Tetris_BlockBase(Tetris_Stage* stage_) :
	m_stage(stage_),   //!ステージアドレス
	m_font("■"),
	m_pos_x(2.0f), m_pos_y(0.0f), m_next_pos_x(m_pos_x),m_next_pos_y(m_pos_y),
	m_speed(0.1f),
	m_stop(false)
{
}

//!初期化関数(繰り返し)
void Tetris_BlockBase::Reset()
{
	m_pos_x = 2.0f;  //!座標
	m_pos_y = 0.0f;	 //!座標

	m_next_pos_x = m_pos_x; //!移動後座標
	m_next_pos_y = m_pos_y; //!移動後座標 

	m_stop = false;
}

//!更新関数
void Tetris_BlockBase::Update()
{
	Move();
}

//!移動関数
void Tetris_BlockBase::Move()
{
	m_next_pos_y += m_speed; //!落下
	
	//!床、もしくはBlockに当たった場合
	if (Collision() == true)
	{
		SetStageBuffer();
		m_stop = true;
	}
	else
	{
		m_pos_y = m_next_pos_y;
	}

}

//!ステージ更新関数
void Tetris_BlockBase::SetStageBuffer()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				m_stage->SetUpBlock(Vec2((int)floor(m_pos_x + x), (int)floor(m_pos_y + y)), (OBJECT_TYPE)m_block[y][x]);
			}
		}
	}
}

//!予測枠更新関数
void Tetris_BlockBase::SetNextBlockBuffer()
{
	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				m_stage->SetUpNextBlock(Vec2(x, y), (OBJECT_TYPE)m_block[y][x]);
			}
		}
	}
}

//!ブロック描画情報代入関数
void Tetris_BlockBase::SetUpDrawBuffer(GAME_TYPE type_)
{
	__int8 flame = 1;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				g_drawer.SetUpBuffer(Vec2((int)floor(m_pos_x + x + flame), (int)floor(m_pos_y + y + flame)), m_font, type_);
			}
		}
	}
	
}

//!当たり判定関数
bool Tetris_BlockBase::Collision()
{
	__int8 value = 3;

	for (int y = 0; y < BLOCK_HEIGHT; y++)
	{
		for (int x = 0; x < BLOCK_WIDTH; x++)
		{
			if (m_block[y][x] == 1)
			{
				value = m_block[y][x] - m_stage->SearchStage(Vec2((int)floor(m_next_pos_x + x), (int)floor(m_next_pos_y + y)));
			}
		
			if (value <= 0)
			{
				return true;
			}
		}
	}

	return false;
}
