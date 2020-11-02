#include "HanoiTowerGameController.h"
#include "../../System/Inputter.h"
#include "../../System/DrawController.h"
#include <stdio.h>

//!コンストラクタ
HanoiTowerGameController::HanoiTowerGameController() :
	m_box_array(nullptr), m_disk_array(nullptr)
{
	m_game_type = HANOI_TOWER;
	m_next_scene = false;
	m_step = STEP_INIT;
}

//!デストラクタ
HanoiTowerGameController::~HanoiTowerGameController()
{
	delete m_box_array;
	delete m_disk_array;

	m_box_array = nullptr;
	m_disk_array = nullptr;
}

//!初期化関数
void HanoiTowerGameController::Reset()
{
	//!描画で使うクラス指定
	DrawController::Instance()->SetNowGameDraw(m_game_type);

	//!入力クラス初期化
	Inputter::Instance()->Reset();

	if (m_box_array == nullptr) { m_box_array = new HanoiTowerBoxArray; }
	if (m_disk_array == nullptr) { m_disk_array = new HanoiTowerDiskArray; }

	m_box_array->Init();
	m_disk_array->Init(m_box_array);

	m_step = STEP_START;  //!次のステップへ
}

void HanoiTowerGameController::Update()
{
	switch (m_step)
	{
	case HanoiTowerGameController::STEP_INIT:     //!初期化
		Reset();
		break;
	case HanoiTowerGameController::STEP_START:    //!開始待ち
		DrawRule();

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_step = STEP_UPDATE;
		}
		break;
	case HanoiTowerGameController::STEP_UPDATE:   //!更新
		ObjectUpdate();
		break;
	case HanoiTowerGameController::STEP_RESULT:  //!結果
		GameResult();
		break;
	default:
		break;
	}
}


//!更新処理関数
void HanoiTowerGameController::ObjectUpdate()
{
	m_disk_array->Move(m_box_array);

	if (m_box_array->SearchRightBox() == true)
	{
		m_step = STEP_RESULT;
	}
}

void HanoiTowerGameController::DrawRule()
{
	printf("Enterでゲームスタート\n");
	printf("操作方法：数字キーで移動元、移動先選択\n");
	printf("終了条件：左端にある円盤をすべて右に持ってくる\n");
	printf("ルール：動かそうとしている円盤よりも小さい円盤の上には置けない\n");
}

//!描画情報代入関数
void HanoiTowerGameController::SetUpDrawBuffer()
{
	m_box_array->SetUpDrawBuffer();
	m_disk_array->SetUpDrawBuffer();
}

//!終了判定関数
void HanoiTowerGameController::GameResult()
{
	printf("ゲームクリア\n");

	//!続けるかどうか
	if (Inputter::Instance()->InputContinue() == true)
	{
		m_step = STEP_INIT;
	}
}

//!強制終了関数
void HanoiTowerGameController::ChangeState()
{
	//!ESCキーが押されたとき
	if (Inputter::Instance()->GetESCKey() == true)
	{
		m_game_type = SELECTSCENE;  //!選択したゲームの種類
		m_next_scene = true;       //!シーン切り替えフラグtrue
	}
}

GameControllerBase* HanoiTowerGameController::InstanceHanoiTower()
{
	return static_cast<GameControllerBase*>(new HanoiTowerGameController);
}
