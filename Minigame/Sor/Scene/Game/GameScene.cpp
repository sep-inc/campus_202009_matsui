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
	m_controller_step = CONTROLLER_INIT;  //!ステップ
	m_next_scene = false;                 //!シーン切り替えフラグ
}

//!初期化関数(繰り返し)
void GameScene::Reset()
{
	m_game_type = SceneController::Instance()->GetSelectGame();  //!選択されたゲームを保存

	DrawController::Instance()->SetNowGameDraw(m_game_type);  //!使う描画クラスを指定描画

	Inputter::Instance()->Reset();  //!入力クラス初期化

}

//!各ゲーム管理処理関数
void GameScene::Update()
{
	switch (m_controller_step)
	{
	case GameScene::CONTROLLER_INIT:     //!初期化
		Reset();   //!シーンの初期化

		m_gamecontroller[m_game_type]->Reset(); //!各オブジェクトの初期化

		m_controller_step = CONTROLLER_START;  //!次のステップへ
		break;
	case GameScene::CONTROLLER_START:    //!開始待ち
		m_gamecontroller[m_game_type]->DrawRule();  //ルール表示

		//!スタートキーが入力されたら
		if (Inputter::Instance()->InputStartKey() == true)
		{
			m_controller_step = CONTROLLER_UPDATE;
		}

		break;
	case GameScene::CONTROLLER_UPDATE:   //!更新
		m_gamecontroller[m_game_type]->ObjectUpdate();  //!各オブジェクト更新

		//!ゲームの終了条件が満たされた場合
		if (m_gamecontroller[m_game_type]->ResultStep() == true)
		{
			m_controller_step = CONTROLLER_RESULT;
		}

		break;
	case GameScene::CONTROLLER_RESULT:  //!結果
		m_gamecontroller[m_game_type]->GameResult();

		//!続けるかどうか
		if (Inputter::Instance()->InputContinue() == true)
		{
			m_controller_step = CONTROLLER_INIT;
		}

		break;
	default:
		break;
	}

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

