﻿#include "RunGamePlayer.h"
#include "RunGameMapData.h"
#include "../../../Utility/Collision.h"
#include "../../../System/Inputter.h"
#include "../../../System/DrawController.h"

#include "../../../Definition.h"


const __int8 RunGamePlayer::PlayerInfo::m_width = 1;	    //!縦幅
const __int8 RunGamePlayer::PlayerInfo::m_height = 2;      //!横幅
const __int8 RunGamePlayer::PlayerInfo::m_gravity = 1;     //!重力
const __int8 RunGamePlayer::PlayerInfo::m_jump_power = 3;  //!ジャンプ力

const unsigned __int8 RunGamePlayer::PlayerInfo::m_speed_max = 9; //!移動までにかかるフレーム数


//!初期化関数
void RunGamePlayer::Reset()
{
	m_player_info.m_pos = Vec2(RUNGAME_PLAYER_POS_X, 3);     //!現在座標初期化
	m_player_info.m_next_pos = Vec2(m_player_info.m_pos.x + 1, m_player_info.m_pos.y); //!次のフレームの座標

	m_player_info.m_speed_counter = 0;

	m_player_info.m_deth = false;   //!死亡フラグ初期化
}

//!更新関数
void RunGamePlayer::Update()
{
	Run();  //!移動関数

	Jump();  //!ジャンプ関数

	Collision(); //!当たり判定関数
}

//!移動関数
void RunGamePlayer::Run()
{
	m_player_info.m_move = false;  //!移動フラグをfalse

	m_player_info.m_speed_counter++;  //!移動までに掛かる時間をカウント

	//!移動スピードに達したら
	if (m_player_info.m_speed_counter == m_player_info.m_speed_max)
	{
		m_player_info.m_speed_counter = 0;
		m_player_info.m_move = true;  //!移動フラグをtrue
	}
}

//!ジャンプ関数
void RunGamePlayer::Jump()
{
	printf("Rキーでジャンプ\n");

	//!ジャンプキーが押された場合
	if (Inputter::Instance()->InputJumpKey() == true)
	{
		//!床に脚がついているなら
		if (Collision::EdgeCollision(m_player_info.m_pos, RunGameMapData::Instance()->GroundPos(m_player_info.m_pos),
			m_player_info.m_height, m_player_info.m_width, RUNGAME_WALL_SIZE_X, RUNGAME_WALL_SIZE_Y, EdgeType::EDGE_BOTTOM) == true)
		{
			m_player_info.m_pos.y -= m_player_info.m_jump_power;  //!ジャンプ
		}
	}
}

//!当たり判定関数
void RunGamePlayer::Collision()
{
	if (m_player_info.m_move == true)
	{
		//!脚が地面についている場合
		if (Collision::EdgeCollision(m_player_info.m_pos, RunGameMapData::Instance()->GroundPos(m_player_info.m_next_pos),
			m_player_info.m_height, m_player_info.m_width, RUNGAME_WALL_SIZE_X, RUNGAME_WALL_SIZE_Y, EdgeType::EDGE_BOTTOM) == true)
		{
			m_player_info.m_pos.y -= m_player_info.m_gravity;  //!垂直抗力が働く
		}

		m_player_info.m_pos.y += m_player_info.m_gravity;  //!重力が働く

		DethJudgment(); //!壁に当たって死んだかどうか調べる
	}
}

//!死亡判定関数
void RunGamePlayer::DethJudgment()
{
	//!壁に当たって死んだかどうか調べる
	if (m_player_info.m_pos.y + m_player_info.m_height > RunGameMapData::Instance()->GroundPos(m_player_info.m_next_pos).y)
	{
		if (Collision::EdgeCollision(m_player_info.m_pos, RunGameMapData::Instance()->GroundPos(m_player_info.m_next_pos),
			m_player_info.m_height, m_player_info.m_width, RUNGAME_WALL_SIZE_X, RUNGAME_WALL_SIZE_Y, EdgeType::EDGE_BOTTOM) == true)
		{
			m_player_info.m_deth = true;
		}
	}
}

//!描画情報代入関数
void RunGamePlayer::SetUpBuffer()
{
	//!体を頭とくっつける
	m_player_info.m_body_pos = m_player_info.m_pos;

	m_player_info.m_body_pos.y += 1; //!体座標

	DrawController::Instance()->SetUpBuffer(m_player_info.m_pos, "〇");      //!頭
	DrawController::Instance()->SetUpBuffer(m_player_info.m_body_pos, "▽"); //!体
}
