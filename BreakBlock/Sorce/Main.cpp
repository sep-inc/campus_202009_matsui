#include "../Header/Definition.h"


int main()
{	
	/* �`��p�N���X�݂̂����ŏ����� */
	g_drawer.Init();

	while (true)
	{
		/* �e�I�u�W�F�N�gStepChange */
		g_blockarray.Update();
		g_bar.Update();
		g_ball .Update();


		//* Buffer�̒��g���N���A */
		g_drawer.BufferClear();

		/* Drawer���� */
		g_blockarray.SetUpDrawBuufer();   //Block��ǉ�
		g_bar.SetUpDrawBuffer();          //Bar��ǉ�
		g_ball.SetDrawBuffer();           //Ball��ǉ�


		/* �\�� */
		g_drawer.Draw();

		getchar();

		/* ����\�������ɍs���Ȃ��悤�ɂ��Ă��� */
		system("cls");
	}
	return 0;
}