#include "Typedef.h"

int main()
{

	while (true)
	{
		/* 入力処理 */
		g_inputter.InputStation();

		/* ステップ処理 */
		g_database.StepChange();

		/* 表示 */
		g_drawer.Draw();

		/* 終了判定 */
		if (g_inputter.InputEnd() == true)
		{
			break;
		}
		
	}
	return 0;
}