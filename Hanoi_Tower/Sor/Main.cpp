#include "Typedef.h"

int main()
{
	/* 描画配列初期化 */
	g_drawer.Init();

	while (true)
	{
		/* 各オブジェクトのStep処理 */
		g_diskarray.StepChange();
		g_boxarray.StepChange();

		/* 描画配列クリア */
		g_drawer.Clear();

		/* 各オブジェクト描画座標に代入 */
		g_boxarray.SetUpDrawBuffer();
		g_diskarray.SetUpDrawBuffer();

		/* 描画 */
		g_drawer.Draw();

		/* 終了フラグon,off */
		if (g_boxarray.GetEndFlg() == true)
		{
			return 0;
		}

		/* 入力待ち関数 */
		g_inputter.InputNumber();

	}

	return 0;
}