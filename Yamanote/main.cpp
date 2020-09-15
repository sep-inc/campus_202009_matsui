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
		
	}
	return 0;
}