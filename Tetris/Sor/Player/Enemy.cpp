#include "Enemy.h"
#include <random>

//!コンストラクタ
Tetris_Eenmy::Tetris_Eenmy(Tetris_BlockController* block_) :
	Tetris_Player_Base(block_),
	m_ai(nullptr)
{
	if (m_ai == nullptr) { m_ai = new Tetris_AIController(); }
	SetDirection();
}

//!更新関数
void Tetris_Eenmy::Update()
{
	MoveBlock();  //!移動
	RoteBlock();  //!回転
}

//!移動関数
void Tetris_Eenmy::MoveBlock()
{
	if (m_ai->DecisionFlg() == true) { m_direction = Vec2(0, 1); }

	m_block->SetBlockPos((float)m_direction.x, (float)m_direction.y); //!ブロックの座標更新

	//!移動後何かに当たっている場合
	if (m_block->Collision() == true)
	{
		//!座標を戻す
		m_block->SetBlockPos((float)-m_direction.x, (float)-m_direction.y);

		if (m_direction.y == 0)
		{
			m_wall_hit = true;
			m_direction.x = -m_direction.x;
		}
		else
		{
			SetDirection();
		}
	}
	else
	{
		m_wall_hit = false;
	}
}

//!回転関数
void Tetris_Eenmy::RoteBlock()
{
	//!右回転キーが押された場合
	if (m_wall_hit == true)
	{
		m_block->SetBlockAngle(-1);

		//!回転後何かに当たっている場合
		if (m_block->Collision() == true)
		{
			//!元に戻す
			m_block->SetBlockAngle(1);
		}
	}
}

void Tetris_Eenmy::SetDirection()
{
	DIRECTION_TYPE direction;

	direction = static_cast<DIRECTION_TYPE>(rand() % RIGHT + LEFT);//!ランダム選択用移動方向ベクトル

	switch (direction)
	{
	case DIRECTION_TYPE::LEFT:
		m_direction = Vec2(-1, 0);
		break;
	case DIRECTION_TYPE::RIGHT:
		m_direction = Vec2(1, 0);
		break;
	default:
		break;
	}
}
