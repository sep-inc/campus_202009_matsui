#include "World.h"

int main()
{

	g_inputter.InputStation();

	/* �X�e�b�v���� */
	g_database.StepChange();

	g_drawer.Draw();

	return 0;
}