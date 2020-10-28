#include "SelectScene.h"
#include "../../System/Inputter.h"
#include <Windows.h>
#include "../../System/DrawController.h"

//!コンストラクタ
SelectScene::SelectScene() :
	m_select_arrow(Vec2(0, 0)),
	m_now_select(0),
	m_select_font("→"),
	m_none_font("　")
{
	m_game_type = SelectMode;     //!ゲームの種類(描画クラスに情報を送るため)
	m_next_scene = false;         //!シーン切り替えフラグ

	m_controller_step = CONTROLLER_INIT;
	//!各ゲーム名
	m_game_nmae[Hanoi_Tower] = "ハノイの塔";
	m_game_nmae[OX_Game] = "OXゲーム";
	m_game_nmae[PacMan] = "パックマン";
	m_game_nmae[RunGame] = "Runゲーム";
	m_game_nmae[Shougi] = "将棋";
	m_game_nmae[Tron] = "トロン";
}

//!初期化関数(繰り返し)
void SelectScene::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();
}

//!各ゲーム管理処理関数
void SelectScene::Update()
{
	switch (m_controller_step)
	{
	case SelectScene::CONTROLLER_INIT:     //!初期化
		Reset();
		m_controller_step = CONTROLLER_UPDATE;
		break;
	case SelectScene::CONTROLLER_UPDATE:   //!更新
		ArrowUpdate();	//!矢印更新関数
		break;
	default:
		break;
	}
	
}

//!描画情報送信関数関数
void SelectScene::SetUpDrawBuffer()
{
	std::string kai = "ゲームを選択してください。\n十字キーで移動";

	//!文字代入
	DrawController::Instance()->SetUpFont(kai);

	//!ゲーム文字代入
	for (int i = 0; i < SelectMode; i++)
	{
		//!矢印がある場合
		if (m_now_select == i)
		{
			m_draw_font = m_select_font + m_game_nmae[i];  //!矢印とゲーム名を連結
		}
		//!ない場合
		else
		{
			m_draw_font = m_none_font + m_game_nmae[i];  //!空白とゲーム名を連結
		}

		DrawController::Instance()->SetUpFont(m_draw_font);
	}
}

//!矢印更新関数
void SelectScene::ArrowUpdate()
{
	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });

	//!矢印座標に入力座標を代入
	m_select_arrow.y += Inputter::Instance()->InpuMoveKey().y;

	//!矢印が選択外に言った場合
	if (m_select_arrow.y < 0) { m_select_arrow.y = 0; }
	else if (m_select_arrow.y >= SelectMode) { m_select_arrow.y = 5; }

	//!現在の座標の位置のゲームを保存
	m_now_select = m_select_arrow.y;
}

//!シーン切り替え判定関数
void SelectScene::ChangeState()
{
	//!決定キーが押された場合
	if (Inputter::Instance()->GetDecideKey() == true)
	{
		m_game_type = (GAME_TYPE)m_now_select;  //!選択したゲームの種類
		m_next_scene = true;                    //!シーン切り替えフラグtrue
	}
}

//!強制終了関数
bool SelectScene::GameEnd()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		return true;
	}
	return false;
}
