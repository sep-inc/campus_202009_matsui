#include "OX_GameGameController.h"
#include "../../Definition.h"
#include "../../System/DrawController.h"
#include "../../System/Inputter.h"
#include <stdio.h>

OX_GameGameController::OX_GameGameController() :
	m_board(nullptr), m_player(nullptr), m_enemy(nullptr)
{
	m_game_type = OX_GAME;
	m_next_scene = false;
	m_step = STEP_INIT;//!ステップ初期化
}

OX_GameGameController::~OX_GameGameController()
{
	delete m_board;
	delete m_player;
	delete m_enemy;

	m_board = nullptr;
	m_player = nullptr;
	m_enemy = nullptr;
}

//!ステップ処理関数
void OX_GameGameController::Update()
{
	switch (m_step)
	{
	case OX_GameGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case OX_GameGameController::STEP_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case OX_GameGameController::STEP_UPDATE:  //!更新
		ObjectUpdate();
		break;
	case OX_GameGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}



//!初期化関数
void OX_GameGameController::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	if (m_board == nullptr) { m_board = new OX_GameBoard; }
	if (m_player == nullptr) { m_player = new OX_GamePlayer; }
	if (m_enemy == nullptr) { m_enemy = new OX_GameEnemy; }

	m_board->Init();

	m_player->Init();
	m_enemy->Init();
	
	m_turn = TURN_PLAYER;

	//!次のステップへ
	m_step = STEP_START;
}

//!更新処理関数
void OX_GameGameController::ObjectUpdate()
{
	switch (m_turn)
	{
	case OX_GameGameController::TURN_PLAYER:   //!プレイヤー
		m_player->Put(m_board);
		system("cls");
		m_turn = TURN_ENEMY;  //!配置権を敵に
		break;
	case OX_GameGameController::TURN_ENEMY:   //!敵
		m_enemy->Put(m_board);
		m_turn = TURN_PLAYER; //!配置権をプレイヤーに
		break;
	default:
		break;
	}

	if (m_board->Judgment() == true)
	{
		system("cls");
		m_step = STEP_RESULT;
	}

}

//!描画情報代入関数
void OX_GameGameController::SetUpDrawBuffer()
{
	m_player->SetUpDrawBuffer();   //!プレイヤー
	m_enemy->SetUpDrawBuffer();	   //!敵
}

void OX_GameGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("操作方法：指定箇所(横と縦の交差する場所)を選んで駒を置く。\n");
	printf("自分は●です\n");
	printf("終了条件：相手よりも先に駒を3つ並べる\n");
}

void OX_GameGameController::GameResult()
{
	m_board->DrawResult();

	//!続けるかどうか
	if (Inputter::Instance()->InputContinue() == true)
	{
		//!続けるなら初期化ステップへ
		m_step = STEP_INIT;
	}
}

void OX_GameGameController::ChangeState()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		m_game_type = SELECTSCENE;  //!選択したゲームの種類
		m_next_scene = true;       //!シーン切り替えフラグtrue
	}
}

GameControllerBase* OX_GameGameController::InstanceOX_Game()
{
	return static_cast<GameControllerBase*>(new OX_GameGameController);
}



