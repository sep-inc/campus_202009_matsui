#include "RunGameGameController.h"
#include "../../System/Inputter.h"
#include "../../System/DrawController.h"

//!コンストラクタ
RunGameGameController::RunGameGameController()
{
	m_game_type = RunGame;
	m_next_scene = false;
	m_controller_step = CONTROLLER_INIT;//!ステップ初期化
}

//!デストラクタ
RunGameGameController::~RunGameGameController()
{
	Delete(); //!解放処理
}

//!ステップ処理関数
void RunGameGameController::Update()
{
	switch (m_controller_step)
	{
	case RunGameGameController::CONTROLLER_INIT:     //!初期化
		Reset();
		break;
	case RunGameGameController::CONTROLLER_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_controller_step = CONTROLLER_UPDATE;
		}
		break;
	case RunGameGameController::CONTROLLER_UPDATE:  //!更新
		ObjectUpdate();
		break;
	case RunGameGameController::CONTROLLER_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}

//!初期化関数
void RunGameGameController::Reset()
{
	//!インスタンス化
	if (m_map == nullptr) { m_map = new RunGameMapManager; }//!マップ
	if (m_player == nullptr) { m_player = new Player; }//!プレイヤー

	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	m_map->Reset();    //!マップ
	m_player->Reset(); //!プレイヤー

	//!開始待ちステップへ
	m_controller_step = CONTROLLER_START;
}

//!更新処理関数
void RunGameGameController::ObjectUpdate()
{
	m_player->Update();  //!プレイヤー

	//!プレイヤーが死んだ場合マップの更新は行わないようにする
	if (m_player->GetPlayerInfo().m_deth == true || m_map->GetGoal() == true)
	{
		//!結果ステップへ
		m_controller_step = CONTROLLER_RESULT;
		return;
	}

	//!プレイヤーが移動したら
	if (m_player->GetPlayerInfo().m_move == true)
	{
		m_map->Update(); //!マップ
	}
}

//!描画情報代入関数
void RunGameGameController::SetUpDrawBuffer()
{
	m_map->SetUpBuffer();    //!マップ
	m_player->SetUpBuffer(); //!プレイヤー
}

void RunGameGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("操作方法：Rキーでジャンプ\n");
	printf("終了条件：壁にぶつかるか、300マス先のゴールにたどり着くか。\n");
}

//!終了判定関数
void RunGameGameController::GameResult()
{
	//!結果表示
	m_map->ResultDraw();

	//!続けるかどうか(続けるボタンが押されるまでは結果を表示)
	if (Inputter::Instance()->InputContinue() == true)
	{
		//!続けるなら初期化ステップへ
		m_controller_step = CONTROLLER_INIT;
	}
}

//!ゲーム終了関数
bool RunGameGameController::GameEnd()
{
	//!ESCキーが押されたら
	if (Inputter::Instance()->GetESCKey() == true)
	{
		return true;
	}

	return false;
}

//!解放処理
void RunGameGameController::Delete()
{
	delete m_player;
	delete m_map;
}
