#include "Myself.h"
#include "../Entity.h"

//!コンストラクタ
Tetris_Myself::Tetris_Myself(Tetris_BlockController* block_) :Tetris_Player_Base(block_)
{
	m_direction = Vec2(0, 0);  //!方向ベクトル
}

//!更新関数
void Tetris_Myself::Update()
{
	MoveBlock();  //!移動
	RoteBlock();  //!回転
}

//! 移動関数
void Tetris_Myself::MoveBlock()
{
	
	m_direction = g_inputter.InpuMoveKey();  //!方向ベクトル代入

	m_block->SetBlockPos((float)m_direction.x, (float)m_direction.y); //!ブロックの座標更新

	//!移動後何かに当たっている場合
	if (m_block->Collision() == true)
	{
		//!座標を戻す
		m_block->SetBlockPos((float)-m_direction.x, (float)-m_direction.y);
	}

}

//!回転関数
void Tetris_Myself::RoteBlock()
{
	//!右回転キーが押された場合
	if (g_inputter.GetRigthRoteKey() == true)
	{
		m_block->SetBlockAngle(-1);

		//!回転後何かに当たっている場合
		if (m_block->Collision() == true)
		{
			//!元に戻す
			m_block->SetBlockAngle(1);
		}
	}
	//!左回転キーが押された場合
	else if (g_inputter.GetLeftRoteKey() == true)
	{
		m_block->SetBlockAngle(1);

		//!回転後何かに当たっている場合
		if (m_block->Collision() == true)
		{
			//!元に戻す
			m_block->SetBlockAngle(-1);
		}
	}
}
