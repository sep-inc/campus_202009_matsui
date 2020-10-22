﻿#include "AIController.h"

//!コンストラクタ
AIController::AIController(PacManStage* stage_)
{
	m_change_counter = 0;    //!AI切り替え時間カウンター
	m_chase_ai_count = 10;   //!ChaseAI中の時間
	m_change_maxcount = 20;  //!StopAIからChaseAIまでの時間

	m_direction = Vec(0, 0);  //!方向ベクトル

	m_chase_ai = nullptr;   //!追跡AI
	m_stop_ai = nullptr;    //!停止AI

	if (m_chase_ai == nullptr) { m_chase_ai = new ChaseAI(stage_); }
	if (m_stop_ai == nullptr) { m_stop_ai = new StopAI(); }

}

//!AIパターン更新関数
void AIController::ChangeAI(Vec pos_)
{
	m_change_counter++; //!AI切り替え時間カウント

	//!追跡AI中
	if (m_change_counter <= m_chase_ai_count)
	{
		m_direction = m_chase_ai->SelectDirection(pos_);
	}
	//!停止AI中
	else if (m_change_counter > m_chase_ai_count)
	{
		m_direction = m_stop_ai->SelectDirection();
	}

	//!追跡AIに切り替え
	if (m_change_counter == m_change_maxcount)
	{
		m_change_counter = 0;
	}
}

//!追跡判定関数
bool AIController::ChaseMode()
{
	//!追跡AIでプレイヤーを見つけた場合
	if (m_chase_ai->GetChase() == true)
	{
		return true;
	}

	return false;
}

//!解放関数
void AIController::DeleteAI()
{
	delete m_chase_ai;
	delete m_stop_ai;

	m_chase_ai = nullptr;
	m_stop_ai = nullptr;
}