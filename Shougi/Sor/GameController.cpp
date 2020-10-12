#include "GameController.h"
#include "Definition.h"
#include "Entity.h"
#include "Object/Piece_King.h"
#include "Object/Piece_Knight.h"
#include "Object/Piece_Goldgeneral.h"
#include "Object/Piece_Pawn.h"
#include "Player/Myself.h"
#include "Player/Enemy.h"
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
	m_cursor = new Cursor;

	m_board = new Board();  //!インスタンス化

	m_player[FIRST] = new Myself(FIRST);  //!インスタンス化
	m_player[SECOND] = new Enemy(SECOND);  //!インスタンス化

	m_piece[KING] = new PieceKing;                //!王
	m_piece[KNIGHT] = new PieceKnight;            //!桂
	m_piece[GOLDGENERAL] = new PieceGoldgeneral;  //!金
	m_piece[PAWN] = new PiecePawn;                //!歩

	m_cursor->Init();  //!カーソル初期化
	m_board->Init();   //盤クラス初期化

	//!次のステップへ
	m_step = STEP_UPDATE;
}

//!更新処理関数
void GameController::ObjectUpdate()
{
	switch (m_turn)
	{
	case GameController::FIRST_TURN:     //!先手
		printf("先手は手前です\n");
		m_player[FIRST]->Update(m_piece);  //!プレイヤーの更新処理
		break;
	case GameController::SECOND_TURN:    //!後手
		m_player[SECOND]->Update(m_piece);  //!プレイヤーの更新処理
		break;
	default:
		break;
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_board->SetUpDrawBuffer(m_piece);  //!盤の情報を描画配列に代入
	m_cursor->SetUpDrawCursor(); 
}

//!終了判定関数
bool GameController::Judgment()
{
	//!プレイヤーの結果を受け取る
	if (m_player[FIRST]->Judgment(m_board) == true || m_player[SECOND]->Judgment(m_board) == true)
	{
		//!続けるかどうか
		if (g_inputter.InputContinue() == true)
		{
			m_turn = FIRST_TURN;  //!先手のターンに戻す
			m_cursor->Init();     //!カーソル初期化 
			m_board->Reset();     //!盤クラス初期化
			g_drawer.Clear();	  //!描画配列クリア
			SetUpDrawBuffer();    //!描画配列に盤情報代入
			g_drawer.Draw();      //!描画(終了後一度描画しないと見た目上終了しているように見えないため)

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
	delete m_board;
	delete m_cursor;

	for (int i = 0; i < PIECE_NUM; i++)
	{
		delete m_piece[i];
	}
}

//!プレイヤーターン変更関数
void GameController::SetNextTurn(PLAYER_TURN turn_)
{
	m_turn = turn_;
}
