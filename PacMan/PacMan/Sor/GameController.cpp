﻿#include "GameController.h"
#include "Object/Player/PacManMyself.h"
#include "Object/Player/PacManEnemy.h"
#include "Entity.h"

//!コンストラクタ
GameController::GameController() :
	m_stage(nullptr), m_player(nullptr), m_enemy{ nullptr }, m_item(nullptr),
	m_step(STEP_INIT) //!初期化ステップ
{
	//!各オブジェクトインスタンス化
	if (m_stage == nullptr) { m_stage = new PacManStage; }
	if (m_item == nullptr) { m_item = new PacManItem(m_stage); }
	if (m_player == nullptr) { m_player = new PacManMyself(m_stage, m_item); }

	//!敵の数分回す
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		if (m_enemy[i] == nullptr)
		{
			m_enemy[i] = new PacManEnemy(m_stage, m_item);
		}
	}
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
	m_stage->Reset();   //!ステージ

	m_player->Reset();//!プレイヤー

	for (int i = 0; i < ENEMY_NUM; i++) { m_enemy[i]->Reset(); }	//!敵

	m_item->Reset();//!アイテム

	//!次のステップへ
	m_step = STEP_START;

}

//!更新処理関数
void GameController::ObjectUpdate()
{
	//!敵
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i]->Update();
	}

	m_player->Update();  //!プレイヤー

	m_item->Update();    //!アイテム
	
	//!プレイヤーが死ぬか、ゲームクリアした時
	if (m_player->GetFlgInfo().m_clear == true || m_player->GetFlgInfo().m_deth == true)
	{
		m_step = STEP_RESULT;
	}
}

//!描画情報代入関数
void GameController::SetUpDrawBuffer()
{
	m_stage->SetUpDrawBuffer();   //!ステージ

	m_item->SetUpDrawBuffer();    //!アイテム

	m_player->SetUpDrawBuffer();  //!プレイヤー

	//!敵
	for (int i = 0; i < ENEMY_NUM; i++)
	{
		m_enemy[i]->SetUpDrawBuffer();
	}
}

//!終了判定関数
void GameController::GameResult()
{
	m_player->ResultDraw();   //!結果表示

	//!続けるかどうか
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
