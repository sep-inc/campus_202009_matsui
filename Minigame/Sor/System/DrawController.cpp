#include "DrawController.h"
#include "../Scene/Select/System/SelectSceneDrawer.h"
#include "../Scene/PacMan/System/PacManDrawer.h"
#include "../Scene/RunGame/System/RunGameDrawer.h"
#include "../Scene/Tron/System/TronDrawer.h"
#include "../Scene/Shougi/System/SyougiDrawer.h"



DrawController* DrawController::p_instance = 0;

//!コンストラクタ
DrawController::DrawController() :
	m_game_type(SelectMode),
	m_drawer(nullptr)
{}

//!インスタンス化関数
DrawController* DrawController::Instance()
{
	if (p_instance == 0)
	{
		p_instance = new DrawController; //!インスタンス化
	}

	return p_instance;
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

	//!各ゲームに切り替え
	switch (m_game_type)
	{
	case PacMan:
		if (m_drawer == nullptr)
		{
			m_drawer = new PacManDrawer;
		}
		break;
	case RunGame:
		if (m_drawer == nullptr)
		{
			m_drawer = new RunGameDrawer;
		}
		break;
	case Tron:
		if (m_drawer == nullptr)
		{
			m_drawer = new TronDrawer;
		}
		break;
	case Syougi:
		if (m_drawer == nullptr)
		{
			m_drawer = new SyougiDrawer;
		}
		break;
	case SelectMode:
		if (m_drawer == nullptr)
		{
			m_drawer = new SelectSceneDrawer;
		}
		break;
	default:
		break;
	}
}


