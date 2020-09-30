#include "Entity.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	g_drawer.Init();  //!描画クラス初期化

	g_bord.Init();    //盤クラス初期化

	while (true)
	{
		g_piece.StepChange();       //!駒クラスステップ処理

		g_drawer.Clear();           //!描画配列クリア

		g_piece.SetUpDrawBuffer();  //!駒情報描画配列に代入


		g_drawer.Draw();            //!描画

		//!もしもゲームが終わった時
		if (g_piece.GetFirstWin() == true || g_piece.GetSecondWin() == true)
		{
			g_drawer.DrawJudgment();  //!勝者表示

			//!続けるかどうか
			if (g_inputter.InputContinue() == true)
			{
				g_bord.Init();         //!盤クラス初期化
				g_drawer.Clear();	   //!描画配列クリア
				g_piece.ResetPiece();  //!駒クラスリセット
			}
			else
			{
				break;
			}
		}
		////!キー入力(ESC)
		//if (g_inputter.InputEnd() == true)
		//{
		//	break;
		//}

	}

	return 1;

}