#include "GameScene.h"
#include "PacMan/PacManGameController.h"
#include "../SceneController.h"
#include "../../System/DrawController.h"
#include "../../System/Inputter.h"


//!コンストラクタ
GameScene::GameScene() :
	m_gamecontroller{ false }
{
	if (m_gamecontroller[PacMan] == nullptr) { m_gamecontroller[PacMan] = new PacManGameController; }
	m_step = STEP_INIT;
	m_next_scene = false;
}

//!初期化関数(繰り返し)
void GameScene::Reset()
{
	m_game_type = SceneController::Instance()->GetSelectGame();  //!選択されたゲームを保存

	DrawController::Instance()->SetNowGameDraw(m_game_type);  //!使う描画クラスを指定描画

	GameControllerUpdate();   //!各ゲーム管理処理関数

	Inputter::Instance()->Reset();  //!入力クラス初期化

	//!次のステップへ
	m_step = STEP_UPDATE;
}

//!各ゲーム管理処理関数
void GameScene::GameControllerUpdate()
{
	m_gamecontroller[m_game_type]->Update();
}

//!描画情報送信関数関数
void GameScene::SetUpDrawBuffer()
{
	m_gamecontroller[m_game_type]->SetUpDrawBuffer();
}

//!シーン切り替え判定関数
void GameScene::ChangeState()
{
	//!各ゲームの終了判定がtrueの時
	if (m_gamecontroller[m_game_type]->GameEnd() == true)
	{
		m_game_type = SelectMode;  //!選択シーンに戻る
		m_next_scene = true;       //!シーン切り替えフラグtrue
		system("cls");
	}
}

