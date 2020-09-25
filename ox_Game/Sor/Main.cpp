#include "Entity.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	g_drawer.Init();  //!描画クラス初期化

	g_bord.Init();    //!盤クラス初期化

	srand((unsigned int)time(NULL));   //乱数初期化

	while (true)
	{

		g_piece.StepChange();  //!駒のステップ処理

		g_piece.SetUpDrawBuffer();  //!駒を描画座標に変換

		g_drawer.Draw();            //!描画

		//!終了判定
		if (g_bord.Search() == true && g_inputter.InputContinue() == true)
		{
			g_bord.Init();      //!盤クラス初期化
			g_drawer.Init();    //!描画クラス初期化
			g_piece.Delete();   //!プレイヤー、敵の解放
			g_piece.Continue(); //!初期化
		}
		else if (g_bord.Search() == true && g_inputter.InputContinue() == false)
		{  
			g_piece.Delete();   //!プレイヤー、敵の解放
			break;
		}
		//!キー入力(ESC)
		else if (g_inputter.InputEnd() == true)
		{
			g_piece.Delete();  //!プレイヤー、敵の解放
			break;
		}

	}

	return 1;

}
