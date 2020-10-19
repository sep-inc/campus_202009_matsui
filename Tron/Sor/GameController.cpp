﻿#include "GameController.h"
#include "Object/Player/TronMyself.h"
#include "Object/Player/TronEnemy.h"

#include "Entity.h"

//!ステップ処理関数
void GameController::Update()
{
	switch (m_step)
	{
	case GameController::STEP_INIT:     //!初期化
		Init();
		break;
	case GameController::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	default:
		break;
	}
}

//!初期化関数
void GameController::Init()
{
	m_stage = new TronStage;           //!ステージ
	m_player[MYSELF] = new TornMyself; //!自分
	m_player[ENEMY] = new TronEnemy;   //!敵

	//!初期化
	m_stage->Init();          
	m_player[MYSELF]->Init();
	m_player[ENEMY]->Init();

	//!スタートキーが押された場合
	if (g_inputter.InputStart() == true)
	{
		//!次のステップへ
		m_step = STEP_UPDATE;
	}
}

//!更新処理関数
void GameController::ObjectUpdate()
{
	m_player[MYSELF]->Update();    //!自分

	//!自分が動いた場合(移動先で死んだ場合は動かないため敵の移動に入らない)
	if (m_player[MYSELF]->GetMove() == true)
	{
		m_player[ENEMY]->Update(); //!敵
	}

}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_player[MYSELF]->SetUpDrawBuffer();
	m_player[ENEMY]->SetUpDrawBuffer();
}

//!終了判定関数
bool GameController::GameEndJudgment()
{
	//!プレイヤーのどちらかが死亡した時
	if (m_player[MYSELF]->GetDeth() == true || m_player[ENEMY]->GetDeth() == true)
	{
		m_player[MYSELF]->ResultDraw();


		if (g_inputter.InputContinue() == true)
		{
			//!初期化
			m_stage->Init();
			m_player[MYSELF]->Init();
			m_player[ENEMY]->Init();

			m_step = STEP_INIT;
			return false;
		}

		Delete();
		return true;
	}

	return false;
}

//!強制終了関数
bool GameController::GameEnd()
{
	if (g_inputter.GetEndKey() == true)
	{
		Delete();
		return true;
	}
	return false;
}

//!解放処理
void GameController::Delete()
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		delete m_player[i];
	}

	delete m_stage;

}
