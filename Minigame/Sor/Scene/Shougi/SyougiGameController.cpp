#include "SyougiGameController.h"
#include "Object/SyougiPiece_King.h"
#include "Object/SyougiPiece_Knight.h"
#include "Object/SyougiPiece_Goldgeneral.h"
#include "Object/SyougiPiece_Pawn.h"
#include "Object/Player/SyougiMyself.h"
#include "Object/Player/SyougiEnemy.h"
#include "../../Definition.h"
#include "../../System/DrawController.h"
#include "../../System/Inputter.h"
#include <stdio.h>

SyougiGameController::SyougiGameController()
{
	m_game_type = SYOUGI;
	m_next_scene = false;
	m_step = STEP_INIT;//!ステップ初期化
}

SyougiGameController::~SyougiGameController()
{
	Delete();
}

//!ステップ処理関数
void SyougiGameController::Update()
{
	switch (m_step)
	{
	case SyougiGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case SyougiGameController::STEP_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case SyougiGameController::STEP_UPDATE:  //!更新
		ObjectUpdate();
		break;
	case SyougiGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}



//!初期化関数
void SyougiGameController::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	m_cursor = new SyougiCursor;

	m_board = new SyougiBoard();  //!インスタンス化

	m_player[SYOUGI_FIRST] = new SyougiMyself(SYOUGI_FIRST, m_board, m_cursor);  //!インスタンス化
	m_player[SYOUGI_SECOND] = new SyougiEnemy(SYOUGI_SECOND, m_board);  //!インスタンス化

	m_piece[KING] = new SyougiPieceKing;                //!王
	m_piece[KNIGHT] = new SyougiPieceKnight;            //!桂
	m_piece[GOLDGENERAL] = new SyougiPieceGoldgeneral;  //!金
	m_piece[PAWN] = new SyougiPiecePawn;                //!歩

	m_cursor->Reset();  //!カーソル初期化
	m_board->Reset();   //盤クラス初期化

	//!次のステップへ
	m_step = STEP_START;
}

//!更新処理関数
void SyougiGameController::ObjectUpdate()
{
	switch (m_turn)
	{
	case SyougiGameController::FIRST_TURN:     //!先手
		printf("先手は手前です\n");
		m_player[SYOUGI_FIRST]->Update(m_piece);  //!プレイヤーの更新処理
		if (m_player[SYOUGI_FIRST]->Judgment(m_board) == true)
		{
			m_step = STEP_RESULT;
			break;
		}

		if (m_player[SYOUGI_FIRST]->GetMove() == true)
		{
			m_turn = SECOND_TURN;
		}
		break;
	case SyougiGameController::SECOND_TURN:    //!後手
		m_player[SYOUGI_SECOND]->Update(m_piece);  //!プレイヤーの更新処理
		if (m_player[SYOUGI_SECOND]->Judgment(m_board) == true)
		{
			m_step = STEP_RESULT;
			break;
		}

		if (m_player[SYOUGI_SECOND]->GetMove() == true)
		{
			m_turn = FIRST_TURN;
		}
		break;
	default:
		break;
	}
}

//!描画情報代入関数
void SyougiGameController::SetUpDrawBuffer()
{
	m_board->SetUpDrawBuffer(m_piece);  //!盤の情報を描画配列に代入
	m_cursor->SetUpDrawCursor();
}

void SyougiGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("操作方法：十字キーでカーソル移動\n");
	printf("Enterで移動させる駒選択、移動先選択\n");
	printf("終了条件：相手の王を取るか自分の王が取られた時\n");
}

void SyougiGameController::GameResult()
{
	//!プレイヤーの結果を受け取る
	if (m_turn== FIRST_TURN)
	{
		printf("先手の勝ちです。\n");
	}
	else
	{
		printf("後手の勝ちです。\n");
	}

	//!続けるかどうか
	if (Inputter::Instance()->InputContinue() == true)
	{
		//!続けるなら初期化ステップへ
		m_step = STEP_INIT;
		m_turn = FIRST_TURN;  //!先手のターンに戻す
		m_cursor->Reset();     //!カーソル初期化 
		m_board->Reset();     //!盤クラス初期化
		DrawController::Instance()->Clear();	  //!描画配列クリア
		SetUpDrawBuffer();    //!描画配列に盤情報代入
		DrawController::Instance()->Draw();      //!描画(終了後一度描画しないと見た目上終了しているように見えないため)
	}
}

//bool SyougiGameController::GameEnd()
//{
//	//!ESCキーが押されたら
//	if (Inputter::Instance()->GetESCKey() == true)
//	{
//		return true;
//	}
//
//	return false;
//}

void SyougiGameController::ChangeState()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		m_game_type = SELECTSCENE;  //!選択したゲームの種類
		m_next_scene = true;       //!シーン切り替えフラグtrue
	}
}

//!解放関数
void SyougiGameController::Delete()
{
	delete m_player[SYOUGI_FIRST];
	delete m_player[SYOUGI_SECOND];
	delete m_board;
	delete m_cursor;

	for (int i = 0; i < PIECE_NUM; i++)
	{
		delete m_piece[i];
	}
}

GameControllerBase* SyougiGameController::InstanceSyougi()
{
	return static_cast<GameControllerBase*>(new SyougiGameController);
}

//!プレイヤーターン変更関数
void SyougiGameController::SetNextTurn(PLAYER_TURN turn_)
{
	m_turn = turn_;
}
