#include "SceneController.h"
#include "Select/SelectScene.h"
#include "Game/GameScene.h"
#include "../System/DrawController.h"

SceneController* SceneController::p_instance = 0;

//!コンストラクタ
SceneController::SceneController() :
	m_step(STEP_INIT), m_scene_step(Select),
	m_scene(nullptr),
	m_next_scene(false),
	m_select_game(SelectMode)
{
	
	if (m_scene == nullptr) { m_scene = new SelectScene; }

}

//!デストラクタ
SceneController::~SceneController()
{
	delete m_scene;
	m_scene = nullptr;
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
	//!シーン切り替え時
	if (m_next_scene == true)
	{
		//!初期化
		delete m_scene;
		m_scene = nullptr;

		m_next_scene = false;

		//!選択シーン時
		if (m_select_game == SelectMode)
		{
			if (m_scene == nullptr) { m_scene = new SelectScene; }
		}
		//!各ゲームシーン時
		else
		{
			if (m_scene == nullptr) { m_scene = new GameScene; }
		}
	}

	//!更新
	m_scene->Update();
}

//! 描画情報代入関数
void SceneController::SetUpDrawBuffer()
{
	m_scene->SetUpDrawBuffer();
}

//!シーン切り替え判定関数
void SceneController::ChangeScene()
{
	m_scene->ChangeState();

	//!シーンが切り替えられたら
	if (m_scene->GetNextScene() == true)
	{
		m_select_game = m_scene->GetSelectGame();  //!選択したゲーム(もしくは選択シーン)を代入
		m_step = STEP_INIT;    //!初期化ステップへ
		m_next_scene = true;   //!シーン切り替えフラグtrue
	}
}

//! 強制終了関数
bool SceneController::GameEnd()
{
	if (m_scene->GameEnd()==true)
	{
		return true;
	}
	else
	{
		return false;
	}
	return false;
}
