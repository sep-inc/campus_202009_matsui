#include "GameController.h"
#include "Definition.h"
#include "Entity.h"
#include "Object/Piece.h"
#include <stdio.h>

//!ステップ処理関数
void GameController::StepChange()
{
	switch (m_step)
	{
	case GameController::STEP_INIT:         //!初期化
		Init();
		break;
	case GameController::STEP_FIRST_PUT:    //!先手
		Update(FIRST);
		m_step = STEP_SECOND_PUT;
		break;
	case GameController::STEP_SECOND_PUT:   //!後手
		Update(SECOND);
		m_step = STEP_FIRST_PUT;
		break;
	default:
		break;
	}
}

//!初期化関数
void GameController::Init()
{
	m_player = new Player;  //!インスタンス化

	g_bord.Init();    //盤クラス初期化

	//!次のステップへ
	m_step = STEP_FIRST_PUT;
}

//!更新処理関数
void GameController::Update(PLAYER_TYPE player_type_)
{
	m_player->Update(player_type_); //!プレイヤーの更新処理
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	g_bord.SetUpDrawBuffer();  //!盤の情報を描画配列に代入
}

//!終了判定関数
bool GameController::Judgment()
{
	//!プレイヤーの結果を返す
	if (m_player->Judgment() == true)
	{
		//!続けるかどうか
		if (g_inputter.InputContinue() == true)
		{
			g_bord.Init();         //!盤クラス初期化
			g_drawer.Clear();	   //!描画配列クリア
			SetUpDrawBuffer();     //!描画配列に盤情報代入
			g_drawer.Draw();       //!描画(終了後一度描画しないと見た目上終了しているように見えないため)

			return false;
		}
		else
		{
			return true;
		}
	}

	return false;
}

//!解放関数
void GameController::Delete()
{
	delete m_player;
}
