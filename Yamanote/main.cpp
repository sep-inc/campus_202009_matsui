﻿#include "World.h"

int main()
{
	/* 入力処理 */
	g_inputter.InputStation();

	/* ステップ処理 */
	g_database.StepChange();

	g_drawer.Draw();

	return 0;
}