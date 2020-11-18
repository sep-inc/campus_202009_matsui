#include "AIController.h"
#include <stdlib.h>

//!コンストラクタ
Tetris_AIController::Tetris_AIController() :
	m_ai{ nullptr },
	m_direction(Vec2(0, 0))	//!方向ベクトル
{
}

Tetris_AIController::~Tetris_AIController()
{
	DeleteAI();
}

//!初期化関数
void Tetris_AIController::Reset()
{
	//!各AI初期化
	m_ai->Reset();
}

bool Tetris_AIController::DecisionFlg()
{
	if (m_ai->GetDecisionFlg() == true)
	{
		return true;
	}
	return false;
}

//!解放関数
void Tetris_AIController::DeleteAI()
{
	delete m_ai;
}
