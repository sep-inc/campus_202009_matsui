#include "SceneController.h"
#include "../System/DrawController.h"
#include "../System/Inputter.h"
#include "Select/SelectGameController.h"
#include "PacMan/PacManGameController.h"
#include "RunGame/RunGameGameController.h"
#include "Tron/TronGameController.h"
#include "Shougi/SyougiGameController.h"




SceneController* SceneController::p_instance = 0;

//!コンストラクタ
SceneController::SceneController() :
	m_select_game(SelectMode),
	m_gamecontroller(nullptr)
{
	//if (m_gamecontroller == nullptr) { m_gamecontroller = new SelectGameController; }
	//if (m_gamecontroller == nullptr) { m_gamecontroller = new RunGameGameController; }
	//if (m_gamecontroller == nullptr) { m_gamecontroller = new TronGameController; }
	if (m_gamecontroller == nullptr) { m_gamecontroller = new SyougiGameController; }


}

//!デストラクタ
SceneController::~SceneController()
{
	delete m_gamecontroller;
	m_gamecontroller = nullptr;
}

//!インスタンス化関数
SceneController* SceneController::Instance()
{
	if (p_instance == 0)
	{
		p_instance = new SceneController; //!インスタンス化
	}

	return p_instance;
}

//!ステップ処理関数
void SceneController::Update()
{
	m_gamecontroller->Update();
}

//! 描画情報代入関数
void SceneController::SetUpDrawBuffer()
{
	m_gamecontroller->SetUpDrawBuffer();
}

//!シーン切り替え判定関数
void SceneController::ChangeScene()
{
	m_gamecontroller->ChangeState();

	//!シーンが切り替えられたら
	//if (m_gamecontroller->GetNextScene() == true)
	//{
	//	m_select_game = m_gamecontroller->GetSelectGame();  //!選択したゲーム(もしくは選択シーン)を代入
	//}
}

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
