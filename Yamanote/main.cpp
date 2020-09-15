#include "World.h"

int main()
{

	g_inputter.InputStation();

	/* ステップ処理 */
	g_database.StepChange();

	g_drawer.Draw();

	return 0;
}