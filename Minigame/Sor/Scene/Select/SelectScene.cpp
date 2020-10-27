#include "SelectScene.h"
#include "../../System/Inputter.h"
#include <Windows.h>
#include "../../System/DrawController.h"

//!コンストラクタ
SelectScene::SelectScene()
{
	m_step = STEP_INIT;
}

//!初期化関数(繰り返し)
void SelectScene::Reset()
{
	m_game_type = SelectMode;     //!ゲームの種類(描画クラスに情報を送るため)

	m_select_arrow = Vec2(0, 0);  //!矢印座標
	m_next_scene = false;         //!シーン切り替えフラグ
	m_now_select = 0;             //!現在矢印が示すゲームの位置用
	m_select_font = "→";         //!矢印
	m_none_font = "　";           //!空白

	//!各ゲーム名
	m_game_nmae[Hanoi_Tower] = "ハノイの塔";
	m_game_nmae[OX_Game] = "OXゲーム";
	m_game_nmae[PacMan] = "パックマン";
	m_game_nmae[RunGame] = "Runゲーム";
	m_game_nmae[Shougi] = "将棋";
	m_game_nmae[Tron] = "トロン";

	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	//!次のステップへ
	m_step = STEP_UPDATE;
}

//!各ゲーム管理処理関数
void SelectScene::GameControllerUpdate()
{
	ArrowUpdate();	//!矢印更新関数
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
