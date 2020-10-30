#include "PacManGameController.h"
#include "Object/Player/PacManMyself.h"
#include "Object/Player/PacManEnemy.h"
#include "../../System/Inputter.h"
#include "../../System/DrawController.h"
#include <stdio.h>

//!コンストラクタ
PacManGameController::PacManGameController() :
	m_stage(nullptr), m_player(nullptr), m_enemy{ nullptr }, m_item(nullptr)
{
	//!各オブジェクトインスタンス化
	if (m_stage == nullptr) { m_stage = new PacManStage; }
	if (m_item == nullptr) { m_item = new PacManItem(m_stage); }
	if (m_player == nullptr) { m_player = new PacManMyself(m_stage, m_item); }

	//!敵の数分回す
	for (int i = 0; i < PACMAN_ENEMY_NUM; i++)
	{
		if (m_enemy[i] == nullptr)
		{
			m_enemy[i] = new PacManEnemy(m_stage, m_item);
		}
	}

	m_game_type = PacMan;
	m_next_scene = false;
	m_step = STEP_INIT;
}

//!デストラクタ
PacManGameController::~PacManGameController()
{
	Delete(); //!オブジェクトの解放
}

//!初期化関数
void PacManGameController::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	m_stage->Reset();   //!ステージ

	m_stage->SetUpDrawBuffer();   //!ステージ

	m_player->Reset();//!プレイヤー

	for (int i = 0; i < PACMAN_ENEMY_NUM; i++) { m_enemy[i]->Reset(); }	//!敵

	m_item->Reset();//!アイテム



	m_step = STEP_START;  //!次のステップへ

}

void PacManGameController::Update()
{
	switch (m_step)
	{
	case PacManGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case PacManGameController::STEP_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case PacManGameController::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case PacManGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}


//!更新処理関数
void PacManGameController::ObjectUpdate()
{
	//!敵
	for (int i = 0; i < PACMAN_ENEMY_NUM; i++)
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

void PacManGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("あなたは「●」を操作してください。\n");
	printf("操作方法：十字キーで移動\n");
	printf("勝利条件：アイテムをすべて集める。(順番関係なし)\n");
	printf("敗北条件：敵にぶつかる\n");
}

//!描画情報代入関数
void PacManGameController::SetUpDrawBuffer()
{
	m_item->SetUpDrawBuffer();    //!アイテム

	m_player->SetUpDrawBuffer();  //!プレイヤー

	//!敵
	for (int i = 0; i < PACMAN_ENEMY_NUM; i++)
	{
		m_enemy[i]->SetUpDrawBuffer();
	}
}

//!終了判定関数
void PacManGameController::GameResult()
{
	m_player->ResultDraw();   //!結果表示

	//!続けるかどうか
	if (Inputter::Instance()->InputContinue() == true)
	{
		m_step = STEP_INIT;
	}
}

//!ゲーム終了関数
//bool PacManGameController::GameEnd()
//{
//	//!ESCキーが押されたら
//	if (Inputter::Instance()->GetESCKey() == true)
//	{
//		return true;
//	}
//
//	return false;
//}

//!強制終了関数
void PacManGameController::ChangeState()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		m_game_type = SelectMode;  //!選択したゲームの種類
		m_next_scene = true;       //!シーン切り替えフラグtrue
	}
}

//!解放処理
void PacManGameController::Delete()
{
	delete m_stage;
	m_stage = nullptr;

	delete m_player;
	m_player = nullptr;

	for (int i = 0; i < PACMAN_ENEMY_NUM; i++)
	{
		delete m_enemy[i];
		m_enemy[i] = nullptr;
	}

	delete m_item;
	m_item = nullptr;
}

GameControllerBase* PacManGameController::InstancePacMan()
{
	return static_cast<GameControllerBase*>(new PacManGameController);
}
