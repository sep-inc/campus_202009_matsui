#include "GameController.h"
#include "Entity.h"

//!コンストラクタ
GameController::GameController()
{
	m_step = STEP_INIT; //!ステップ初期化

	//!インスタンス化
	m_map = new MapManager;  //!マップ
	m_player = new Player;   //!プレイヤー
}

//!ステップ処理関数
void GameController::Update()
{
	switch (m_step)
	{
	case GameController::STEP_INIT:     //!初期化
		Init();
		break;
	case GameController::STEP_START:    //!開始待ち
	    //!スタートキーが入力されたら
		if (g_inputter.InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case GameController::STEP_UPDATE:  //!更新
		ObjectUpdate();
		break;
	case GameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

//!初期化関数
void GameController::Init()
{
	m_map->Init();    //!マップ
	m_player->Init(); //!プレイヤー

	//!開始待ちステップへ
	m_step = STEP_START;
}

//!更新処理関数
void GameController::ObjectUpdate()
{
	m_player->Update();  //!プレイヤー
	
	//!プレイヤーが死んだ場合マップの更新は行わないようにする
	if (m_player->GetPlayerInfo().m_deth == true || m_map->GetGoal() == true)
	{
		//!結果ステップへ
		m_step = STEP_RESULT;
		return;
	}

	//!プレイヤーが移動したら
	if (m_player->GetPlayerInfo().m_move == true)
	{
		m_map->Update(); //!マップ
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_map->SetUpBuffer();    //!マップ
	m_player->SetUpBuffer(); //!プレイヤー
}

//!終了判定関数
void GameController::GameResult()
{
	//!結果表示
	m_map->ResultDraw();

	//!続けるかどうか
	if (g_inputter.InputContinue() == true)
	{
		//!続けるなら初期化ステップへ
		m_step = STEP_INIT;
	}
}

//!強制終了関数
bool GameController::GameEnd()
{
	//!ESCキーが押されたら
	if (g_inputter.GetESCKey() == true)
	{
		Delete();  //!解放処理
		return true;
	}
	return false;
}

//!解放処理
void GameController::Delete()
{
	delete m_player;
	delete m_map;
}
