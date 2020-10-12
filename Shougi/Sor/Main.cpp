#include "Entity.h"
#include <stdlib.h>
#include <time.h>
#include <random>


int main()
{
	//!乱数テーブル初期化
	srand((unsigned)time(NULL));

	while (true)
	{
		g_fps.TimeBaseLoopExecuter();  //!フレーム時間測定開始

		g_game_controller.Update();       //!ゲームクラスステップ処理

		g_drawer.Clear();                     //!描画配列クリア

		g_game_controller.SetUpDrawBuffer();  //!盤情報描画配列に代入

		g_drawer.Draw();                      //!描画


		//!もしもゲームが終わった時
		if (g_game_controller.Judgment() == true)
		{
			g_game_controller.Delete(); //!解放処理
			break;
		}

		g_fps.TimeAdjustment();	 //!フレーム固定関数

	}

	return 1;

}