﻿#include "Entity.h"
#include <stdlib.h>
#include <time.h>
#include <random>


int main()
{
	g_drawer.Init();  //!描画クラス初期化

	srand((unsigned)time(NULL));

	while (true)
	{
		//!Updateを呼ぶ
		g_game_controller.Update();       //!ゲームクラスステップ処理

		g_drawer.Clear();                     //!描画配列クリア

		g_game_controller.SetUpDrawBuffer();  //!盤情報描画配列に代入

		g_drawer.Draw();                      //!描画


		//!もしもゲームが終わった時
		if (g_game_controller.Judgment() == true)
		{
			g_game_controller.Delete();
			break;
		}

		//!強制終了
		g_inputter.InputEnd();

	}

	return 1;

}