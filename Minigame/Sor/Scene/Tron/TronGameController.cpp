#include "TronGameController.h"
#include "Object/Player/TronMyself.h"
#include "Object/Player/TronEnemy.h"
#include "../../System/Inputter.h"
#include "../../System/DrawController.h"

//!コンストラクタ
TronGameController::TronGameController()
{
	/////////////////////////////
	//!null初期化(忘れないよう)//
	/////////////////////////////
	for (int i = 0; i < TRON_PLAYER_MAX; i++)
	{
		m_player[i] = nullptr;  //!プレイヤー
	}

	m_stage = nullptr;        //!マップ

	m_game_type = Tron;
	m_next_scene = false;
	m_step = STEP_INIT;//!ステップ初期化
}

//!デストラクタ
TronGameController::~TronGameController()
{
	Delete(); //!オブジェクトの解放
}

//!ステップ処理関数
void TronGameController::Update()
{
	switch (m_step)
	{
	case TronGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case TronGameController::STEP_START:    //!開始待ち
		DrawRule();

	//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case TronGameController::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case TronGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}



//!初期化関数
void TronGameController::Reset()
{

	if (m_stage == nullptr) { m_stage = new TronStage; }     //!ステージ
	if (m_player[TRON_MYSELF] == nullptr) { m_player[TRON_MYSELF] = new TornMyself; }  //!自分
	if (m_player[TRON_ENEMY] == nullptr) { m_player[TRON_ENEMY] = new TronEnemy; }    //!敵

	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	//!初期化
	m_stage->Reset();
	m_player[TRON_MYSELF]->Reset(Vec2(MYSELF_INIT_POS_X, MYSELF_INIT_POS_Y), m_stage);
	m_player[TRON_ENEMY]->Reset(Vec2(ENEMY_INIT_POS_X, ENEMY_INIT_POS_Y), m_stage);

	//!次のステップへ
	m_step = STEP_START;

}

//!更新処理関数
void TronGameController::ObjectUpdate()
{
	m_player[TRON_MYSELF]->Update();    //!自分

	//!自分が動いた場合(移動先で死んだ場合は動かないため敵の移動に入らない)
	if (m_player[TRON_MYSELF]->GetMove() == true)
	{
		m_player[TRON_ENEMY]->Update(); //!敵
	}

	//!プレイヤーのどちらかが死亡した時
	if (m_player[TRON_MYSELF]->GetDeth() == true || m_player[TRON_ENEMY]->GetDeth() == true)
	{
		m_step = STEP_RESULT;
	}
}

//!描画情報代入関数
void TronGameController::SetUpDrawBuffer()
{
	m_player[TRON_MYSELF]->SetUpDrawBuffer();
	m_player[TRON_ENEMY]->SetUpDrawBuffer();
}

//!ルール関数
void TronGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("あなたは「■」を操作してください。\n");
	printf("操作方法：十字キーで移動\n");
	printf("終了条件：移動先で何かにぶつかると負け。\n");
}

//!終了判定関数
void TronGameController::GameResult()
{
	m_player[TRON_MYSELF]->ResultDraw();
	m_player[TRON_ENEMY]->ResultDraw();


	if (Inputter::Instance()->InputContinue() == true)
	{
		m_step = STEP_INIT;
	}
}

//!強制終了関数
bool TronGameController::GameEnd()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		return true;
	}
	return false;
}

//!解放処理
void TronGameController::Delete()
{
	//!deleteはnullではないのでnullにしておく
	for (int i = 0; i < TRON_PLAYER_MAX; i++)
	{
		delete m_player[i];
		m_player[i] = nullptr;

	}

	delete m_stage;
	m_stage = nullptr;

}
