#define _CRTDBG_MAP_ALLOC
#include "System/Fps.h"
#include "Scene/SceneController.h"
#include "System/Inputter.h"
#include "../Sor/System/DrawController.h"
#include <time.h>
#include <random>
#include <stdlib.h>
#include <crtdbg.h>

int main()
{
	srand((unsigned)time(NULL)); //!乱数テーブル初期化


	SceneController::Instance()->Init();   //!シーン管理クラス初期化
	DrawController::Instance()->Init();    //!描画管理クラス初期化

	while (true)
	{
		Fps::Instance()->TimeBaseLoopExecuter();    //!Fps測定開始

		SceneController::Instance()->Update();      //!ゲームシーン管理クラス更新処理

		DrawController::Instance()->Clear();        //!描画配列クリア

		SceneController::Instance()->SetUpDrawBuffer();    //!ゲーム情報描画クラスに送信

		DrawController::Instance()->Draw();         //!描画

		//!選択シーン時に終了キーが押された場合
		if (SceneController::Instance()->GameEnd() == true)
		{
			break;
		}

		//SceneController::Instance()->ChangeScene();      

		Fps::Instance()->TimeAdjustment();  //!フレーム固定関数
	}

	//!解放処理
	DrawController::Instance()->Delete();
	Inputter::Instance()->Delete();
	SceneController::Instance()->Delete();

	return 0;
}