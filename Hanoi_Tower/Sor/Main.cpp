#include "Typedef.h"

int main()
{
	/* �`��z�񏉊��� */
	g_drawer.Init();

	while (true)
	{
		/* �e�I�u�W�F�N�g��Step���� */
		g_diskarray.StepChange();
		g_boxarray.StepChange();

		/* �`��z��N���A */
		g_drawer.Clear();

		/* �e�I�u�W�F�N�g�`����W�ɑ�� */
		g_boxarray.SetUpDrawBuffer();
		g_diskarray.SetUpDrawBuffer();

		/* �`�� */
		g_drawer.Draw();

		/* �I���t���Oon,off */
		if (g_boxarray.GetEndFlg() == true)
		{
			return 0;
		}

		/* ���͑҂��֐� */
		g_inputter.InputNumber();

	}

	return 0;
}