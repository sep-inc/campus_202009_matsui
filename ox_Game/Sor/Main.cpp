#include "Entity.h"
#include <stdlib.h>
#include <time.h>


int main()
{
	g_drawer.Init();  //!�`��N���X������

	g_bord.Init();    //!�ՃN���X������

	srand((unsigned int)time(NULL));   //����������

	while (true)
	{

		g_piece.StepChange();  //!��̃X�e�b�v����

		g_piece.SetUpDrawBuffer();  //!���`����W�ɕϊ�

		g_drawer.Draw();            //!�`��

		//!�I������
		if (g_bord.Search() == true)
		{
			break;
		}
		//!�L�[����(ESC)
		else if (g_inputter.InputEnd() == true)
		{
			break;
		}

		g_inputter.InputNumber();    //!���͔���
	}

	return 1;

}
