#include "System/Fps.h"
#include "Scene/SceneController.h"
#include "../Sor/System/DrawController.h"
#include <time.h>
#include <random>

int main()
{
	srand((unsigned)time(NULL)); //!乱数テーブル初期化

	while (true)
	{
		Fps::Instance()->TimeBaseLoopExecuter();    //!Fps測定開始

		SceneController::Instance()->Update();      //!ゲームシーン管理クラス更新処理

		DrawController::Instance()->Clear();        //!描画配列クリア

		SceneController::Instance()->SetUpDrawBuffer();    //!ゲーム情報描画クラスに送信

		DrawController::Instance()->Draw();         //!描画

		SceneController::Instance()->ChangeScene();      //!シーン切り替え判定

		//!選択シーン時に終了キーが押された場合
		if (SceneController::Instance()->GameEnd() == true)
		{
			break;
		}

		Fps::Instance()->TimeAdjustment();  //!フレーム固定関数
	}

	return -1;
}