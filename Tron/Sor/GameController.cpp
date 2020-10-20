#include "GameController.h"
#include "Object/Player/TronMyself.h"
#include "Object/Player/TronEnemy.h"
#include "Entity.h"

//!コンストラクタ
GameController::GameController()
{
	m_step = STEP_INIT;
}

//!デストラクタ
GameController::~GameController()
{
	Delete(); //!オブジェクトの解放
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
	case GameController::STEP_UPDATE:   //!更新
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

	if (m_stage == nullptr) { m_stage = new TronStage; }     //!ステージ
	if (m_player[MYSELF] == nullptr) { m_player[MYSELF] = new TornMyself; }  //!自分
	if (m_player[ENEMY] == nullptr) { m_player[ENEMY] = new TronEnemy; }    //!敵

	//!初期化
	m_stage->Init();          
	m_player[MYSELF]->Init(Vec(MYSELF_INIT_POS_X, MYSELF_INIT_POS_Y),m_stage);
	m_player[ENEMY]->Init(Vec(ENEMY_INIT_POS_X, ENEMY_INIT_POS_Y),m_stage);

	//!次のステップへ
	m_step = STEP_START;
	
}

//!更新処理関数
void GameController::ObjectUpdate()
{
	m_player[MYSELF]->Update();    //!自分

	//!自分が動いた場合(移動先で死んだ場合は動かないため敵の移動に入らない)
	if (m_player[MYSELF]->GetMove() == true)
	{
		m_player[ENEMY]->Update(); //!敵
	}

	//!プレイヤーのどちらかが死亡した時
	if (m_player[MYSELF]->GetDeth() == true || m_player[ENEMY]->GetDeth() == true)
	{
		m_step = STEP_RESULT;
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_player[MYSELF]->SetUpDrawBuffer();
	m_player[ENEMY]->SetUpDrawBuffer();
}

//!終了判定関数
void GameController::GameResult()
{
	m_player[MYSELF]->ResultDraw();
	m_player[ENEMY]->ResultDraw();


	if (g_inputter.InputContinue() == true)
	{

		m_step = STEP_INIT;
		
	}
}

//!強制終了関数
bool GameController::GameEnd()
{
	//!ESCキーが押されたとき
	if (g_inputter.GetESCKey() == true)
	{
		return true;
	}
	return false;
}

//!解放処理
void GameController::Delete()
{
	for (int i = 0; i < PLAYER_MAX; i++)
	{
		delete m_player[i];
	}
	delete m_stage;
}
