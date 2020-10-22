#include "GameController.h"
#include "Object/Player/PacManMyself.h"
#include "Object/Player/PacManEnemy.h"
#include "Entity.h"

//!コンストラクタ
GameController::GameController()
{
	//!各オブジェクト初期化
	m_stage = nullptr;
	m_player = nullptr;
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i] = nullptr;
	}
	m_item = nullptr;


	//!初期化ステップへ
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
	//!
	if (m_stage == nullptr) { m_stage = new PacManStage; }
	if (m_player == nullptr) { m_player = new PacManMyself; }
	if (m_item == nullptr) { m_item = new PacManItem; }

	
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemy[i] == nullptr)
		{
			m_enemy[i] = new PacManEnemy;
		}
	}

	m_stage->Init();
	m_player->Init(m_stage, m_item);

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i]->Init(m_stage, m_item);
	}

	m_item->Init(m_stage);

	//!次のステップへ
	m_step = STEP_START;

}

//!更新処理関数
void GameController::ObjectUpdate()
{
	
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i]->Update();
	}

	m_player->Update();

	m_item->Update();
	
	//!プレイヤーのどちらかが死亡した時
	if (m_player->GetDeth() == true || m_player->GetClear() == true)
	{
		m_step = STEP_RESULT;
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_stage->SetUpDrawBuffer();
	m_item->SetUpDrawBuffer();

	m_player->SetUpDrawBuffer();

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i]->SetUpDrawBuffer();
	}
}

//!終了判定関数
void GameController::GameResult()
{
	m_player->ResultDraw();

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
	delete m_stage;
	m_stage = nullptr;

	delete m_player;
	m_player = nullptr;

	for (int i = 0; i < ENEMY_NUM; i++)
	{
		delete m_enemy[i];
		m_enemy[i] = nullptr;
	}

	delete m_item;
	m_item = nullptr;
}
