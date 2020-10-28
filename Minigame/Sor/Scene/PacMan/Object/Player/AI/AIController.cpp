#include "AIController.h"
#include "ChaseAI.h"
#include "StopAI.h"
#include <stdlib.h>

const __int16 AIController::m_chase_ai_count = 10;   //!ChaseAI中の時間
const __int16 AIController::m_change_maxcount = 20;	 //!StopAIからChaseAIまでの時間

//!コンストラクタ
AIController::AIController(PacManStage* stage_) :
	m_ai{ nullptr,nullptr },
	m_change_counter(0),    //!AI切り替え時間カウンター
	m_direction(Vec2(0, 0))	//!方向ベクトル
{
	if (m_ai[CHASE] == nullptr) { m_ai[CHASE] = new ChaseAI(stage_); }//!追跡AI
	if (m_ai[STOP] == nullptr) { m_ai[STOP] = new StopAI(); } //!停止AI 
}

AIController::~AIController()
{
	DeleteAI();
}

//!初期化関数
void AIController::Reset()
{
	m_change_counter = 0;     //!AI切り替え時間カウンター
	m_direction = Vec2(0, 0);  //!方向ベクトル

	//!各AI初期化
	for (int i = 0; i < AI_NUM; i++)
	{
		m_ai[i]->Reset();
	}
}

//!AIパターン更新関数
void AIController::ChangeAI(Vec2 pos_)
{
	m_change_counter++; //!AI切り替え時間カウント

	//!追跡AI中
	if (m_change_counter <= m_chase_ai_count)
	{
		m_direction = m_ai[CHASE]->SelectDirection(pos_);
	}
	//!停止AI中
	else if (m_change_counter > m_chase_ai_count)
	{
		m_direction = m_ai[STOP]->SelectDirection(pos_);
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
	if (m_ai[CHASE]->GetParam_change() == true)
	{
		return true;
	}

	return false;
}

//!解放関数
void AIController::DeleteAI()
{
	for (int i = 0; i < AI_NUM; i++)
	{
		delete m_ai[i];
		m_ai[i] = nullptr;
	}
}
