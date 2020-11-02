#include "SceneController.h"
#include "../System/DrawController.h"
#include "../System/Inputter.h"
#include "Select/SelectGameController.h"
#include "PacMan/PacManGameController.h"
#include "RunGame/RunGameGameController.h"
#include "Tron/TronGameController.h"
#include "Shougi/SyougiGameController.h"
#include "Hanoi_Tower/HanoiTowerGameController.h"
#include "OX_Game/OX_GameGameController.h"

SceneController* SceneController::p_instance = 0;

//!インスタンス化関数
SceneController* SceneController::Instance()
{
	if (p_instance == 0)
	{
		p_instance = new SceneController; //!インスタンス化
	}

	return p_instance;
}

//!初期化関数
void SceneController::Init()
{
	m_gamecontroller = nullptr;

	m_select_game = SELECTSCENE;
}

//!各シーン更新処理関数
void SceneController::Update()
{
	ChangeScene(); //!シーン切り替え判定

	m_gamecontroller->Update();
}

//! 各シーン描画情報代入関数
void SceneController::SetUpDrawBuffer()
{
	m_gamecontroller->SetUpDrawBuffer();
}

//!シーン切り替え判定関数
void SceneController::ChangeScene()
{
	//!最初は選択シーンで初期化
	if (m_gamecontroller == nullptr) { m_gamecontroller = new SelectGameController; }

	//!各シーン切り替え判定
	m_gamecontroller->ChangeState();

	//!シーンが切り替えられたら
	if (m_gamecontroller->GetNextScene() == true)
	{
		system("cls");    //!遊んでいたゲームの描画を消す

		m_select_game = m_gamecontroller->GetSelectGame();  //!選択したゲーム(もしくは選択シーン)を代入

		delete m_gamecontroller;
		m_gamecontroller = nullptr;

		//!指定のゲームの管理クラスに切り替える
		m_gamecontroller = s_controller_array[static_cast<int>(m_select_game)]();
	}
}

//!各ゲーム管理クラスアドレス配列
GameControllerBase* (*SceneController::s_controller_array[static_cast<int>(GAME_TYPE::GAME_NUM)])() =
{
	HanoiTowerGameController::InstanceHanoiTower,  //!ハノイの塔
	OX_GameGameController::InstanceOX_Game,		   //!●×ゲーム
	PacManGameController::InstancePacMan,		   //!パックマン
	RunGameGameController::InstanceRunGame,		   //!RunGame
	SyougiGameController::InstanceSyougi,		   //!将棋
	TronGameController::InstanceTron,			   //!トロン
	SelectGameController::InstanceSelect		   //!選択シーン
};

//! 強制終了関数
bool SceneController::GameEnd()
{
	if (m_gamecontroller->GameEnd() == true)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}

//!解放処理関数
void SceneController::Delete()
{
	delete m_gamecontroller;
	m_gamecontroller = nullptr;

	delete p_instance;
	p_instance = nullptr;
}
