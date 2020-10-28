#include "TronPlayer.h"
#include "../../../../System/DrawController.h"
#include <stdio.h>

void TronPlayer::Reset(Vec2 pos_, TronStage* p_stage_)
{
	m_stage = p_stage_;  //!ステージクラスのアドレス代入
	m_pos = pos_;       //!座標
	m_direction = Vec2(0, 0); //!移動方向ベクトル
	m_deth = false;          //!死亡フラグ
	m_move = false;          //!移動フラグ

	//!ステージクラスに情報を送る
	m_stage->SetUpStageBuffer(m_pos, m_player_type);
}

//!更新関数
void TronPlayer::Update()
{
	SelectDirection(); //!移動方向選択

	//!移動先が死ぬ場所かどうか(死んでいる場合は移動しない)
	if (m_deth == false)
	{
		Move();  //!移動
	}

	//!ステージに移動後の情報を送る
	m_stage->SetUpStageBuffer(m_pos, m_player_type);
}

//!移動関数
void TronPlayer::Move()
{
	m_pos.x += m_direction.x;
	m_pos.y += m_direction.y;
}

//!当たり判定
bool TronPlayer::Collision()
{
	Vec2 pos = m_pos;   //!座標保存用
	pos.x += m_direction.x;
	pos.y += m_direction.y;

	//!移動先で何かにぶつかっているかどうか
	if (m_stage->SearchObjectType(pos) != TRON_NONE)
	{
		return true;
	}

	return false;
}

//!描画配列代入関数
void TronPlayer::SetUpDrawBuffer()
{
	DrawController::Instance()->SetUpBuffer(m_pos, m_draw_font);
}

//!結果表示関数
void TronPlayer::ResultDraw()
{
	if (m_deth == true)
	{
		switch (m_player_type)
		{
		case TRON_MYSELF:
			printf("あなたの負けです。\n");
			break;
		case TRON_ENEMY:
			printf("あなたの勝ちです。\n");
			break;
		default:
			break;
		}
	}
}

