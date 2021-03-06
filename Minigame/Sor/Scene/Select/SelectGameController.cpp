﻿#include "SelectGameController.h"
#include "../../System/Inputter.h"
#include <Windows.h>
#include "../../System/DrawController.h"

//!コンストラクタ
SelectGameController::SelectGameController() :
	m_select_arrow(Vec2(0, 0)),
	m_now_select(0),
	m_select_font("→"),
	m_none_font("　")
{
	m_step = STEP_INIT;
	m_game_type = SELECTSCENE;     //!ゲームの種類(描画クラスに情報を送るため)
	m_next_scene = false;         //!シーン切り替えフラグ

	//!各ゲーム名
	m_game_nmae[HANOI_TOWER] = "ハノイの塔";
	m_game_nmae[OX_GAME] = "OXゲーム";
	m_game_nmae[PACMAN] = "パックマン";
	m_game_nmae[RUNGAME] = "Runゲーム";
	m_game_nmae[SYOUGI] = "将棋";
	m_game_nmae[TRON] = "トロン";
}

//!初期化関数(繰り返し)
void SelectGameController::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	m_step = STEP_UPDATE;

}

void SelectGameController::Update()
{
	switch (m_step)
	{
	case SelectGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case SelectGameController::STEP_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case SelectGameController::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case SelectGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

void SelectGameController::ObjectUpdate()
{
	ArrowUpdate();

	ChangeState();
}

//!描画情報送信関数関数
void SelectGameController::SetUpDrawBuffer()
{
	std::string kai = "ゲームを選択してください。\n十字キーで移動";

	//!文字代入
	DrawController::Instance()->SetUpFont(kai);

	//!ゲーム文字代入
	for (int i = 0; i < SELECTSCENE; i++)
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
void SelectGameController::ArrowUpdate()
{
	//!カーソル座標を左上に
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD{ 0,0 });

	//!矢印座標に入力座標を代入
	m_select_arrow.y += Inputter::Instance()->InpuMoveKey().y;

	//!矢印が選択外に言った場合
	if (m_select_arrow.y < 0) { m_select_arrow.y = 0; }
	else if (m_select_arrow.y >= SELECTSCENE) { m_select_arrow.y = 5; }

	//!現在の座標の位置のゲームを保存
	m_now_select = m_select_arrow.y;
}

//!シーン切り替え判定関数
void SelectGameController::ChangeState()
{
	//!決定キーが押された場合
	if (Inputter::Instance()->GetDecideKey() == true)
	{
		system("cls");
		m_game_type = (GAME_TYPE)m_now_select;  //!選択したゲームの種類
		m_next_scene = true;                    //!シーン切り替えフラグtrue
	}
}

//!強制終了関数
bool SelectGameController::GameEnd()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		return true;
	}
	return false;
}

GameControllerBase* SelectGameController::InstanceSelect()
{
	return static_cast<GameControllerBase*>(new SelectGameController);
}
