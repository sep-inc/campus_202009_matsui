#include "DrawController.h"
#include "../Scene/Select/System/SelectSceneDrawer.h"
#include "../Scene/PacMan/System/PacManDrawer.h"
#include "../Scene/RunGame/System/RunGameDrawer.h"
#include "../Scene/Tron/System/TronDrawer.h"
#include "../Scene/Shougi/System/SyougiDrawer.h"
#include "../Scene/Hanoi_Tower/System/HanoiTowerDrawer.h"
#include "../Scene/OX_Game/System/OX_GameDrawer.h"

DrawController* DrawController::p_instance = 0;

//!インスタンス化関数
DrawController* DrawController::Instance()
{
	//static DrawController drawer;

	//return &drawer;

	if (p_instance == 0)
	{
		p_instance = new DrawController; //!インスタンス化
	}

	return p_instance;
}

//!初期化関数
void DrawController::Init()
{
	m_game_type = SELECTSCENE;
	m_drawer = nullptr;
}


//!描画関数
void DrawController::Draw()
{
	m_drawer->Draw();
}

//!ゲーム文字代入関数
void DrawController::Clear()
{
	m_drawer->Clear();
}

//!ゲーム文字代入関数
void DrawController::SetUpFont(std::string font_)
{
	m_drawer->SetUpFont(font_);
}

//! Object描画座標変換関数
void DrawController::SetUpBuffer(Vec2 pos_, const char* font_)
{
	m_drawer->SetUpBuffer(pos_, font_);
}

//!クリア用配列代入関数
void DrawController::SetUpClearBuffer(Vec2 pos_, const char* font_)
{
	m_drawer->SetUpClearBuffer(pos_, font_);
}

//!描画ゲーム判定関数
void DrawController::SetNowGameDraw(GAME_TYPE game_type_)
{
	m_game_type = game_type_;

	delete m_drawer;
	m_drawer = nullptr;

	//!指定のゲームの管理クラスに切り替える
	m_drawer = s_drawer_array[static_cast<int>(m_game_type)]();
}

//!各ゲーム管理クラスアドレス配列
DrawBase* (*DrawController::s_drawer_array[static_cast<int>(GAME_TYPE::GAME_NUM)])() =
{
	HanoiTowerDrawer::InstanceHanoiTower,  //!ハノイの塔
	OX_GameDrawer::InstanceOX_Game,		   //!●×ゲーム
	PacManDrawer::InstancePacMan,		   //!パックマン
	RunGameDrawer::InstanceRunGame,		   //!RunGame
	SyougiDrawer::InstanceSyougi,		   //!将棋
	TronDrawer::InstanceTron,			   //!トロン
	SelectSceneDrawer::InstanceSelect	   //!選択シーン
};

//!解放処理関数
void DrawController::Delete()
{

	delete m_drawer;
	m_drawer = nullptr;

	delete p_instance;
	p_instance = nullptr;
}


