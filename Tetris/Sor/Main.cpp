#include "Entity.h"
#include <time.h>
#include <random>

int main()
{
	srand((unsigned)time(NULL)); //!乱数テーブル初期化

	g_game_controller.Init();    //!ゲームクラスステップ処理

	while (true)
	{
		g_fps.TimeBaseLoopExecuter();  //!Fps測定開始

		g_game_controller.Update();    //!ゲームクラスステップ処理

		g_drawer.Clear();              //!描画配列クリア

		g_game_controller.SetUpDrawBuffer();//!盤情報描画配列に代入

		g_drawer.Draw();               //!描画

		//!もしもゲームが終わった時
		if (g_game_controller.GameEnd() == true)
		{
			break;
		}

		g_fps.TimeAdjustment();  //!フレーム固定関数
	}

	return -1;
}