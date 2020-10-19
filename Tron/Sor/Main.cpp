#include "Entity.h"
#include <time.h>
#include <random>

int main()
{
	srand((unsigned)time(NULL)); //!乱数テーブル初期化

	while (true)
	{
		g_game_controller.Update();    //!ゲームクラスステップ処理

		g_game_controller.SetUpDrawBuffer();//!盤情報描画配列に代入

		g_drawer.Draw();               //!描画

		//!もしもゲームが終わった時
		if (g_game_controller.GameEnd() == true)
		{
			break;
		}
	}

	return -1;
}