#include "OX_GameEnemy.h"
#include "../../../System/DrawController.h"
#include <random>

//!初期化関数
void OX_GameEnemy::Init()
{
	m_pos = Vec2(-5, -5);  //!表示されないよう見えない位置に初期化

	//!0～2の乱数で初期化
	m_randm_number.x = rand() % BORD_SIZE;
	m_randm_number.y = rand() % BORD_SIZE;
}

//!描画座標代入関数
void OX_GameEnemy::SetUpDrawBuffer()
{
	DrawController::Instance()->SetUpBuffer(m_pos, "×");
}

//!配置
void OX_GameEnemy::Put(OX_GameBoard* board_)
{
	//!乱数で出した位置が置けるか。また、配置できる場所があるかどうか調べる
	while (board_->PutSearch(m_randm_number.x, m_randm_number.y) == false
		&& board_->SearchNumber() == true)
	{
		//!配置できない場合もう一度乱数を出す
		m_randm_number.x = rand() % BORD_SIZE;
		m_randm_number.y = rand() % BORD_SIZE;
	}

	m_pos = Vec2(m_randm_number.x, m_randm_number.y);   //座標更新

	//!配置場所があった場合
	if (board_->SearchNumber() == true)
	{
		board_->SetPiecePos(m_pos, OX_GAME_OBJECT_TYPE::OX_GAME_ENEMY_PIECE);   //盤配列に座標代入
	}
}
