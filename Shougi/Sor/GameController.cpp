#include "GameController.h"
#include "Definition.h"
#include "Entity.h"
#include "Object/Piece.h"
#include <stdio.h>

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
	m_player[FIRST] = new Player(FIRST);  //!インスタンス化
	m_player[SECOND] = new Player(SECOND);  //!インスタンス化

	m_bord = new Bord;  //!インスタンス化

	//!初期化
	m_player[FIRST]->Init();
	m_player[SECOND]->Init();

	m_bord->Init();    //盤クラス初期化

	//!次のステップへ
	m_step = STEP_UPDATE;
}

//!更新処理関数
void GameController::ObjectUpdate()
{
	switch (m_turn)
	{
	case GameController::FIRST_TURN:     //!先手
		printf("先手の番です。\n");
		m_player[FIRST]->Update(m_bord);  //!プレイヤーの更新処理
		m_turn = SECOND_TURN;
		break;
	case GameController::SECOND_TURN:    //!後手
		printf("後手の番です。\n");
		m_player[SECOND]->Update(m_bord);  //!プレイヤーの更新処理
		m_turn = FIRST_TURN;
		break;
	default:
		break;
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_bord->SetUpDrawBuffer();  //!盤の情報を描画配列に代入
}

//!終了判定関数
bool GameController::Judgment()
{
	//!プレイヤーの結果を受け取る
	if (m_player[FIRST]->Judgment(m_bord) == true || m_player[SECOND]->Judgment(m_bord) == true)
	{
		//!続けるかどうか
		if (g_inputter.InputContinue() == true)
		{
			m_bord->Init();         //!盤クラス初期化
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
	delete m_player[FIRST];
	delete m_player[SECOND];
	delete m_bord;
}
